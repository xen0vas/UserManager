/*
 * HashEncode.cpp
 *
 *  Created on: Aug 16, 2017
 *      Author: root
 */
/**
*
* The function below creates a random 64bit encoded code
*/

#include "HashEncode.h"


HashEncode::HashEncode()
{

}

HashEncode::~HashEncode()
{}

void HashEncode::into64 ( char *s, long int v, int n ) const
{
	static unsigned char itoa64[] =  "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 0 ... 63 => ascii - 64
	while ( --n >= 0 )
	{
		//64 bit integer into string conversion
		*s++ = itoa64[v&0x3f];
		v >>= 6;  // right shifting 6 bits
	}
}

