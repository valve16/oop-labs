#include "CHttpUrl.h"
#include <regex>
#include <sstream>
#include <iostream>
#include <map>

const unsigned short MAX_PORT_VALUE = 65535;
const unsigned short MIN_PORT_VALUE = 1;
const std::string INVALID_PORT = "Invalid Port. Port must be between 1 and 65535";
const std::string DOMAIN_EMPTY = "Domain name is empty";
const std::string INVALID_DOMAIN = "Invalid domain, has space";
const std::string INVALID_DOCUMENT = "Invalid document name";
const std::string INVALID_URL = "Invalid URL format";
const std::string INVALID_PROTOCOL = "Invalid protocol";
const std::regex URL_REGEX(R"((http|https):\/\/([^\/:]+)(:(\d{1,5}))?(\/.*)?)");
const std::map<Protocol, std::string> PROTOCOL_STR_MAP = 
{
        {Protocol::HTTP, "http"},
        {Protocol::HTTPS, "https"}
};
const std::map<std::string, Protocol> STR_PROTOCOL_MAP =
{
        {"http", Protocol::HTTP},
        {"https", Protocol::HTTPS}
};
const std::map<Protocol, unsigned short> PROTOCOL_PORT_MAP =
{
        {Protocol::HTTP, 80},
        {Protocol::HTTPS, 443}
};


CHttpUrl::CHttpUrl(const std::string& url)
{
    std::string strUrl = url; 
    std::transform(strUrl.begin(), strUrl.end(), strUrl.begin(),
        [](unsigned char c) { return std::tolower(c); });
    ParseURL(strUrl);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol)
    : m_domain(domain)
    , m_document(document)
    , m_protocol(protocol)
    , m_port(GetDefaultPort(protocol))
{
    ValidateDomain(domain);
    m_document = ValidateDocument(document);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
    : m_domain(domain)
    , m_document(document)
    , m_protocol(protocol)
{
    ValidateDomain(domain);
    m_document = ValidateDocument(document);
    if (port < MIN_PORT_VALUE || port > MAX_PORT_VALUE)
    {
        throw std::invalid_argument(INVALID_PORT);
    }
    m_port = port;
}

std::string CHttpUrl::GetURL() const
{
    std::ostringstream url;
    url << ProtocolToString(m_protocol) << "://" << m_domain;
    if (m_port != GetDefaultPort(m_protocol))
    {
        url << ":" << m_port;
    }
    url << m_document;
    return url.str();
}

std::string CHttpUrl::GetDomain() const
{
    return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
    return m_port;
}

void CHttpUrl::ValidateDomain(const std::string& domain)
{
    if (domain.empty() )
    {
        throw CUrlParsingError(DOMAIN_EMPTY);
    }
    if (domain.find(' ') != std::string::npos)
    {
        throw CUrlParsingError(INVALID_DOMAIN);
    }
}

std::string CHttpUrl::ValidateDocument(const std::string& document)
{
    if (document.find(' ') != std::string::npos)
    {
        throw CUrlParsingError(INVALID_DOCUMENT);
    }
    if (document.empty())
    {
        return "/";
    }
    else if (document[0] != '/')
    {
        return "/" + document;
    }
    else
    {
        return document;
    }
}

void CHttpUrl::ParseURL(const std::string& url)
{
    std::smatch match;

    if (!std::regex_match(url, match, URL_REGEX))
    {
        throw CUrlParsingError(INVALID_URL);
    }
    m_protocol = StringToProtocol(match[1]);

    m_domain = match[2];
    m_port = ParsePort(match[4]);
    ValidateDomain(m_domain);
    m_document = ValidateDocument(match[5]);
}

unsigned short CHttpUrl::ParsePort(const std::string& port) const
{
    if (port.empty())
    {
        return GetDefaultPort(m_protocol);
    }

    int portVal;
    try
    {
        portVal = std::stoi(port);
    }
    catch (...)
    {
        throw CUrlParsingError(INVALID_PORT);
    }
    if (portVal > MAX_PORT_VALUE || portVal < MIN_PORT_VALUE)
    {
        throw CUrlParsingError(INVALID_PORT);
    }

    return portVal;
}

unsigned short CHttpUrl::GetDefaultPort(Protocol protocol) const
{
    return PROTOCOL_PORT_MAP.at(protocol);
}

std::string CHttpUrl::ProtocolToString(Protocol protocol) const
{
    return PROTOCOL_STR_MAP.at(protocol);
}

Protocol CHttpUrl::StringToProtocol(const std::string& protocol) const
{
    if (STR_PROTOCOL_MAP.find(protocol) != STR_PROTOCOL_MAP.end())
    {
        return STR_PROTOCOL_MAP.at(protocol);
    }
    else
    {
        throw CUrlParsingError(INVALID_PROTOCOL + ": " + protocol);
    }
}