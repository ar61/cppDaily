//
//  main.cpp
//  cppDaily
//
//  Created by Abhinav Rathod on 3/29/24.
//

// 1. 1,5,10,25 change to return on a transaction with min coins
// 2.
// 3. parse json array and extract elements to handle some logic to return values

#include "jsonParser.hpp"
#include <iostream>
#include <vector>

void processJson() {
    std::string json = "[{\"unit\": \"1\", \"description\": \"Majestic 1-bedroom apt\"},\
                         {\"unit\": \"2\", \"description\": \"Majestic studio apt\"}]";
    JsonParser jp(json);
    jp.parse();
    std::vector<int> values;
    auto map = jp.getMap();
    for (auto [k,v] : map) {
        for(auto [ki,vi] : map[k]) {
            if(ki == "description") {
                if(vi.find("1-bedroom") != std::string::npos) {
                    values.push_back(1);
                } else if (vi.find("studio") != std::string::npos) {
                    values.push_back(0);
                }
            }
        }
    }
    
    for(auto i : values) {
        std::cout << i << ",";
    }
}

int main(int argc, const char * argv[]) {
    
    processJson();
    return 0;
}
