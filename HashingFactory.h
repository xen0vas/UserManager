
#include <string>
#include <map>
#include "hashingalgorithm.h"

using namespace std ;

class HashingFactory
{
private:
	HashingFactory();
	HashingFactory(const HashingFactory& ){}
	HashingFactory &operator=(const HashingFactory&){ return *this;}
	typedef map<string, CreateHash> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~HashingFactory() {m_FactoryMap.clear();}
	static HashingFactory *Get()
	{
		static HashingFactory instance;
		return &instance;
	}
	void Register(const std::string &HashingFactory, CreateHash pfnCreate);
	hashingalgorithm *CreateAlgorithm(const string &hashName);
};

