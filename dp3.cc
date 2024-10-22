#include <iostream>
#include <memory>

class Chair {
public:
    virtual void build() = 0;
};

class ModernChair : public Chair {
public:
    void build() override {
        std::cout << "modern chair" << std::endl;
    }
};

class ClassicalChair : public Chair {
public:
    void build() override {
        std::cout << "classical chair" << std::endl;
    }
};

class Sofa {
public:
    virtual void build() = 0;
};

class ModernSofa : public Sofa {
public:
    void build() override {
        std::cout << "modern sofa" << std::endl;
    }
};

class ClassicalSofa : public Sofa {
public:
    void build() override {
        std::cout << "classical sofa" << std::endl;
    }
};

class Factory {
public:
    virtual std::unique_ptr<Chair> createChair() = 0;
    virtual std::unique_ptr<Sofa> createSofa() = 0;
};

class ModernFactory : public Factory {
public:
    std::unique_ptr<Chair> createChair() override {
        return std::make_unique<ModernChair>();
    }
    std::unique_ptr<Sofa> createSofa() override {
        return std::make_unique<ModernSofa>();
    }
};

class ClassicalFactory : public Factory {
public:
    std::unique_ptr<Chair> createChair() override {
        return std::make_unique<ClassicalChair>();
    }
    std::unique_ptr<Sofa> createSofa() override {
        return std::make_unique<ClassicalSofa>();
    }
};

int main(int, char const *[]) {
    int n; std::cin >> n;
    std::string type;
    ModernFactory mf;
    ClassicalFactory cf;
    while (n--) {
        std::cin >> type;
        if (type == "modern") {
            (mf.createChair())->build();
            (mf.createSofa())->build();
        } else if (type == "classical") {
            (cf.createChair())->build();
            (cf.createSofa())->build();
        }
    }
    return 0;
}