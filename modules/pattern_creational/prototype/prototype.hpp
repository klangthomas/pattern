#pragma once

//! @brief Create a enumerated list of all basic prototype functions.
enum Type
{
	Prototype1 = 1,
	Prototype2
};

//! @brief Defines the interface for the rest of the application
class Prototype
{
public:
	Prototype ( )
	{
	}

	Prototype ( int prototypeID )
	    : prototype_id ( prototypeID )
	{
	}

	virtual ~Prototype ( ){ };

	//! @brief 
	virtual Prototype* Clone ( ) const = 0;

	//! @brief interface to alter internal structures, in this case a simple int
	virtual void Method ( int prototype_field )
	{
		this->prototype_field = prototype_field;
	}

	//! @brief 
	int getID ( )
	{
		return prototype_id;
	}

	int getField ( )
	{
		return prototype_field;
	}

protected:
	int prototype_id;
	int prototype_field;
};

class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1 ( int prototypeID, int prototypeField )
	    : Prototype ( prototypeID )
	    , concretePrototype_field1 ( prototypeField )
	{
	}

	Prototype* Clone ( ) const override
	{
		return new ConcretePrototype1 ( *this );
	}

private:
	int concretePrototype_field1;
};

class ConcretePrototype2 : public Prototype
{
public:
	ConcretePrototype2 ( int prototypeID, int prototypeField )
	    : Prototype ( prototypeID )
	    , concretePrototype_field2 ( prototypeField )
	{
	}

	Prototype* Clone ( ) const override
	{
		return new ConcretePrototype2 ( *this );
	}

private:
	int concretePrototype_field2;
};

class PrototypeFactory
{
public:
	PrototypeFactory ( )
	{
		prototypes_[Type::Prototype1] = new ConcretePrototype1 ( Type::Prototype1, 50 );
		prototypes_[Type::Prototype2] = new ConcretePrototype2 ( Type::Prototype2, 60 );
	}

	~PrototypeFactory ( )
	{
		delete prototypes_[Type::Prototype1];
		delete prototypes_[Type::Prototype2];
	}

	Prototype* CreatePrototype ( Type type )
	{
		return prototypes_[type]->Clone ( );
	}

private:
	std::unordered_map< Type, Prototype*, std::hash< int > > prototypes_;
};
