// link: https://kamacoder.com/problempage.php?pid=1074

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

template <typename T>
class singleton {
public:
    singleton(const singleton &) = delete;
    singleton &operator=(const singleton &) = delete;

    static T &get_instance() {
        static T instance;
        return instance;
    }
private:
    singleton() = default;
};

class cart {
public:
    using item_type = std::pair<std::string, unsigned>;

public:
    void add(const std::string &name, unsigned count) {
        if (const auto pos = std::find_if(items.begin(), items.end(),
            [&](const item_type &el) { return el.first == name; });
            pos != items.end()) {
                pos->second += count;
        } else {
            items.push_back({ name, count });
        }
    }

public:
    friend std::ostream &operator<<(std::ostream &os, const cart &c) {
        std::ostringstream oss;
        for (auto iter = c.items.begin(); iter != c.items.end(); ++iter) {
            oss << iter->first << " " << iter->second;
            if (next(iter) != c.items.end()) oss << std::endl;
        }
        os << oss.str();
        return os;
    }

private:
    std::vector<item_type> items;
};

int main(int, char const *[]) {
    auto &g_cart = singleton<cart>::get_instance();
    std::string line, name; unsigned quantity;
    while (getline(std::cin, line)) {
        std::stringstream converter { line };
        converter >> name >> quantity;
        g_cart.add(name, quantity);
    }
    std::cout << g_cart << std::endl;
    return 0;
}
