#pragma once

/// @brief The common interface that all other products have to implement
class Product 
{
public:
	virtual ~Product ( ){ };
	virtual int doOperation ( ) const = 0;
};


class ConcreteProduct1 : public Product
{
public:
	int doOperation ( ) const override
	{
		return 1;
	}
};

class ConcreteProduct2 : public Product
{
public:
	int doOperation ( ) const override
	{
		return 2;
	}
};