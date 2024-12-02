#include <iostream>
#include <memory>

// default charge adapter
class USB_adapter {
public:
    virtual void charge_with_USB() = 0;
};

class TypeC_adapter {
public:
    virtual void charge_with_TypeC() = 0;
};

class TypeC : public TypeC_adapter {
public:
    void charge_with_TypeC() override {
        std::cout << "TypeC" << std::endl;
    }
};

class TypeC_to_USB_adapter : public USB_adapter {
public:
    TypeC_to_USB_adapter() = delete;
    TypeC_to_USB_adapter(std::shared_ptr<TypeC_adapter> adapter)
        : type_c_adapter(adapter) {};

    void charge_with_USB() override {
        std::cout << "USB Adapter" << std::endl;
    }

private:
    std::shared_ptr<TypeC_adapter> type_c_adapter;
};

class computer : public TypeC_adapter, public USB_adapter {
public:
    computer() {
        typec_to_usb = std::make_shared<TypeC_to_USB_adapter>(typec);
    }

    void charge_with_TypeC() override {
        typec->charge_with_TypeC();
    }

    void charge_with_USB() override {
            typec_to_usb->charge_with_USB();
    }

private:
    std::shared_ptr<TypeC> typec { std::make_shared<TypeC>() };
    std::shared_ptr<TypeC_to_USB_adapter> typec_to_usb;
};

int main(int, char const *[]) {
    unsigned cnt; std::cin >> cnt;
    computer com;
    while (cnt--) {
        unsigned type; std::cin >> type;
        if (type == 1) {
            com.charge_with_TypeC();
        } else if (type == 2) {
            com.charge_with_USB();
        }
    }
    return 0;
}