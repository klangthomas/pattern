#pragma once

#include <string>
#include <vector>

class BuilderProduct
{
public:
	std::vector< std::string > parts;

	std::string ListParts ( ) const
	{
		std::string msg = "";
		for ( auto p : parts)
		{
			msg += p;
		}

		return msg;
	}
};
