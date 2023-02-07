#include "singleton.h"

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::m;

Singleton::Singleton ( const std::string value )
    : stringValue ( value )
{
}

Singleton::~Singleton ( )
{
}

Singleton* Singleton::getInstance ( const std::string value )
{
	std::lock_guard< std::mutex > lock ( m );
	if ( instance == nullptr ) instance = new Singleton ( value );
	return instance;
}

std::string Singleton::getValue ( )
{
	return stringValue;
}

void Singleton::deleteInstanceForUnitTests ( )
{
	delete instance;
	instance = nullptr;
}
