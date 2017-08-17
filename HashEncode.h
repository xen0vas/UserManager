/*
 * HashEncode.h
 *
 *  Created on: Aug 16, 2017
 *      Author: root
 */

#ifndef HASHENCODE_H_
#define HASHENCODE_H_

class HashEncode
{

public :
	HashEncode();
	~HashEncode();
	void into64 ( char *s, long int v, int n ) const;
};


#endif /* HASHENCODE_H_ */
