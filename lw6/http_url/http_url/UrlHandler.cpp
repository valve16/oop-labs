#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "UrlHandler.h"
#include "CHttpUrl.h"

const std::string EXIT_COMMAND = "...";

void CUrlHandler::Handle(std::istream& in, std::ostream& out)
{
    std::string url;
    while (std::getline(in, url))
    {
        if (url == EXIT_COMMAND)
        {
            break;
        }
        try
        {
            CHttpUrl httpUrl(url);
            out << "URL: " << httpUrl.GetURL() << std::endl;
            out << "Domain: " << httpUrl.GetDomain() << std::endl;
            out << "Document: " << httpUrl.GetDocument() << std::endl;
            out << "Protocol: " << (httpUrl.GetProtocol() == Protocol::HTTP ? "http" : "https") << std::endl;
            out << "Port: " << httpUrl.GetPort() << std::endl;
        }
        catch (const CUrlParsingError& e)
        {
            out << "Error parsing URL: " << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            out << "Unexpected error: " << e.what() << std::endl;
        }
    }

}