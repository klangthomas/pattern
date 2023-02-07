#include <catch2/catch.hpp>
#include <chrono>
#include <thread>

#include "singleton.h"

void getSingleton ( std::string singletonName, std::string& returnName )
{
	std::this_thread::sleep_for ( std::chrono::milliseconds ( 1000 ) );
	Singleton* s = Singleton::getInstance ( singletonName );
	returnName = s->getValue ( );
};

TEST_CASE ( "Singleton singlethreading" )
{
	std::string t1Name = "notSet";
	std::string t2Name = "notSet";
	getSingleton ( "FOO", t1Name );
	getSingleton ( "BAR", t2Name );

	REQUIRE ( t1Name == "FOO" );
	REQUIRE ( t2Name == "FOO" );

	Singleton::deleteInstanceForUnitTests ( );
}

TEST_CASE ( "Singleton multithreading" )
{
	std::string t1Name = "notSet";
	std::string t2Name = "notSet";

	std::thread t1 ( [&t1Name] ( ) mutable { getSingleton ( "FOO", t1Name ); } );
	std::thread t2 ( [&t2Name] ( ) mutable { getSingleton ( "BAR", t2Name ); } );
	t1.join ( );
	t2.join ( );

	// Can't determine which thread comes first. Therefore we have to check names, which should be identical
	REQUIRE ( t1Name == t2Name );

	Singleton::deleteInstanceForUnitTests ( );
}
