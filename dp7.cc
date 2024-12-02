#include <iostream>
#include <memory>

class house_purchase {
public:
    virtual void purchase(unsigned area) = 0;
};

class real_purchase : public house_purchase {
public:
    void purchase(unsigned area) override {
        std::cout << "YES" << std::endl;
    }
};

class agent_purchase : public house_purchase {
public:
    agent_purchase() = delete;
    agent_purchase(std::shared_ptr<house_purchase> handler)
        : handler(handler) {}

    void purchase(unsigned area) override {
        if (area >= 100) handler->purchase(area);
        else std::cout << "NO" << std::endl;
    }

private:
    std::shared_ptr<house_purchase> handler;
};

int main(int, char const *[]) {
    auto rp = std::make_shared<real_purchase>();
    agent_purchase ap { rp };
    unsigned cnt; std::cin >> cnt;
    while (cnt--) {
        unsigned area; std::cin >> area;
        ap.purchase(area);
    }
    return 0;
}