/******************************************************************************
File Name     : main.cpp
Author        : Dingjiang Zhou
Email         : zhoudingjiang@gmail.com
Create Time   : Wed, Dec. 23rd, 2020. 11:16:41 AM
Last Modified :
Purpose       :
-------------------------------------------------------------------------------
INPUTS

OUTPUTS

******************************************************************************/
#include "../exlcm/Example.hpp"
#include <iostream>
#include <lcm/lcm-cpp.hpp>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // --------------
    lcm::LCM lcm;
    if (!lcm.good()) {
        std::cout << argv[0] << ": lcm is not good" << std::endl;
        return 1;
    }
    // --------------
    exlcm::Example example_data;
    example_data.timestamp = 0;

    example_data.position[0] = 1;
    example_data.position[1] = 2;
    example_data.position[2] = 3;

    example_data.num_ranges = 15;
    example_data.ranges.resize(example_data.num_ranges);
    for (int i = 0; i < example_data.num_ranges; i++)
        example_data.ranges[i] = i;

    example_data.name    = "example string";
    example_data.enabled = true;

    for (int i = 0; i < 10; i++) {
        example_data.timestamp = ( unsigned )time(NULL);  // unit: s
        for (int j = 0; j < 3; j++) {
            example_data.position[j]++;
        }
        lcm.publish("LCM-EXAMPLE", &example_data);
        sleep(1);
    }

    // --------------
    return 0;
}
