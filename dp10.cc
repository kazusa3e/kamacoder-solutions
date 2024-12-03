#include <iostream>
#include <memory>

class tv {
public:
    virtual void turn_on() = 0;
    virtual void turn_off() = 0;
    virtual void switch_channel() = 0;
};

class Sony_tv : public tv {
public:
    void turn_on() override {
        std::cout << "Sony TV is ON" << std::endl;
    }
    void turn_off() override {
        std::cout << "Sony TV is OFF" << std::endl;
    }
    void switch_channel() override {
        std::cout << "Switching Sony TV channel" << std::endl;
    }
};

class TCL_tv : public tv {
public:
    void turn_on() override {
        std::cout << "TCL TV is ON" << std::endl;
    }
    void turn_off() override {
        std::cout << "TCL TV is OFF" << std::endl;
    }
    void switch_channel() override {
        std::cout << "Switching TCL TV channel" << std::endl;
    }
};

class remote_controller {
public:
    remote_controller() = delete;
    remote_controller(std::shared_ptr<tv> o): m_tv(o) {}

    virtual void perform_operation() = 0;

protected:
    std::shared_ptr<tv> m_tv;
};

class power_on_operation : public remote_controller {
public:
    power_on_operation() = delete;
    power_on_operation(std::shared_ptr<tv> o): remote_controller(o) {}
    void perform_operation() override {
        m_tv->turn_on();
    }
};

class power_off_operation : public remote_controller {
public:
    power_off_operation() = delete;
    power_off_operation(std::shared_ptr<tv> o): remote_controller(o) {}
    void perform_operation() override {
        m_tv->turn_off();
    }
};

class switch_channel_operation : public remote_controller {
public:
    switch_channel_operation() = delete;
    switch_channel_operation(std::shared_ptr<tv> o): remote_controller(o) {}
    void perform_operation() override {
        m_tv->switch_channel();
    }
};

int main(int, char const *[]) {
    unsigned cnt; std::cin >> cnt;

    while (cnt--) {
        unsigned tv_type, oper_type; std::cin >> tv_type >> oper_type;
        std::shared_ptr<tv> g_tv;
        if (tv_type == 0) g_tv = std::make_shared<Sony_tv>();
        else if (tv_type == 1) g_tv = std::make_shared<TCL_tv>();

        std::shared_ptr<remote_controller> rc;
        if (oper_type == 2) rc = std::make_shared<power_on_operation>(g_tv);
        else if (oper_type == 3) rc = std::make_shared<power_off_operation>(g_tv);
        else if (oper_type == 4) rc = std::make_shared<switch_channel_operation>(g_tv);

        rc->perform_operation();
    }
    return 0;
}