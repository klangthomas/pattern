#include <catch2/catch.hpp>

#include "prototype.hpp"

TEST_CASE ( "Create Prototype1" )
{
	int methodField = GENERATE ( take ( 10, random ( 1, 100 ) ) );
	int prototypeID = GENERATE ( take ( 10, random ( ( int ) Type::Prototype1, ( int ) Type::Prototype2 ) ) );

	PrototypeFactory* prototype_factory = new PrototypeFactory ( );
	Prototype* prototype = prototype_factory->CreatePrototype ( ( Type ) prototypeID );

	prototype->Method ( methodField );

	REQUIRE ( prototype->getField ( ) == methodField );
	REQUIRE ( prototype->getID ( ) == prototypeID );
}
