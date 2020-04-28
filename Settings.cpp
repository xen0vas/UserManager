#include "MainWindow.h"
using namespace std;

/**
 * Αρχικοποίηση των components 
 */
Settings::Settings ( QWidget * parent ) : QDialog ( parent )
{

	setupUi ( this );
	QValidator *validator = new QIntValidator ( 1, 65535, this );//to validator pernei orisma mono int apo 1-65536 kai dhlwnei oti dexetai mono mono kapoia timh apo ayto to eyros
	minGidEdit->setValidator ( validator );//ta editboxes pernoun ton validator wste na mhn mpainei text alla mono int apo 1-65536 sto pedio tou edit
	minUidEdit->setValidator ( validator );

	
	connect ( warnCheckBox, SIGNAL ( clicked() ), this, SLOT ( sendMail() ) );
	connect ( okSetBtn, SIGNAL ( clicked() ), this, SLOT ( applySettings() ) );
	connect ( okSetBtn, SIGNAL ( clicked() ), this, SLOT ( close() ) );
		
initialSettings();
}

/**
 * Destructor κλάσης
 */
Settings::~Settings()
{}
/**
 * Αρχικοποίηση των components της φόρμας ρυθμίσεων και αποθήκευση των ρυθμίσεων για χρήση τους στην applySettings(..) αργότερα
   Η συνάρτηση διαβάζει τις ρυθμίσεις μέσω της getconf() στο usermanager.conf, παίρνοτας όλες τις ρυθμίσεις αρχικοποιώντας ανάλογα τα
  components της φόρμας. 
 */
void Settings::initialSettings()
{
//edw pairnoume tis arxikes ry8miseis thn stigmh pou anougetai h settings kai tis apo8hkeyoume stis metavlhtes wste na elegxoume otan kleisei to para8yro twn ry8misewn poies exoun alaxtei
//gia to mail den xreiazetai na elegxoume an einai checked h oxi giati analoga me poio ap ta 2 8a epilexei o xrhsths enhmerwnetai kai to conf kai to checkbox mesa sthn sendMail
//oi metavlhtes einai dhlwmene sto .h
minUIDprop=this->getconf ( "MINIMUM_GID" ).c_str();
minGIDprop=this->getconf ( "MINIMUM_UID" ).c_str();
//dinoume sta checkbox kai editbox tis ry8miseis tou conf
std::string warn;
	warn=this->getconf ( "WARN_USER" );
	if ( warn=="yes" )
		warnCheckBox->setChecked ( true );
	else
		warnCheckBox->setChecked ( false );

	minGidEdit->setText ( getconf ( "MINIMUM_GID" ).c_str() );
	minUidEdit->setText ( getconf ( "MINIMUM_UID" ).c_str() );


	languageCombo->addItem("Greek");
	languageCombo->addItem("English");
	languageCombo->setItemIcon(0,QIcon("/usr/share/apps/UserManager/pics/greek.jpeg"));
	languageCombo->setItemIcon(1,QIcon("/usr/share/apps/UserManager/pics/uk.jpeg"));
	if(getconf("LANGUAGE")=="English")
	languageCombo->setCurrentIndex(1);
	else
	languageCombo->setCurrentIndex(0);
}
/**
 * Η συνάρτηση διαβάζει μια ρύθμιση από το usermanager.conf
 παιρνάμε σαν όρισμα τον τίτλο της ρύθμισης που θέλουμε και μας επιστρέφει το string της ρύθμισης
 π.χ η κλήση getconf("LANGUAGE") θα μας επιστρέψει ένα string το οποίο θα είναι ή "GREEK" ή "ENGLISH" 
 */
std::string Settings::getconf ( std::string setting )
{
	string line;
	size_t found=' ';
	size_t pos=' ';

	fstream conf ( "/usr/share/apps/UserManager/other/usermanager.conf",ios::in );
	conf.seekg ( 0 );//metaferei ton deikth sthn arxh tou arxeiou.xreiazetai an den exei ginei swsto close tou arxeiou apo prohgoumenh anazhthsh
	if ( !conf.is_open() )
		return "";
	while ( getline ( conf,line ) )
		if ( ( found = line.find ( setting,0 ) ) != string::npos ) //vre8hke h ry8mish
		{
			pos=line.find ( "=",0 );  //psaxnei th 8esh pou yparxei to = pou diaxwrizei ton titlo ths ru8mishs ap thn ry8mish
			line.erase ( 0,pos+1 ); //svhnei apo thn arxh mexri kai to = (to = einai sto pos+1) kai sthn line menei h telikh ry8mish pou 8eloume
			break;
		}

	conf.close();
	return line;

}
/**
 * Η συνάρτηση αλλάζει μια ρύθμιση στο usermanager.conf.παίρνοντας τον τίτλο της ρύθμισης προς αλλαγή και την τιμή της ρύθμισης.
   Αν θέλουμε να αλλάξουμε την γλώσσα θα καλέσουμε setconf("LANGUAGE","ENGLISH")
 */
void Settings::setConf ( QString title, QString setting )
{
//allazei mia ry8mish sto conf.txt.px an 8eloume na allaxoume to MINIMUM_UID=1000 se MINIMUM_UID=2000 pername thn setconf("MINIMUM_UID","2000")
char *cmd;
QString command="sed -i '/"+ title +"/s/=.*/="+setting+"/g' /usr/share/apps/UserManager/other/usermanager.conf";
cmd=command.toLatin1().data();
system ( cmd );

}
/**
 * Ενέργεια αποστολής mail σε χρήστες των οποίων ο κωδικός είναι προς λήξη.
  Δημιουργεί αν δεν υπάρχει ένα αρχείο cron στον φάκελο /var/spool/cron/crontabs για τον root τον οποίο περιέχει εντολή ώστε να τρέχει το
  script κελύφους exp.sh.Το συγκεκριμένο script διαβάζει το αρχείο /etc/shadow και ψάχνει λογαριασμούς χρηστών οι οποίοι λήγουν μέσα στις
  επόμενες 7 μέρες.Αν βρεθεί χρήστης το script τον ενημερώνει στέλνοντάς του mail μέσω του συστήματος. Ο daemon crond του κάθε συστήματος ψάχνει ανά κάποιο χρονικό διάστημα (2-4 ώρες) τον φάκελο crontabs για τις προγραμματισμένες εργασίες χρηστών, οπότε υπάρχει μια μικρή καθυστέρηση μέχρι να δει την κάθε προγραμματισένη εργασία.
  Η γραμμή "echo 0x1A | echo '01 * * * * sh /usr/share/apps/UserManager/other/exp.sh' | crontab - -u root" περιλαμβάνει 3 ενέργειες.
 Πρώτα η "crontab - -u root" δημιουργεί ένα αρχείο με το όνομα root μέσα στο φάκελο /var/spool/cron/crontabs/
 Με την εντολή "echo '* 01 * * * sh /usr/share/apps/UserManager/other/exp.sh'" εισάγεται η γραμμή στο αρχείο η οποία ουστιαστικά σημαίνει
 ότι το σύστημα θα πρέπει να τρέχει την παραπάνω εντολή κάθε πρώτη ώρα της μέρας
 Με την εντολή "echo 0x1A" δηλώνουμε στο κέλυφος ότι έχουμε τελειώσει την εγγραφή στο αρχείο root.Το 0x1A ισοδυναμεί με Ctrl+D.
 Ετσι καταφέρνουμε να τρέχει το script exp.sh μία φορά τη μέρα ανεξάρτητα από το ποιος χρήστης είναι logged in στο σύστημα,γιατί το
 cron ενεργεί ακόμα και αν ο χρήστης root δεν έχει μπει στο σύστημα.
Το mail προειδοποίησης που λαμβάνει ο χρήστης έχει την παρακάτω μορφή:

*************************************************************************************
fts@Debian:~$ mail

"/var/mail/fts": 1 message 1 new

>N   1 root               Τετ Οκτ 22  15/486   Password Expiration

& 1

Subject: Password Expiration

To: <fts@Debian>

From: root <root@debian>

Date: Wed, 22 Oct 2008 14:45:08 +0300

Your password on Debian will be expired in 1 days

&
**************************************************************************************

 */

void Settings::sendMail ( )
{
	std::string command="exp.sh";//ayto to text psaxnoume an yparxei
	string line;
	bool done=false;
	size_t found=' ';
	ifstream file("/var/spool/cron/crontabs/root",ios::out);
	if (!file)
{
	system("echo 0x1A | echo '01 * * * * sh /usr/share/apps/UserManager/other/exp.sh' | crontab - -u root");//0x1A=EOF/CTRL+D
	  file.close();
}

else
{
	fstream file ( "/var/spool/cron/crontabs/root",ios::in|ios::out );
	file.seekg ( 0 );
	while ( getline ( file,line ) )
	{
		if ( ( found = line.find ( command,0 ) ) != string::npos )
		{
			done=true;
			system ( "sed -i '/exp.sh/d' /var/spool/cron/crontabs/root" );//svisimo grammhs h opoia periexei to exp.sh ()
			setConf("WARN_USER","no");//enhmerwsh tou conf
			break;
		}
	}
	file.close();
	if ( !done )
	{
		system("echo '01 * * * * sh /usr/share/apps/UserManager/other/exp.sh' >> /var/spool/cron/crontabs/root");
		setConf("WARN_USER","yes");//enhmerwsh tou conf
	}


}
}
/**
 *Αποθηκεύει τις νέες ρυθμίσεις που θα επιλέξει ο διαχειριστής στο usermanager.conf
  ελέγχει αν οι ρυθμίσεις που εισήχθησαν στην φόρμα είναι ίδιες με αυτές του αρχείου.Άν δεν είναι τις αλλάζει μέσα στο usermanager.conf μέσω της συνάρτησης setconf(..)
 */
void Settings::applySettings()
{
//edw molis path8ei to ok ths formas ginetai o elegxos an exei alaxtei kamia ry8mish kai analoga enhmerwnoume to conf. 
if (minUIDprop!=minUidEdit->text())
setConf("MINIMUM_UID",minUidEdit->text());
if (minGIDprop!=minGidEdit->text())
setConf("MINIMUM_GID",minGidEdit->text());
QString ax1,ax2;
ax1=languageCombo->currentText();
ax2=getconf("LANGUAGE").c_str();
if (languageCombo->currentText().toStdString()!=getconf("LANGUAGE"))//an to conf symfwnei me to text ap to combo sthn forma
{
setConf("LANGUAGE",languageCombo->currentText());
QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "Language will change after program restarts" ) );
}
}
