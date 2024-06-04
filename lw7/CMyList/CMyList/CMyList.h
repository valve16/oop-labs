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
    CMyList() 
        : m_head(nullptr)
        , m_tail(nullptr)
        , m_size(0)
    {
    };

    CMyList(const CMyList& list)
        : m_head(nullptr)
        , m_tail(nullptr)
        , m_size(0)
    {
        try {
            CopyFrom(list);
        }
        catch (...) {
            Clear();
            throw;
        }
    };

    CMyList(CMyList&& list)  noexcept
        : m_head(list.m_head)
        , m_tail(list.m_tail)
        , m_size(list.m_size)
    {
        list.m_head = nullptr;
        list.m_tail = nullptr;
        list.m_size = 0;

    };

    CMyList& operator=(const CMyList& list)
    {
        if (this != &list) {
            CMyList temp(list);
            std::swap(m_head, temp.m_head);
            std::swap(m_tail, temp.m_tail);
            std::swap(m_size, temp.m_size);
        }
        return *this;
    };
    CMyList& operator=(CMyList&& list) noexcept
    {
        if (this != &list)
        {
            Clear();
            m_head = list.m_head;
            m_tail = list.m_tail;
            m_size = list.m_size;
            list.m_head = nullptr;
            list.m_tail = nullptr;
            list.m_size = 0;
        }
        return *this;
    };

    ~CMyList() noexcept
    {
        Clear();
    };

    void push_front(const T& value) 
    {
        Node* newNode = new Node(value);
        newNode->next = m_head;
        if (m_head)
        {
            m_head->prev = newNode;
        }
        else
        {
            m_tail = newNode;
        }
        m_head = newNode;
        ++m_size;
    };

    void push_back(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->prev = m_tail;
        if (m_tail)
        {
            m_tail->next = newNode;
        }
        else
        {
            m_head = newNode;
        }
        m_tail = newNode;
        ++m_size;
    };

    size_t GetSize() const noexcept
    {
        return m_size;
    };

    class CIt
    {
    private:
        Node* m_current;
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit CIt(Node* node)
            : m_current(node)
        {
        };

        reference operator*() const
        {
            return m_current->data;
        };

        pointer operator->()
        {
            return &(m_current->data);
        };

        CIt& operator++()
        {
            //проверитть можно ли сделать
            m_current = m_current->next;

            return *this;
        };
        CIt operator++(int)
        {
            CIt tmp = *this;
            m_current = m_current->next;
            return tmp;
        };

        CIt& operator--()
        {
            m_current = m_current->prev;
            return *this;
        };

        CIt operator--(int)
        {
            CIt tmp = *this;
            m_current = m_current->prev;
            return tmp;
        };

        friend bool operator==(const CIt& a, const CIt& b) { return a.m_current == b.m_current; } //изменить
        friend bool operator!=(const CIt& a, const CIt& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    CIt begin()
    {
        return CIt(m_head);
    };
    CIt end()
    {// стра
        return CIt(nullptr);
    };

    class CRevIt
    {
    private:
        Node* m_current;
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit CRevIt(Node* node)
            : m_current(node)
        {
        };

        reference operator*() const
        {
            return m_current->data;
        };

        pointer operator->()
        {
            return &(m_current->data);
        };

        CRevIt& operator++()
        {
            m_current = m_current->prev;
            return *this;
        };

        CRevIt operator++(int)
        {
            CRevIt tmp = *this;
            m_current = m_current->prev;
            return tmp;
        };

        CRevIt& operator--()
        {
            m_current = m_current->next;
            return *this;
        };

        CRevIt operator--(int)
        {
            CRevIt tmp = *this;
            m_current = m_current->next;
            return tmp;
        };

        friend bool operator==(const CRevIt& a, const CRevIt& b) { return a.m_current == b.m_current; }
        friend bool operator!=(const CRevIt& a, const CRevIt& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    CRevIt rbegin()
    {
        return CRevIt(m_tail);
    };

    CRevIt rend()
    {
        return CRevIt(nullptr);
    };

    CIt insert(CIt pos, const T& value)
    {
        Node* posNode = pos.getNode();
        Node* newNode = new Node(value);

        if (!posNode)
        {
            push_back(value);
            return CIt(m_tail);
        }

        newNode->next = posNode;
        newNode->prev = posNode->prev;

        if (posNode->prev)
        {
            posNode->prev->next = newNode;
        }
        else
        {
            m_head = newNode;
        }

        posNode->prev = newNode;

        ++m_size;
        return CIt(newNode);
    };

    CIt insert(CIt pos, T&& value)
    {
        Node* posNode = pos.getNode();
        Node* newNode = new Node(std::move(value));
        newNode->next = posNode;
        if (posNode)
        {
            newNode->prev = posNode->prev;
            if (posNode->prev)
            {
                posNode->prev->next = newNode;
            }
            else
            {
                m_head = newNode;
            }
            posNode->prev = newNode;
        }
        else
        {
            newNode->prev = m_tail;
            if (m_tail)
            {
                m_tail->next = newNode;
            }
            else
            {
                m_head = newNode;
            }
            m_tail = newNode;
        }
        ++m_size;
        return CIt(newNode);
    };

    CIt erase(CIt pos)
    {
        Node* posNode = pos.getNode();
        if (!posNode)
        {
            throw std::out_of_range("Invalid iterator position"); // переименовать
        }

        if (posNode->prev)
        {
            posNode->prev->next = posNode->next;
        }
        else
        {
            m_head = posNode->next;
        }

        if (posNode->next)
        {
            posNode->next->prev = posNode->prev;
        }
        else
        {
            m_tail = posNode->prev;
        }

        CIt next(posNode->next);
        delete posNode;
        --m_size;
        return next;
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
    };
private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;

    void CopyFrom(const CMyList& list)
    {
        for (Node* cur = list.m_head; cur != nullptr; cur = cur->next)
        {
            push_back(cur->data);
        }
    };
};
