/*
 * HashingAlgorithm.h
 *
 *  Created on: Aug 16, 2017
 *      Author: root
 */

class HashingAlgorithm : public QDialog , public Ui::HashingAlgorithm
{

Q_OBJECT

public:
	HashingAlgorithm( QWidget *parent = 0 );
	~HashingAlgorithm();
};

