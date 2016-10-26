#ifndef EDITPROPERTIES_H
#define EDITPROPERTIES_H
#include "ui_EditProperties.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <pwd.h>
#include <errno.h>
#include <sys/stat.h>
#include "userproperties.h"
#include "shadow.h"
#include "myLibb.h" 

/**
 * Σε αυτήν την φόρμα εμφανίζονται όλες οι πληροφορίες του χρήστη που έχει επιλεχθεί για επεξεργασία. Από αυτήν ξεκινάνε όλες οι ενέργειες επεξεργασίας που μπορούν να γίνουν σε ένα λογαριασμό,ανάμεσα τους η επεξεργασία ονόματος και προσωπικών στοιχείων του χρήστη,ενεργοποίηση/απενεργοποίηση του λογαριασμού,εισαγωγή/διαγραφή του χρήστη από ομάδες,αλλαγή κύριας ομάδας του χρήστη,ορισμός κωδικών,και δυνατότητες για την διάρκεια που θα είναι ενεργός ο λογαριασμός.
 */
class EditProperties : public QDialog , public Ui::EditProperties
{
Q_OBJECT
public:
 	void setOldUsername ( QString oldUsername );
	QString getOldUsername();
	EditProperties( QWidget *parent = 0 );
	~EditProperties();
	void comboShell();
	void acct_shadow(struct spwd spw);
	int set_password(QString nam);
	int set_shad_expire(QString months,int days_value,int years_value);

	
private:
	
	void set_account(bool set);
	QString oldUsername_;

private slots:

	void set_Pass_info(); 
	void ok_to_edit_Button();
	void changeMembers(const QModelIndex &index );
	void fillEasyList();
	void easyCheckboxClicked();
	void easyAddGroups(const QModelIndex &index);
	void setPrimaryGroup();
	void disablechk();
	void browse();
};
#endif
