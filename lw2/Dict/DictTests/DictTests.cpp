#define CATCH_CONFIG_MAIN
#include <DecodeString\StringProcess.h>
#include <vector>
#include <..\..\catch2\catch.hpp>
#include <iostream>


TEST_CASE("test_string")
{
	std::string test1 = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	CHECK(HtmlDecode(test1) == "Cat <says> \"Meow\". M&M's");

	CHECK(HtmlDecode("") == "");

	std::string testEntityLast = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;Ms&apos;";
	CHECK(HtmlDecode(testEntityLast) == "Cat <says> \"Meow\". M&Ms'");

	std::string testEntityFirst = "&lt;Cat says&gt; &quot;Meow&quot;. M&amp;Ms&apos;";
	CHECK(HtmlDecode(testEntityFirst) == "<Cat says> \"Meow\". M&Ms'");

	std::string testEntitybug = "&&lt;hello";
	CHECK(HtmlDecode(testEntitybug) == "&<hello");
}

