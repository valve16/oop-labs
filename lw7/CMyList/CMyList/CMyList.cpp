#include <iostream>
#include <stdexcept>
#include <iterator>
#include <utility>

template<typename T>
class CMyList 
{
public:
    CMyList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    CMyList(const CMyList& other) : m_head(nullptr), m_tail(nullptr), m_size(0) {
        CopyFrom(other);
    }

    CMyList(CMyList&& other) noexcept : m_head(other.m_head), m_tail(other.m_tail), m_size(other.m_size) {
        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_size = 0;
    }

    CMyList& operator=(const CMyList& other) {
        if (this != &other) {
            Clear();
            CopyFrom(other);
        }
        return *this;
    }

    CMyList& operator=(CMyList&& other) noexcept {
        if (this != &other) {
            Clear();
            m_head = other.m_head;
            m_tail = other.m_tail;
            m_size = other.m_size;
            other.m_head = nullptr;
            other.m_tail = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    ~CMyList() noexcept {
        Clear();
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = m_head;
        if (m_head) {
            m_head->prev = newNode;
        }
        else {
            m_tail = newNode;
        }
        m_head = newNode;
        ++m_size;
    }

    void push_front(T&& value) {
        Node* newNode = new Node(std::move(value));
        newNode->next = m_head;
        if (m_head) {
            m_head->prev = newNode;
        }
        else {
            m_tail = newNode;
        }
        m_head = newNode;
        ++m_size;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = m_tail;
        if (m_tail) {
            m_tail->next = newNode;
        }
        else {
            m_head = newNode;
        }
        m_tail = newNode;
        ++m_size;
    }

    void push_back(T&& value) {
        Node* newNode = new Node(std::move(value));
        newNode->prev = m_tail;
        if (m_tail) {
            m_tail->next = newNode;
        }
        else {
            m_head = newNode;
        }
        m_tail = newNode;
        ++m_size;
    }

    size_t getSize() const noexcept {
        return m_size;
    }

    template <bool IsConst>
    class IteratorBase
    {
        friend class IteratorBase<true>;
    public:
        using MyType = IteratorBase< IsConst>;
        using value_type = std::conditional_t<IsConst, const T, T>;
        using reference = value_type&;
        using pointer = value_type*;
        using difference_type = ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        IteratorBase() = default;
        IteratorBase(const IteratorBase<false>& other)
            : m_item(other.m_item)
        {
        }

        reference& operator*() const
        {
            return *m_item;
        }

        MyType& operator+=(difference_type offset)
        {
            m_item += offset;
            return *this;
        }

        MyType operator+(difference_type offset) const
        {
            MyType self(m_item);
            return self += offset;
        }

        friend MyType operator+(difference_type offset, const MyType& it)
        {
            return it + offset;
        }

    public:
        IteratorBase(T* item)
            : m_item(item)
        {
        }

    protected:
        T* m_item = nullptr;
    };
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), prev(nullptr), next(nullptr) {}
    };



    void Clear() noexcept 
    {
        while (m_head) 
        {
            Node* tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
        m_tail = nullptr;
        m_size = 0;
    }

    void CopyFrom(const CMyList& other)
    {
        for (Node* cur = other.m_head; cur != nullptr; cur = cur->next) 
        {
            push_back(cur->data);
        }
    }
private: 
    T* m_head = nullptr;;
    T* m_tail = nullptr;;
    size_t m_size;
};