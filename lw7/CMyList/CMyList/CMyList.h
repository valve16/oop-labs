#ifndef CMYLIST_H
#define CMYLIST_H
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <utility>

template<typename T>
class CMyList 
{
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), prev(nullptr), next(nullptr) {}
    };
public:
    CMyList();
    CMyList(const CMyList& list);
    CMyList(CMyList&& list) noexcept;

    CMyList& operator=(const CMyList& list);
    CMyList& operator=(CMyList&& list) noexcept;

    ~CMyList() noexcept;

    void push_front(const T& value);
    void push_front(T&& value);

    void push_back(const T& value);
    void push_back(T&& value);

    size_t GetSize() const noexcept;

    class CIt
    {
    private:
        Node* m_current;
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit CIt(Node* node);

        reference operator*() const;
        pointer operator->();

        CIt& operator++();
        CIt operator++(int);

        CIt& operator--();
        CIt operator--(int);

        friend bool operator==(const CIt& a, const CIt& b) { return a.m_current == b.m_current; }
        friend bool operator!=(const CIt& a, const CIt& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    CIt begin();
    CIt end();

    class CRevIt
    {
    private:
        Node* m_current;
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit CRevIt(Node* node);

        reference operator*() const;
        pointer operator->();

        CRevIt& operator++();

        CRevIt operator++(int);

        CRevIt& operator--();

        CRevIt operator--(int);

        friend bool operator==(const CRevIt& a, const CRevIt& b) { return a.m_current == b.m_current; }
        friend bool operator!=(const CRevIt& a, const CRevIt& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    CRevIt rbegin();
    CRevIt rend();

    CIt insert(CIt pos, const T& value);
    CIt insert(CIt pos, T&& value);

    CIt erase(CIt pos);
    void Clear() noexcept;
private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;

    void CopyFrom(const CMyList& list);
};

#include "CMyList.cpp"

#endif 