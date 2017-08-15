#include <string>
#include <QString>
#include "hashingalgorithm.h"

class sha256 : public hashingalgorithm
{
public:
	char* makeSalt(int length);
	char* encryptpass(QString passwd);
	void into64 ( char *s, long int v, int n );
    static const int saltLength = 8;
    void Free(){ delete this; }
    static hashingalgorithm* Create();
};
