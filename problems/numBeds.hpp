//
//  numBeds.hpp
//  cppDaily
//
//  Created by Abhinav Rathod on 4/3/24.
//

#ifndef numBeds_hpp
#define numBeds_hpp

#include <vector>
#include <string>

class NumBeds {
public:
    // given a json string get number of beds in an array for each item
    static void sampleGetNumBeds();
    static std::vector<int> getNumBeds(const std::string& jsonString);
};

#endif /* numBeds_hpp */
