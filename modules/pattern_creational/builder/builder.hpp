#pragma once

/**
 * It sense to use the builder pattern only when your project is quite complex and require extensive configuration.
 * Unlike other creational patterns, different builders can produce unrelated products. In other words,
 * results of various builders may not always follow the same interface.
 */

#include "builderProduct.hpp"

class Builder
{
public:
	virtual ~Builder ( )
	{
	}

	virtual void Reset ( ) = 0;
	virtual Builder* ProcedurePartA ( ) = 0;
	virtual Builder* ProcedurePartB ( ) = 0;
	virtual Builder* ProcedurePartC ( ) = 0;

	/**
	 * Note that this class doesn't know anything about the product to be implemented.
	 */
};

class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1 ( )
	{
	}

	virtual ~ConcreteBuilder1 ( )
	{
		delete product;
	}

	virtual void Reset ( )
	{
		this->product = new BuilderProduct ( );
	}

	Builder* ProcedurePartA ( )
	{
		this->product->parts.push_back ( "PartA1" );
		return this;
	}

	Builder* ProcedurePartB ( )
	{
		this->product->parts.push_back ( "PartB1" );
		return this;
	}

	Builder* ProcedurePartC ( )
	{
		this->product->parts.push_back ( "PartC1" );
		return this;
	}

	/**
	 * Concrete builders are suppose to provide their own method for retrieving results.
	 * Hence, in a statically typed programming language as C++ we don't declare the GetProduct method
	 * in the base class.
	 */
	BuilderProduct* GetProduct ( )
	{
		BuilderProduct* result = this->product;
		this->Reset ( );
		return result;
	}

private:
	BuilderProduct* product;
};