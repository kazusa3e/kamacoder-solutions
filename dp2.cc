#include <iostream>
#include <string>
#include <memory>

class Shape {
public:
    virtual void build() = 0;
};

class Circle : public Shape {
public:
    void build() override {
        std::cout << "Circle Block" << std::endl;
    }
};

class Square : public Shape {
public:
    void build() override {
        std::cout << "Square Block" << std::endl;
    }
};

class ShapeFactory {
public:
    virtual std::unique_ptr<Shape> createShape() = 0;
};

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<Circle>();
    }
};

class SquareFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<Square>();
    }
};

int main(int, char const *[]) {
    int n; std::cin >> n;
    std::string name; unsigned quantity;
    CircleFactory cf;
    SquareFactory sf;
    while (n--) {
        std::cin >> name >> quantity;
        for (unsigned ix = 0; ix != quantity; ++ix) {
            std::unique_ptr<Shape> val;
            if (name == "Circle") {
                val = cf.createShape();
            } else if (name == "Square") {
                val = sf.createShape();
            }
            val->build();
        }
    }
    return 0;
}