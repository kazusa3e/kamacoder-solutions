#include <iostream>
#include <memory>
#include <string>

class chair {
public:
    virtual void show() = 0;
};

class modern_chair : public chair {
public:
    void show() override {
        std::cout << "modern chair" << std::endl;
    }
};

class classical_chair : public chair {
public:
    void show() override {
        std::cout << "classical chair" << std::endl;
    }
};

class sofa {
public:
    virtual void show() = 0;
};

class modern_sofa : public sofa {
public:
    void show() override {
        std::cout << "modern sofa" << std::endl;
    }
};

class classical_sofa : public sofa {
public:
    void show() override {
        std::cout << "classical sofa" << std::endl;
    }
};

class factory {
public:
    virtual std::unique_ptr<chair> build_chair() = 0;
    virtual std::unique_ptr<sofa> build_sofa() = 0;
};

class modern_factory : public factory {
public:
    std::unique_ptr<chair> build_chair() override {
        return std::make_unique<modern_chair>();
    }
    std::unique_ptr<sofa> build_sofa() override {
        return std::make_unique<modern_sofa>();
    }
};

class classical_factory : public factory {
public:
    std::unique_ptr<chair> build_chair() override {
        return std::make_unique<classical_chair>();
    }
    std::unique_ptr<sofa> build_sofa() override {
        return std::make_unique<classical_sofa>();
    }
};

int main(int, char const *[]) {
    unsigned cnt; std::cin >> cnt;
    modern_factory mf; classical_factory cf;
    while (cnt--) {
        std::string type; std::cin >> type;
        if (type == "modern") {
            mf.build_chair()->show();
            mf.build_sofa()->show();
        } else if (type == "classical") {
            cf.build_chair()->show();
            cf.build_sofa()->show();
        }
    }
    return 0;
}