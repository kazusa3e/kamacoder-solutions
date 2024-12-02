#include <iostream>
#include <string>
#include <memory>

class cycle {
public:
    void set_frame(const std::string &frame) {
        this->frame = frame;
    }

    void set_tyres(const std::string &tyres) {
        this->tyres = tyres;
    }

public:
    friend std::ostream &operator<<(std::ostream &os, const cycle &c) {
        os << c.frame << " " << c.tyres;
        return os;
    }

private:
    std::string frame;
    std::string tyres;
};

class cycle_builder {
public:
    virtual void build_frame() = 0;
    virtual void build_tyres() = 0;
    virtual std::unique_ptr<cycle> get_result() = 0;
};

class mountain_cycle_builder : public cycle_builder {
public:
    void build_frame() override {
        c->set_frame("Aluminum Frame");
    }

    void build_tyres() override {
        c->set_tyres("Knobby Tires");
    }

    std::unique_ptr<cycle> get_result() override {
        auto res = std::make_unique<cycle>();
        std::swap(res, c);
        return res;
    }

private:
    std::unique_ptr<cycle> c { new cycle };
};

class road_cycle_builder : public cycle_builder {
public:
    void build_frame() override {
        c->set_frame("Carbon Frame");
    }

    void build_tyres() override {
        c->set_tyres("Slim Tires");
    }

    std::unique_ptr<cycle> get_result() override {
        auto res = std::make_unique<cycle>();
        std::swap(res, c);
        return res;
    }

private:
    std::unique_ptr<cycle> c { new cycle };
};

class cycle_director {
public:
    static std::unique_ptr<cycle> construct(cycle_builder &builder) {
        builder.build_frame();
        builder.build_tyres();
        return builder.get_result();
    }
};

int main(int, char const *[]) {
    unsigned cnt; std::cin >> cnt;
    mountain_cycle_builder mcb;
    road_cycle_builder rcb;
    while (cnt--) {
        std::string type; std::cin >> type;
        std::unique_ptr<cycle> res;
        if (type == "mountain") {
            res = cycle_director::construct(mcb);
        } else if (type == "road") {
            res = cycle_director::construct(rcb);
        }
        if (res) std::cout << *res << std::endl;
    }
    return 0;
}