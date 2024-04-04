//
//  numBeds.cpp
//  cppDaily
//
//  Created by Abhinav Rathod on 4/3/24.
//

#include "numBeds.hpp"
#include "../modules/jsonParser.hpp"
#include <iostream>

void NumBeds::sampleGetNumBeds() {
    std::string json = "[{\"unit\": \"1\", \"description\": \"Majestic 1-bedroom apt\"},\
                        {\"unit\": \"2\", \"description\": \"Majestic studio apt\"}]";
    auto values = getNumBeds(json);
    std::cout << "[";
    for(auto i : values) {
        std::cout << i << ",";
    }
    std::cout << "]";
}

std::vector<int>
NumBeds::getNumBeds(const std::string& jsonString) {
    JsonParser jp(jsonString);
    jp.parse();
    std::vector<int> beds;
    auto map = jp.getMap();
    for (auto [k,v] : map) {
        for(auto [ki,vi] : map[k]) {
            if(ki == "description") {
                if(vi.find("1-bedroom") != std::string::npos) {
                    beds.push_back(1);
                } else if (vi.find("studio") != std::string::npos) {
                    beds.push_back(0);
                }
            }
        }
    }
    return beds;
}
