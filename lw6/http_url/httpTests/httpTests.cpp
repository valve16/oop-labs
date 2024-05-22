#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../http_url/CHttpUrl.h"
#include <iostream>

SCENARIO("Construct urls")
{
	WHEN("valid url string")
	{
		CHttpUrl url("https://example.com:8080/path");
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/path");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 8080);
			REQUIRE(url.GetProtocol() == Protocol::HTTPS);
			REQUIRE(url.GetURL() == "https://example.com:8080/path");

		}
	}

	WHEN("valid url string without port")
	{
		CHttpUrl url("https://example.com/path");
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/path");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 443);
			REQUIRE(url.GetProtocol() == Protocol::HTTPS);
			REQUIRE(url.GetURL() == "https://example.com/path");

		}
	}


	WHEN("valid url construct without port")
	{
		CHttpUrl url("example.com", "path", Protocol::HTTP);
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/path");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 80);
			REQUIRE(url.GetProtocol() == Protocol::HTTP);
			REQUIRE(url.GetURL() == "http://example.com/path");

		}
	}
	WHEN("valid url construct with / in path")
	{
		CHttpUrl url("example.com", "/path", Protocol::HTTP, 1448);
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/path");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 1448);
			REQUIRE(url.GetProtocol() == Protocol::HTTP);
			REQUIRE(url.GetURL() == "http://example.com:1448/path");

		}
	}
	WHEN("valid url construct")
	{
		CHttpUrl url("example.com", "path", Protocol::HTTP, 1448);
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/path");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 1448);
			REQUIRE(url.GetProtocol() == Protocol::HTTP);
			REQUIRE(url.GetURL() == "http://example.com:1448/path");

		}
	}
	WHEN("valid url construct without path")
	{
		CHttpUrl url("example.com", "", Protocol::HTTP, 1448);
		THEN("valid url")
		{
			REQUIRE(url.GetDocument() == "/");
			REQUIRE(url.GetDomain() == "example.com");
			REQUIRE(url.GetPort() == 1448);
			REQUIRE(url.GetProtocol() == Protocol::HTTP);
			REQUIRE(url.GetURL() == "http://example.com:1448/");

		}
	}
}

SCENARIO("check errors and invalid status")
{
	WHEN("invalid ports")
	{
		SECTION("Valid URL with invalid port throws exception", "[CHttpUrl]")
		{
			REQUIRE_THROWS_AS(CHttpUrl("https://example.com:80800/path"), CUrlParsingError);

		}
		SECTION("Valid URL with invalid port throws exception", "[CHttpUrl]")
		{
			REQUIRE_THROWS_AS(CHttpUrl("https://example.com:0/path"), CUrlParsingError);

		}
		SECTION("string in port")
		{
			REQUIRE_THROWS_AS(CHttpUrl("https://example.com:stsa/path"), CUrlParsingError);

		}
	}
	WHEN("invalid protocols")
	{
		SECTION("Valid URL with invalid port throws exception", "[CHttpUrl]")
		{
			REQUIRE_THROWS_AS(CHttpUrl("httpss://example.com:8080/path"), CUrlParsingError);

		}
	}
	WHEN("path/document name has space")
	{
		SECTION("throws exception")
		{
			REQUIRE_THROWS_AS(CHttpUrl("https://example.com:8080/pat h"), CUrlParsingError);

		}
	}
	WHEN("domain name has space")
	{
		SECTION("throws exception")
		{
			REQUIRE_THROWS_AS(CHttpUrl("https://exam ple.com:8080/path"), CUrlParsingError);

		}
	}
	WHEN("domain name empty")
	{
		SECTION("throws exception")
		{
			REQUIRE_THROWS_AS(CHttpUrl("", "", Protocol::HTTP, 1448), CUrlParsingError);
		}
	}
	WHEN("invalid url")
	{
		SECTION("exception")
		{
			REQUIRE_THROWS_AS(CHttpUrl("stringdf"), CUrlParsingError);

		}
	}
}