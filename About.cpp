#include "About.h"

using namespace std;

About::About ( QWidget * parent ) : QDialog ( parent )
{

	setupUi ( this );
	textEdit_2->setReadOnly(false);
    //connect( OK, SIGNAL( pressed() ), this, SLOT( close() ) );
};
