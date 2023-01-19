#include "factory.h"
#include "productInterface.hpp"

int Creator::SomeOperation ( ) const
{
	Product* product = this->FactoryMethod ( );
	int result = product->doOperation ( );
	delete product;

	return result;
}

Product* ConcreteCreator1::FactoryMethod ( ) const
{
	return new ConcreteProduct1 ( );
}

Product* ConcreteCreator2::FactoryMethod ( ) const
{
	return new ConcreteProduct2 ( );
}