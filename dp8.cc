#include <iostream>
#include <memory>

class coffee {
public:
    virtual void brew() = 0;
};

class black_coffee : public coffee {
public:
    void brew() override {
        std::cout << "Brewing Black Coffee" << std::endl;
    }
};

class latte_coffee : public coffee {
public:
    void brew() override {
        std::cout << "Brewing Latte" << std::endl;
    }
};

class coffee_decorator : public coffee {
public:
    coffee_decorator() = delete;
    coffee_decorator(std::unique_ptr<coffee> coffee): m_coffee(std::move(coffee)) {}

    void brew() override {
        m_coffee->brew();
    }
private:
    std::unique_ptr<coffee> m_coffee;
};

class milk_decorator : public coffee_decorator {
public:
    milk_decorator() = delete;
    milk_decorator(std::unique_ptr<coffee> coffee): coffee_decorator(std::move(coffee)) {}

    void brew() override {
        coffee_decorator::brew();
        std::cout << "Adding Milk" << std::endl;
    }
};

class sugar_decorator : public coffee_decorator {
public:
    sugar_decorator() = delete;
    sugar_decorator(std::unique_ptr<coffee> coffee): coffee_decorator(std::move(coffee)) {}

    void brew() override {
        coffee_decorator::brew();
        std::cout << "Adding Sugar" << std::endl;
    }
};

int main(int, char const *[]) {
    unsigned coffee_type, integrate_type;
    while (std::cin >> coffee_type >> integrate_type) {
        std::unique_ptr<coffee> coff;
        if (coffee_type == 1) coff = std::make_unique<black_coffee>();
        else if (coffee_type == 2) coff = std::make_unique<latte_coffee>();

        if (integrate_type == 1) {
            coff = std::make_unique<milk_decorator>(std::move(coff));
        } else if (integrate_type == 2) {
            coff = std::make_unique<sugar_decorator>(std::move(coff));
        }

        coff->brew();
    }
    return 0;
}