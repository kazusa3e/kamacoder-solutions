#include <iostream>

class air_conditioner {
public:
    void turn_off() {
        std::cout << "Air Conditioner is turned off." << std::endl;
    }
};

class desk_lamp {
public:
    void turn_off() {
        std::cout << "Desk Lamp is turned off." << std::endl;
    }
};

class television {
public:
    void turn_off() {
        std::cout << "Television is turned off." << std::endl;
    }
};

class power_swich_facade {
public:
    void turn_off_device(unsigned device_code) {
        if (device_code == 1) {
            ac.turn_off();
        } else if (device_code == 2) {
            dl.turn_off();
        } else if (device_code == 3) {
            tv.turn_off();
        } else if (device_code == 4) {
            // ac.turn_off(); dl.turn_off(); tv.turn_off();
            std::cout << "All devices are off." << std::endl;
        }
    }

private:
    air_conditioner ac;
    desk_lamp dl;
    television tv;
};

int main(int, char const *[]) {
    power_swich_facade psf;
    unsigned cnt; std::cin >> cnt;
    while (cnt--) {
        unsigned device_code; std::cin >> device_code;
        psf.turn_off_device(device_code);
    }
    return 0;
}