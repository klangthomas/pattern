#pragma once
#include <string>
#include <mutex>


class Singleton
{
private:
	static std::mutex m;

protected:
	Singleton ( const std::string value );
	~Singleton ( );

	static Singleton* instance;

	std::string stringValue;


public:
    Singleton ( const Singleton& ) = delete;
    void operator= ( const Singleton& ) = delete;

	static Singleton* getInstance ( const std::string value );

	static void deleteInstanceForUnitTests ( );

	std::string getValue ( );
};