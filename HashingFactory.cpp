#include "HashingFactory.h"
#include "sha256.h"
#include "sha512.h"
#include "Md5.h"
#include "Blowfish.h"


HashingFactory::HashingFactory()
{
	Register("SHA-256", &sha256::Create);
	Register("SHA-512", &sha512::Create);
	Register("MD5", &Md5::Create);
	Register("blowfish", &Blowfish::Create);
}

/*
 * Register hashing algorithms.
 */
void HashingFactory::Register(const std::string &HashingFactory, CreateHash pfnCreate)
{
 m_FactoryMap[HashingFactory] = pfnCreate;
}

/*
 * this function is used in order to search for the requested hashing algorithm.
 */
IHashing *HashingFactory::CreateAlgorithm(const string &hashName)
{

	FactoryMap::iterator it = m_FactoryMap.find(hashName);
	if ( it != m_FactoryMap.end())
			return it->second();
	return NULL;
}


