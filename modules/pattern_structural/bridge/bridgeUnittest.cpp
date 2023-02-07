#include <catch2/catch.hpp>
#include "bridge.h"

TEST_CASE ( "BaseBridgeA" )
{
	BridgeImplementation *a = new BridgeImplementationA ( "Foo" );
	BridgeAbstraction *b = new BridgeAbstraction ( a );

	REQUIRE ( b->operation ( ) == "Base: Foo" );

	delete b;
	delete a;
}

TEST_CASE ( "BaseBridgeB" )
{
	BridgeImplementation *a = new BridgeImplementationB ( 42 );
	BridgeAbstraction *b = new BridgeAbstraction ( a );

	REQUIRE ( b->operation ( ) == "Base: 42" );

	delete b;
	delete a;
}

TEST_CASE ( "ExtendedBridgeA" )
{
	BridgeImplementation *a = new BridgeImplementationA ( "Foo" );
	BridgeAbstraction *b = new BridgeAbstractionExtended ( a );

	REQUIRE ( b->operation ( ) == "Extended: Foo" );

	delete b;
	delete a;
}

TEST_CASE ( "ExtendedBridgeB" )
{
	BridgeImplementation *a = new BridgeImplementationB ( 42 );
	BridgeAbstraction *b = new BridgeAbstractionExtended ( a );

	REQUIRE ( b->operation ( ) == "Extended: 42" );

	delete b;
	delete a;
}
