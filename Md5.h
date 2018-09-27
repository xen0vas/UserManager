/*
 * Md5.h
 *
 *  Created on: Aug 16, 2017
 *      Author: root
 */

#ifndef MD5_H_
#define MD5_H_

#include <string>
#include <QString>
#include "HashEncode.h"
#include "IHashing.h"

class Md5 : public IHashing
{
public:
	static const int saltLength = 8;
	char* encryptpass(QString passwd) const;
    void Free();
    static IHashing* Create();
};



#endif /* MD5_H_ */
