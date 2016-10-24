#ifndef ABOUT_H
#define ABOUT_H
#include "ui_About.h"

class About : public QDialog, public Ui::About
{

Q_OBJECT

public:
	About( QWidget *parent = 0 );

};

#endif
