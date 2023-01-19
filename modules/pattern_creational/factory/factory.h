#pragma once

class Product;

class Creator
{
public:
	virtual ~Creator ( ){ };

	virtual Product* FactoryMethod ( ) const = 0;

	int SomeOperation ( ) const;
};


class ConcreteCreator1 : public Creator
{
public:
	Product* FactoryMethod ( ) const override;
};

class ConcreteCreator2 : public Creator
{
public:
	Product* FactoryMethod ( ) const override;
};