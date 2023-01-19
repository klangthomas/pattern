#include <catch2/catch.hpp>

#include "factory.h"
#include "productInterface.hpp"

int ClientCode(const Creator& creator)
{
	return creator.SomeOperation ( );
}

TEST_CASE ( "Create ConcreteProduct1" )
{
	auto creator = new ConcreteCreator1 ( );
	REQUIRE ( ClientCode ( *creator ) == 1 );
}

TEST_CASE ( "Create ConcreteProduct2" )
{
	auto creator = new ConcreteCreator2 ( );
	REQUIRE ( ClientCode ( *creator ) == 2 );
}