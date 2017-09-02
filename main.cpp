#include <QApplication>
#include <QtGui/QtGui>
#include "MainWindow.h"
#include <string>
#include <unistd.h>
#include <memory>

using namespace std;
/**
 *constructor της κλάσης/φόρμας.
  Αρχικά γίνεται ένας έλεγχος στον φάκελο /proc για να διαπιστωθεί αν το πρόγραμμα είναι ήδη ανοιχτό ώστε να βγάλει μύνημα ενημέρωσης.
  Την πρώτη φορά που ανοίγει δημιουργείται ένα αρχείο txt μέσα στον φάκελο tmp το οποίο περιέχει μόνο τον αριθμό της διεργασίας του User
  Manager 
  Αν ανοίξει και για 2η φορά το πρόγραμμα,θα υπάρχει μέσα στον ./proc ο αριθμός που διεργασίας που αποθηκεύτηκε πριν στο usermanager.lock
 στον /tmp.Αρα υποθέτουμε ότι το πρόγραμμα είναι ήδη ανοιχτό.

Στη συνέχεια εκτελούνται έλεγχοι για να διαπιστωθεί αν οι εγγραφές των /etc/passwd και /etc/shadow είναι σωστές.
Για να είναι σωστές θα πρέπει κάθε όνομα χρήστη του /etc/passwd να υπάρχει και στο /etc/shadow και το αντίστροφο.Αν υπάρχει λάθος ο 
διαχειριστής ενημερώνεται για τον χρήστη του οποίου οι εγγραφές έχουν πρόβλημα.
 */

int main(int argc, char ** argv)
{

//dhmiourgei to usermanagaer.lock mesa sto opoio yparxei mono o (pid) ari8mos diergasias tou usermanager.sthn 1h if psaxnei an yparxei fakelos mesa sto /proc o opoios na xei ton ari8mo ths diergasias.an yparxei to usermanager einai anoixto
//an den isxyei h 1h tote 8ewreitai oti to programma den einai anoixto kai paei sthn 2h if h opoia vazei mesa sto usermanager.lock to pid ths diergasias tou usermanager pou molis dhmiourgh8hke kalwntas thn getpid();

	QApplication app( argc, argv);
	
	struct spwd *sp; 
	struct passwd *pw; 
	

	QFile lockFile( QDir::tempPath() + "/usermanager.lock" );
	if ( lockFile.open( QIODevice::ReadOnly ) )
	{

		QTextStream lockStream( &lockFile );
		if ( QDir( "/proc/" + lockStream.readLine() ).exists() )
		{
			QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "UserManager is already running" ));

			exit(0);
		}

		lockFile.close();

	}
	if ( lockFile.open( QIODevice::WriteOnly | QIODevice::Truncate ) )
	{
		QTextStream lockStream( &lockFile );
		int pid = getpid();
		lockStream << pid << endl;
		lockFile.close();
	}

	setspent();
	while ( ( sp = getspent() ) )
	{
		pw=getpwnam ( sp->sp_namp );
		if ( pw==NULL )

			QMessageBox::critical ( 0,QObject::tr ( "User Manager" ),QObject::tr ( " Entry of user ' <i><b>%1</b></i> ' in /etc/shadow does not exist in /etc/passwd  " ).arg ( sp->sp_namp ) );
			
}
        // if the user is not root the application will not start
		char *user = (char *)calloc(128, sizeof(char));
		pw = getpwuid(getuid());
		user = pw->pw_name;
		if (strncmp(user , "root", strlen(user)) != 0)
		{
			QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "UserManager cannot run by non root users" ));
			if (user !=  nullptr) { free(user); user = nullptr;   }
			exit (0);
		}


	MainWindow win;
	win.show();
	
	
	free(user);
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
