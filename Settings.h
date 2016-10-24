#ifndef SETTINGS_H
#define SETTINGS_H
#include "ui_Settings.h"
#include <fstream>




	/*
	8a ftiaxoume ena arxeio usermanager.conf(to kana conf.txt dokimastika) to opoio 8a exei oles tis ry8miseis kai 8a einai ths morfhs
	WARN_USER:yes
	MINIMUM_UID:1000
	MINIMUN_GID:1000 kok.. mia seira gia ka8e ry8mish
	8a mpei mia synarthsh edw ston constructor pou 8a pairnei oles tis ry8miseis apo to arxeio ry8misewn kai analoga
	8a kanei arxikopoihsh ola ta checkbox/editboxes h otidhpote xreiazetai sthn forma ry8misewn
	h synarthsh pou 8a diavazei tis ry8miseis(h getconf("string")) mia mia 8a pernei san orisma ton titlo tis ry8mishs pou 8eloume na diavasoume kai 8a epistrefei oti yparxei meta to : tou titlou
	8a psaxnei px to text WARN_USER sto arxeio kai 8a vriskei poia einai h ry8mish tou ..ara ypoti8etai 8a epistrepsei yes h no h an dwsoume MINIMUM_GID 8a epistrepsei 1000 px.
	an YES to checkbox warnCheckbox sth forma 8a einai checked alliws unchecked
	*/




/**
  Κλάση αποθήκευσης βασικών ρυθμίσεων της εφαρμογής σε ένα αρχείο usermanager.conf .Το usermanager.conf έχει την μορφή;
  WARN_USER:yes
  MINIMUM_UID:1000
  MINIMUN_GID:1000 κοκ 
  και κάθε μια γραμμή αντιστοιχεί και σε μια διαφορετική ρύθμιση για το πρόγραμμα.Διατηρώντας αυτό το αρχείο σε έναν φάκελο μπορούμε να
  αποθηκεύσουμε ρυθμίσεις οι οποίες δεν θα σβήνονται κάθε φορά που κλείνει το πρόγραμμα. Μέσω των συναρτήσεων setConf(..) και getconf(..)
  αποθηκεύουμε μια ρύθμιση ή την διαβάζουμε αντίστοιχα.
 */
/**
 * Κλάση αποθήκευσης βασικών ρυθμίσεων της εφαρμογής σε ένα αρχείο usermanager.conf 
 */
class Settings : public QDialog , public Ui::Settings
{
		Q_OBJECT
	public:

		Settings ( QWidget *parent = 0 );
		~Settings();
		void setConf ( QString title, QString setting );
		std::string getconf ( std::string setting );


	private:
		QString minUIDprop,minGIDprop;
		void initialSettings();


	private slots:
		void sendMail();
		void applySettings();
	
};
#endif
