#include <iostream>
#include <string>
#include <memory>

class cloneable {
public:
    virtual std::unique_ptr<cloneable> clone() = 0;
};

class rectangle : public cloneable {
public:
    rectangle(const std::string &color, unsigned width, unsigned height)
        : color(color), width(width), height(height) {}
    
    rectangle(const rectangle &rhs) = delete;
    rectangle &operator=(const rectangle &rhs) = delete;

    std::unique_ptr<cloneable> clone() override {
        return std::make_unique<rectangle>(color, width, height);
    }

    friend std::ostream &operator<<(std::ostream &os, const rectangle &self) {
        os << "Color: " << self.color << ", Width: " << self.width << ", Height: " << self.height;
        return os;
    }

private:
    std::string color;
    unsigned width;
    unsigned height;
};

int main(int, char const *[]) {
    std::string type; unsigned width; unsigned height;
    std::cin >> type >> width >> height;
    rectangle prototype { type, width, height };
    unsigned cnt; std::cin >> cnt;
    while (cnt--) {
        auto cloned = prototype.clone();
        auto res = std::unique_ptr<rectangle>(dynamic_cast<rectangle *>(cloned.release()));
        std::cout << *res << std::endl;
    }
    return 0;
}