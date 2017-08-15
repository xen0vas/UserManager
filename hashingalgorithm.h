#ifndef HASHINGALGORITHM_H_
#define HASHINGALGORITHM_H_
//

#include <string>
#include <QString>

using namespace std;

class hashingalgorithm
{
public:
	virtual ~hashingalgorithm(){};
	virtual char* makeSalt(int length) = 0;
	virtual char* encryptpass(QString passwd) = 0;
	virtual void Free() = 0;
};

#endif /* HASHINGALGORITHM_H_ */

//create function pointer
typedef hashingalgorithm* (*CreateHash)(void);
