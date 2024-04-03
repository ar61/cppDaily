//
//  jsonParser.cpp
//  cppDaily
//
//  Created by Abhinav Rathod on 4/3/24.
//

#include "jsonParser.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>

JsonParser::JsonParser(const std::string& jsonString)
: m_jsonString(jsonString)
{}

void JsonParser::parse() {
    if(m_jsonString.empty()) {
        throw std::runtime_error("invalid input");
    }
    int quote1 = 0;
    char quote = '"';
    char openBrace = '{';
    
    std::string key;
    bool isKey = true;
    int idx = -1;
    for(int i = 0; i < m_jsonString.size(); ++i) {
        if(m_jsonString[i] == openBrace) {
            ++idx;
        }else if(m_jsonString[i] == quote) {
            if(quote1 == 0) {
                quote1 = i;
            } else {
                int from = quote1 + 1;
                int to = i - quote1 - 1;
                if(isKey) {
                    key = m_jsonString.substr(from, to);
                    isKey = false;
                } else {
                    m_jsonMap[idx][key] = m_jsonString.substr(from, to);
                    isKey = true;
                }
                quote1 = 0;
            }
        }
    }
}

JsonMap JsonParser::getMap() {
    return m_jsonMap;
}
