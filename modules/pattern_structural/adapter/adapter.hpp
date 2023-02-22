#pragma once
#include <string>

class AdapterClient
{
public:
	virtual ~AdapterClient ( ) = default;

	virtual std::string Request ( ) const
	{
		return "Client: the standard behavior";
	}
};

class AdapterThirdParty
{
public:
	std::string SpecificRequest ( ) const
	{
		return ".eetpadA eht fo roivaheb laicepS";
	}
};

class Adapter : public AdapterClient
{
private:
	AdapterThirdParty *adaptee;

	public:
	Adapter ( AdapterThirdParty* a )
	    : adaptee ( a )
	{
	}

	std::string Request() const override
	{
		std::string to_reverse = this->adaptee->SpecificRequest ( );
		std::reverse ( to_reverse.begin ( ), to_reverse.end ( ) );
		return "Adapter: (Translated) " + to_reverse;
	}

};
