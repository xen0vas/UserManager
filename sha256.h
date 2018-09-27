#include <string>
#include <QString>
#include "HashEncode.h"
#include "IHashing.h"

class sha256 : public IHashing
{
public:
	static const int saltLength = 8;
	char* encryptpass(QString passwd) const;
    void Free();
    static IHashing* Create();
};
