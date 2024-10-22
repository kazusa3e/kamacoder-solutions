// link: https://kamacoder.com/problempage.php?pid=1074

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class cart {
public:
    static cart &get_instance();

public:
    cart(const cart &) = delete;
    cart &operator=(const cart &) = delete;
    cart &operator<<(cart &&) = delete;

public:
    void add(const std::string &item, unsigned quantity) {
        auto pos = std::find_if(items.begin(), items.end(), [&item](const std::pair<std::string, unsigned> &v) -> bool {
            return v.first == item;
        });
        if (pos == items.end()) {
            items.push_back(std::make_pair(item, quantity));
        } else {
            pos->second += quantity;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const cart &c);

private:
    cart() = default;

private:
    std::vector<std::pair<std::string, unsigned>> items;
};

cart &cart::get_instance() {
    static cart instance;
    return instance;
}

std::ostream &operator<<(std::ostream &os, const cart &c) {
    for (auto iter = c.items.begin(); iter != c.items.end(); ++iter) {
        os << iter->first << " " << iter->second;
        if (next(iter) != c.items.end()) os << std::endl;
    }
    return os;
}

int main(int, char const *[]) {
    std::string item; unsigned quantity;
    auto &c = cart::get_instance();
    while (std::cin >> item >> quantity) {
        c.add(item, quantity);
    }
    std::cout << c << std::endl;
    return 0;
}
