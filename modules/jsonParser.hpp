//
//  jsonParser.hpp
//  cppDaily
//
//  Created by Abhinav Rathod on 4/3/24.
//

#ifndef jsonParser_hpp
#define jsonParser_hpp

#include <string>
#include "commonTypes.h"

class JsonParser
{
public:
    JsonParser(const std::string& jsonString);
    void parse();
    JsonMap getMap();
private:
    std::string m_jsonString;
    JsonMap m_jsonMap;
};

#endif /* jsonParser_hpp */
