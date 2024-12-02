#include <iostream>
#include <string>
#include <memory>

class shape {
public:
    virtual void show() = 0;
};

class circle : public shape {
public:
    void show() override {
        std::cout << "Circle Block" << std::endl;
    }
};

class square : public shape {
public:
    void show() override {
        std::cout << "Square Block" << std::endl;
    }
};

class shape_factory {
public:
    std::unique_ptr<shape> create_shape(const std::string &type) {
        if (type == "Circle") return std::make_unique<circle>();
        if (type == "Square") return std::make_unique<square>();
        return {};
    }
};

int main(int, char const *[]) {
    unsigned cnt; std::cin >> cnt;
    shape_factory sf;
    while (cnt--) {
        std::string type; unsigned quantity;
        std::cin >> type >> quantity;
        for (unsigned ix = 0; ix != quantity; ++ix) {
            auto res = sf.create_shape(type);
            if (res) res->show();
        }
    }
    return 0;
}