#include <iostream>

//使用你的名字替换YOUR_NAME
namespace LinZhouyi
{
    template <class T>
    // list存储的节点
    // 可以根据你的需要添加适当的成员函数与成员变量
    struct node
    {
        node<T> *prev_;
        node<T> *next_;
        T data_;
        //构造函数
        node(const T &data)
            : data_(data), prev_(nullptr), next_(nullptr)
        {
        }
        node()
            : prev_(nullptr), next_(nullptr)
        {
        }
        //析构函数
        ~node()
        {
        }
    };

    template <class T>
    //迭代器类,(类比指针)

    struct iterator
    {
        typedef node<T> node_;
        typedef iterator<T> iterator_;
        node_ * node_ptr_;
        iterator(node_ *node_ptr = nullptr)
            : node_ptr_(node_ptr){}
        ~iterator()
        {
        }
        //迭代到下一个节点
        //++it
        iterator_ &operator++()
        {
            node_ptr_ = node_ptr_->next_;
            return *this;
        }
        //迭代到前一个节点
        //--it
        iterator_ &operator--()
        {
            node_ptr_ = node_ptr_->prev_;
            return *this;
        }
        // it++
        iterator operator++(int)   //这个int参数只是一个占位符,表示后置自增，没有实际意思
        {
            iterator temp = *this;
            node_ptr_ = node_ptr_->next_;
            return temp;
        }
        // it--
        iterator operator--(int)
        {
            iterator temp = *this;
            node_ptr_ = node_ptr_->prev_;
            return temp;
        }
        //指向迭代器中被访问的成员值
        T &operator*()
        {
            return node_ptr_->data_;
        }

        //指向迭代器中被访问的成员指针
        T *operator->()
        {
            return &(node_ptr_->data_);
        }
        //重载==
        bool operator==(const iterator_ &t)
        {
            return node_ptr_ == t.node_ptr_;
        }
        //重载！=
        bool operator!=(const iterator_ &t)
        {
            return node_ptr_ != t.node_ptr_;
        }

        //**可以添加需要的成员变量与成员函数**
    };

    template <class T>
    class list
    {
    public:
        typedef node<T> node_;
        typedef iterator<T> Iterator;

    private:
        //可以添加你需要的成员变量
        node_ *head_; //头节点,哨兵（不存储有效数据）
        node_ *end_;
        size_t size_;

    public:
        //构造函数
        list()
        {
            head_ = new node<T>();
            end_ = head_;
            size_ =0;
        }
        //拷贝构造，要求实现深拷贝
        list(const list<T> &lt)
        :head_(new node<T>()),size_(0)
        {
            end_=head_;
            node_* h = lt.head_;
            for (int i=0;i<lt.size_;i++)
            {
                h = h->next_;
                push_back(h->data_);
            }
        }
        template <class inputIterator>
        //迭代器构造
        list(inputIterator begin, inputIterator end)
        :head_(new node<T>()),size_(0)
        {
            head_->next_= new node<T>();
            end_ = head_->next_;
            for (auto it=begin;it!=end;it++)
                push_back(*it);
        }

        ~list()
        {
            clear();
            delete head_;
        }
        //拷贝赋值
        list<T> &operator=(const list<T> &lt)
        {
            if (this != &lt)
            {
                list<T> temp(lt);
                std::swap(head_,temp.head_);
                std::swap(end_,temp.end_);
                std::swap(size_,temp.size_);
            }
            return *this;
        }
        //清空list中的数据
        void clear()
        {
            while (size_)
            {
                node_ *temp = head_;
                head_ = head_->next_;
                delete temp;
                --size_;
            }
        }
        //返回容器中存储的有效节点个数
        size_t size() const
        {
            return size_;
        }
        //判断是否为空
        bool empty() const
        {
            if (size_)
                return 0;
            return 1;
        }
        //尾插
        bool push_back(const T &data)
        {
            node_* newnode = new node<T>(data);
            end_->next_ = newnode;
            newnode->prev_ = end_;
            newnode->next_ = nullptr;
            end_ = newnode;

            ++size_;

            return 1;
        }
        //头插
        bool push_front(const T &data)
        {
            node_* newnode = new node<T>(data);
            newnode->prev_ = head_;
            newnode->next_ = head_->next_;
            head_->next_ = newnode;
            newnode->next_->prev_ = newnode;

            return 1;
        }
        //尾删
        bool pop_back()
        {
            if (size_ == 0){
                return 0;
            }
            end_->prev_->next_ = nullptr;
            node_* temp = end_;
            end_ = end_->prev_;
            delete temp;

            --size_;

            return 1;
        }
        //头删
        bool pop_front()
        {
            return erase(this->begin());
        }
        //默认新数据添加到pos迭代器的后面,根据back的方向决定插入在pos的前面还是后面
        bool insert(Iterator pos, const T &data, bool back = true)
        {
            node_ *node = pos.node_ptr_ ;
            node_ *newnode = new node_(data);
            if (back)
            {
                if (node == end_)
                {
                    push_back(data);
                    return 1;
                }
                newnode->prev_ = node;
                newnode->next_ = node->next_;
                node->next_ = newnode;
                newnode->next_->prev_ = newnode;
            }
            else
            {
                if (node == head_)
                {
                    push_front(data);
                    return 1;
                }
                newnode->prev_ = node->prev_;
                newnode->next_ = node;
                node->prev_ = newnode;
                newnode->prev_->next_ = node;
            }
            ++size_;
            return 1;
        }
        //删除pos位置的元素
        bool erase(Iterator pos)
        {
            node_ *node = pos.node_ptr_;
            if (node == end_)
            {
                pop_back();
                return 1;
            }

            node->prev_->next_ = node->next_;
            if (!node->next_)
                node->next_->prev_ = node->prev_;
            delete node;
            size_--;
            return 1;
        }

        //获得list第一个有效节点的迭代器
        Iterator begin() const
        {
            return iterator<T>(head_->next_);
        }

        //获得list最后一个节点的下一个位置
        Iterator end() const
        {
            return iterator<T>(end_->next_);
        }
        //查找data对应的迭代器
        Iterator find(const T &data) const
        {
            for (auto t=head_->next_ ; t!=end_;t=t->next_)
                if (t->data_ == data)
                    return iterator<T>(t);
            return nullptr;
        }
        //获得第一个有效节点元素值
        T front() const
        {
            return head_->next_->data_;
        }
        //获得最后一个有效节点元素值
        T back() const
        {
            return end_->data_;
        }

    private:
        //可以添加你需要的成员函数
    };
};
