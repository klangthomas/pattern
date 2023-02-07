#pragma once

#include <string>

class BridgeImplementation
{
public:
	virtual ~BridgeImplementation ( )
	{
	}

	virtual std::string operationImplementation ( ) const = 0;
};

/// <summary>
/// This could be a concrete implementation on platform A
/// </summary>
class BridgeImplementationA : public BridgeImplementation
{
public:
	BridgeImplementationA ( std::string name )
	    : strName ( name )
	{
	}

	virtual std::string operationImplementation ( ) const override
	{
		return strName;
	}

protected:
	std::string strName;
};

/// <summary>
/// This could be a concrete implementation on platform B
/// </summary>
class BridgeImplementationB : public BridgeImplementation
{
public:
	BridgeImplementationB ( int value )
	    : intValue ( value )
	{
	}

	virtual std::string operationImplementation ( ) const override
	{
		return std::to_string ( intValue );
	}

protected:
	int intValue;
};

/// <summary>
/// This one will define the standard procedures to handle with the BridgeImplementation interface.
/// </summary>
class BridgeAbstraction
{
public:
	BridgeAbstraction ( BridgeImplementation* implementation )
	    : impl ( implementation )
	{
	}

	virtual ~BridgeAbstraction ( )
	{
	}

	virtual std::string operation ( ) const
	{
		return std::string ( "Base: " ) + impl->operationImplementation ( );
	}

protected:
	BridgeImplementation* impl;
};

/// <summary>
/// This one ist just another extension or adaption of the BridgeImplementation interface. 
/// </summary>
class BridgeAbstractionExtended : public BridgeAbstraction
{
public:
	BridgeAbstractionExtended ( BridgeImplementation* implementation )
	    : BridgeAbstraction ( implementation )
	{
	}

	virtual ~BridgeAbstractionExtended ( )
	{
	}

	virtual std::string operation ( ) const override
	{
		return std::string ( "Extended: " ) + impl->operationImplementation ( );
	}
};
