#include <catch2/catch.hpp>

#include "builder.hpp"
#include "director.hpp"

TEST_CASE ( "Directly Minimal" )
{
	ConcreteBuilder1* builder = new ConcreteBuilder1 ( );
	builder->Reset ( );
	builder->ProcedurePartA ( );

	BuilderProduct* product = builder->GetProduct ( );
	REQUIRE ( product->ListParts ( ) == "PartA1" );
}

TEST_CASE ( "Directly Full" )
{
	ConcreteBuilder1* builder = new ConcreteBuilder1 ( );
	builder->Reset ( );
	builder->ProcedurePartA ( )->ProcedurePartB ( )->ProcedurePartC ( );
	BuilderProduct* product = builder->GetProduct ( );
	REQUIRE ( product->ListParts ( ) == "PartA1PartB1PartC1" );
}

TEST_CASE ( "Director Minimal" )
{
	ConcreteBuilder1* builder = new ConcreteBuilder1 ( );
	Director* director = new Director ( );
	director->setBuilder ( builder );
	director->buildMinimalProduct ( );
	BuilderProduct* product = builder->GetProduct ( );
	REQUIRE ( product->ListParts ( ) == "PartA1" );
}

TEST_CASE ( "Director Full" )
{
	ConcreteBuilder1* builder = new ConcreteBuilder1 ( );
	Director* director = new Director ( );
	director->setBuilder ( builder );
	director->buildFullProduct ( );
	BuilderProduct* product = builder->GetProduct ( );
	REQUIRE ( product->ListParts ( ) == "PartA1PartB1PartC1" );
}
