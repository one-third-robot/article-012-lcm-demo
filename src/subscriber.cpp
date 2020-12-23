#include "../exlcm/Example.hpp"
#include <iostream>
#include <lcm/lcm-cpp.hpp>

class HandlerExample {
public:
    ~HandlerExample() {}
    void handle(const lcm::ReceiveBuffer* rbuf, const std::string& chan,
                const exlcm::Example* msg) {
        static int loop_count = 0;
        std::cout << "-------------------------" << std::endl
                  << loop_count++ << ": Received message on channel \"" << chan
                  << "\":" << std::endl;
        std::cout << "  timestamp   = " << ( long long )msg->timestamp
                  << std::endl;
        std::cout << "  position    = (" << msg->position[0] << ", "
                  << msg->position[1] << ", " << msg->position[2] << ")"
                  << std::endl;
        std::cout << "  ranges:" << std::endl;
        for (int i = 0; i < msg->num_ranges; i++) {
            std::cout << "  " << msg->ranges[i];
        }
        std::cout << std::endl;
        std::cout << "  name        = " << msg->name << std::endl;
        if (msg->enabled) {
            std::cout << "  enabled     = true" << std::endl;
        }
        else {
            std::cout << "  enabled     = false" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    lcm::LCM lcm;
    if (!lcm.good()) {
        std::cout << argv[0] << ": lcm is not good" << std::endl;
        return 1;
    }
    HandlerExample handle_example;
    lcm.subscribe("LCM-EXAMPLE", &HandlerExample::handle, &handle_example);

    while (0 == lcm.handle()) {
    }

    return 0;
}
