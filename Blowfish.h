#include <string>
#include <QString>
#include "HashEncode.h"
#include "IHashing.h"

class Blowfish : public IHashing
{
public:
	static const int saltLength = 2;
	char* encryptpass(QString passwd) const;
    void Free();
    static IHashing* Create();
};

