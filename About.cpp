#include "About.h"

using namespace std;

About::About ( QWidget * parent ) : QDialog ( parent )
{

	setupUi ( this );
	connect( OK, SIGNAL( pressed() ), this, SLOT( close() ) );
};
