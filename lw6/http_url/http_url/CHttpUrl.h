#pragma once
#include <string>
#include "CUrlParsingError.h"


enum class Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    // ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
    // ����������� ���������� CUrlParsingError, ���������� ��������� �������� ������
    CHttpUrl(std::string const& url);

    /* �������������� URL �� ������ ���������� ����������.
        ��� �������������� ������� ���������� ����������� ����������
        std::invalid_argument
        ���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
    */
    CHttpUrl(
        std::string const& domain,
        std::string const& document,
        Protocol protocol =  Protocol::HTTP);

    /* �������������� URL �� ������ ���������� ����������.
        ��� �������������� ������� ���������� ����������� ����������
        std::invalid_argument
        ���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
    */
    CHttpUrl(
        std::string const& domain,
        std::string const& document,
        Protocol protocol,
        unsigned short port);

    // ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
    // ���������� ��������� (80 ��� http � 443 ��� https) � ��� ������
    // �� ������ ����������
    std::string GetURL()const;

    // ���������� �������� ���
    std::string GetDomain()const;

    /*
        ���������� ��� ���������. �������:
            /
            /index.html
            /images/photo.jpg
    */
    std::string GetDocument()const;

    // ���������� ��� ���������
    Protocol GetProtocol()const;

    // ���������� ����� �����
    unsigned short GetPort()const;
private:
    std::string m_domain;
    std::string m_document;
    Protocol m_protocol;
    unsigned short m_port;

    void ValidateDomain(const std::string& domain);
    std::string ValidateDocument(const std::string& document);
    void ParseURL(const std::string& url);
    unsigned short GetDefaultPort(Protocol protocol) const;
    unsigned short ParsePort(const std::string& port) const;
    std::string ProtocolToString(Protocol protocol) const;
    Protocol StringToProtocol(const std::string& protocol) const;
};