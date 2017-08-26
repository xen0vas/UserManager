#ifndef GROUPPROPERTIES_H
#define GRPOUPROPERTIES_H
#include "ui_GroupProperties.h"
#include <stdlib.h>
#include <stdint.h>
#include "grp.h"

/**
 * Στην GroupProperties ανήκει η φόρμα στην οποία προβάλλονται τα χαρακτηριστικά των ομάδων. Από αυτήν μπορούμε να προσθέσουμε/αφαιρέσουμε μέλη στις ομάδες, να αλλάξουμε το όνομα τους,να τις επεξεργαστούμε, ή να κανουμε προσθήκη μιας νέας ομάδας στο σύστημα.Πολλές από τις συναρτήσεις της κλάσης αυτής συνδέονται με συναρτήσεις της κλάσης Groups οι οποίες συνεργάζονται προκειμένου να υλοποιηθούν ορισμένες ενέργειε.
 */
class GroupProperties : public QDialog , public Ui::GroupProperties


{
		Q_OBJECT
	public:
		GroupProperties ( QWidget *parent = 0 );
		~GroupProperties();
		int groupStudy(gid_t uid_n);
		virtual void setOldGroupName ( QString oldGroupName );
		virtual QString getOldGroupName();
		
	private :

		QString oldGroupName_;

	private slots:
		void addMembers();
		void removeMembers();
		void checkGroupname ( const QString &text );
		void checkGID ( const QString &text );
		bool renameGroup();
		int addNewGroup();

};


#endif

