#include "ui_HashingAlgorithm.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>
#include "myLibb.h"

using namespace std;

class HashingAlgorithm : public QDialog , public Ui::HashingAlgorithm
{

Q_OBJECT

public:
	HashingAlgorithm( QWidget *parent = 0 );
	~HashingAlgorithm();
	int setPassword(QString name);


private:
	void storePassShadow(QString name, QString passhash);

private slots:
	void setHashingAlgorithm();
	bool getSha256IsChecked();
	bool getSha512IsChecked();
	bool getMd5IsChecked();



};

