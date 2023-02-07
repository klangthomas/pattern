#include "singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton ( const std::string value )
    : stringValue ( value )
{
}

Singleton::~Singleton ( )
{
}

Singleton* Singleton::getInstance ( const std::string value )
{
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
