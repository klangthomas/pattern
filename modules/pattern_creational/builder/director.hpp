#pragma once

#include "builder.hpp"

/**
 * The director is only responsible for executing building steps in a particular sequence.
 * It is helpful when producing products according to a specific order or configuration.
 * Strictly speaking: the Director class is optional, since the client can control builders directly.
 */
class Director
{
public:
	void setBuilder ( Builder* builder )
	{
		this->builder = builder;
		this->builder->Reset ( );
	}

	void buildMinimalProduct ( )
	{
		builder->ProcedurePartA ( );
	}

	void buildFullProduct ( )
	{
		builder->ProcedurePartA ( );
		builder->ProcedurePartB ( );
		builder->ProcedurePartC ( );
	}

private:
	Builder* builder;
};
