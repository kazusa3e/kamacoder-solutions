// WARN: pontential bugs exists:
// 1. check the std::size_t less than zero
// 2. circular reference (maybe?)

#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class linked_list;

template <typename T>
std::ostream &operator<<(std::ostream &os, const linked_list<T> &lst);

template <typename T>
class linked_list {
public:
    linked_list() : impl_(new impl) {}
    ~linked_list() {}

    linked_list(const linked_list &) = delete;
    linked_list &operator=(const linked_list &) = delete;

    linked_list(linked_list &&) = default;
    linked_list &operator=(linked_list &&) = default;

    friend std::ostream &operator<< <>(std::ostream &os, const linked_list<T> &lst);

    std::size_t size() const;
    void insert(std::size_t pos, T val);
    bool empty() const;
    T &get(std::size_t pos) const;
    void remove(std::size_t pos);
    void reverse();

public:
    template <typename InIter>
    static linked_list<T> build(InIter begin, InIter end);

private:
    class impl;

private:
    std::unique_ptr<impl> impl_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const linked_list<T> &lst) {
    lst.impl_->print(os);
    return os;
}

template <typename T>
std::size_t linked_list<T>::size() const {
    return impl_->size();
}

template <typename T>
void linked_list<T>::insert(std::size_t pos, T val) {
    impl_->insert(pos, val);
}

template <typename T>
bool linked_list<T>::empty() const {
    return impl_->size() == 0;
}

template <typename T>
T &linked_list<T>::get(std::size_t pos) const {
    return impl_->get(pos);
}

template <typename T>
void linked_list<T>::remove(std::size_t pos) {
    return impl_->remove(pos);
}

template <typename T>
void linked_list<T>::reverse() {
    impl_->reverse();
}

template <typename T>
template <typename InIter>
linked_list<T> linked_list<T>::build(InIter begin, InIter end) {
    linked_list<T> ret;
    ret.impl_->build(begin, end);
    return ret;
}

template <typename T>
class linked_list<T>::impl {
public:
    impl() {}
    ~impl() {}

    inline std::size_t size() const { return sz; }
    void print(std::ostream &os) const;
    void insert(std::size_t pos, T val);
    T &get(std::size_t pos) const;
    void remove(std::size_t pos);
    void reverse();

    template <typename InIter>
    void build(InIter begin, InIter end);

public:
    struct node {
        T val;
        std::shared_ptr<node> next;
    };

private:
    std::shared_ptr<node> sentinal{new node};
    std::size_t sz{0};
};

template <typename T>
void linked_list<T>::impl::print(std::ostream &os) const {
    if (sz == 0) {
        os << "list is empty";
        return;
    }
    std::weak_ptr<node> iter = sentinal->next;
    while (!iter.expired()) {
        auto s = iter.lock();
        if (s->next) {
            os << s->val << " ";
        } else {
            os << s->val;
        }
        iter = s->next;
    }
}

template <typename T>
void linked_list<T>::impl::insert(std::size_t pos, T val) {
    if (pos > sz) throw std::out_of_range{"position out of range"};
    auto iter = sentinal;
    while (pos-- != 0) iter = iter->next;
    iter->next = std::shared_ptr<node>{new node{val, iter->next}};
    sz += 1;
}

template <typename T>
T &linked_list<T>::impl::get(std::size_t pos) const {
    if (pos < 0 || pos >= sz) throw std::out_of_range{"position out of range"};
    std::shared_ptr<node> iter = sentinal->next;
    while (pos-- != 0) iter = iter->next;
    return iter->val;
}

template <typename T>
void linked_list<T>::impl::remove(std::size_t pos) {
    if (pos < 0 || pos >= sz) throw std::out_of_range{"position out of range"};
    auto iter = sentinal;
    while (pos-- != 0) iter = iter->next;
    iter->next = iter->next->next;
    sz -= 1;
}

template <typename T>
void linked_list<T>::impl::reverse() {
    if (sz == 0 || sz == 1) return;
    auto prev = sentinal->next, next = sentinal->next->next;
    prev->next = nullptr;
    while (next) {
        auto t = next->next;
        next->next = prev;
        prev = next; next = t;
    }
    sentinal->next = prev;
}

template <typename T>
template <typename InIter>
void linked_list<T>::impl::build(InIter begin, InIter end) {
    auto iter = sentinal;
    while (begin != end) {
        iter->next = std::shared_ptr<node>(new node {*begin});
        iter = iter->next;
        sz += 1;
        ++begin;
    }
}

int main(int, char const *[]) {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            std::cout << "list is empty" << std::endl;
            continue;
        }
        std::vector<int> vec;
        while (n-- != 0) {
            int val; std::cin >> val;
            vec.push_back(val);
        }
        auto lst = linked_list<int>::build(vec.begin(), vec.end());
        std::cout << lst << std::endl;
        lst.reverse();
        std::cout << lst << std::endl;
    }
    return 0;
}