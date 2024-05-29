#pragma once
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
    CMyList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    CMyList(const CMyList& list) : m_head(nullptr), m_tail(nullptr), m_size(0) 
    {
        CopyFrom(list);
    }

    CMyList(CMyList&& list) noexcept : m_head(list.m_head), m_tail(list.m_tail), m_size(list.m_size) 
    {
        list.m_head = nullptr;
        list.m_tail = nullptr;
        list.m_size = 0;
    }

    CMyList& operator=(const CMyList& list) 
    {
        if (this != &list) 
        {
            Clear();
            CopyFrom(list);
        }
        return *this;
    }

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
    }

    ~CMyList() noexcept 
    {
        Clear();
    }

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
    }

    void push_front(T&& value) 
    {
        Node* newNode = new Node(std::move(value));
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
    }

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
    }

    void push_back(T&& value) 
    {
        Node* newNode = new Node(std::move(value));
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
    }

    size_t getSize() const noexcept 
    {
        return m_size;
    }

    class iterator 
    {
    private:
        Node* m_current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit iterator(Node* node) : m_current(node) {}

        reference operator*() const { return m_current->data; }
        pointer operator->() { return &(m_current->data); }

        iterator& operator++() 
        {
            m_current = m_current->next;
            return *this;
        }

        iterator operator++(int) 
        {
            iterator tmp = *this;
            m_current = m_current->next;
            return tmp;
        }

        iterator& operator--() 
        {
            m_current = m_current->prev;
            return *this;
        }

        iterator operator--(int) 
        {
            iterator tmp = *this;
            m_current = m_current->prev;
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) { return a.m_current == b.m_current; }
        friend bool operator!=(const iterator& a, const iterator& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    iterator begin() { return iterator(m_head); }
    iterator end() { return iterator(m_tail->next); }

    class reverse_iterator 
    {
    private:
        Node* m_current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        explicit reverse_iterator(Node* node) : m_current(node) {}

        reference operator*() const { return m_current->data; }
        pointer operator->() { return &(m_current->data); }

        reverse_iterator& operator++() 
        {
            m_current = m_current->prev;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            m_current = m_current->prev;
            return tmp;
        }

        reverse_iterator& operator--() 
        {
            m_current = m_current->next;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            m_current = m_current->next;
            return tmp;
        }

        friend bool operator==(const reverse_iterator& a, const reverse_iterator& b) { return a.m_current == b.m_current; }
        friend bool operator!=(const reverse_iterator& a, const reverse_iterator& b) { return a.m_current != b.m_current; }
        Node* getNode() const { return m_current; }
    };

    reverse_iterator rbegin() { return reverse_iterator(m_tail); }
    reverse_iterator rend() { return reverse_iterator(m_tail->next); }

    iterator insert(iterator pos, const T& value) 
    {
        Node* posNode = pos.getNode();
        Node* newNode = new Node(value);

        if (!posNode) 
        {
            push_back(value);
            return iterator(m_tail);
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
        return iterator(newNode);
    }

    iterator insert(iterator pos, T&& value) 
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
        return iterator(newNode);
    }

    iterator erase(iterator pos) 
    {
        Node* posNode = pos.getNode();
        if (!posNode) 
        {
            throw std::out_of_range("Invalid iterator position");
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

        iterator next(posNode->next);
        delete posNode;
        --m_size;
        return next;
    }
private:

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

    void CopyFrom(const CMyList& list) 
    {
        for (Node* cur = list.m_head; cur != nullptr; cur = cur->next) 
        {
            push_back(cur->data);
        }
    }
private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;
};
