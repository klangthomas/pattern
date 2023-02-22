#include <catch2/catch.hpp>
#include "adapter.hpp"

TEST_CASE ( "SimpleAdapter" )
{
	AdapterClient *client = new AdapterClient;
	REQUIRE ( client->Request ( ) == "Client: the standard behavior" );
	
	AdapterThirdParty *thirdPartyClass = new AdapterThirdParty;
	Adapter *adapter = new Adapter ( thirdPartyClass );
	REQUIRE ( adapter->Request ( ) == "Adapter: (Translated) Special behavior of the Adaptee." );
}