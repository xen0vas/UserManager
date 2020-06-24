#include "spc.h"

using std::string; 

Spc::Spc()
{}

Spc::~Spc()
{}

void Spc::spc_sanitize(std::string &stringValue)
{
stringValue.erase(
    std::remove_if(
        stringValue.begin(), stringValue.end(), [](char const c) {
            return '\\' == c || '"' == c || '#' == c || '\'' == c || '\r' == c || '{' == c || '}' ==c || '[' == c || ']' == c || '&' == c || '+' == c || ';' == c || '<' == c || '>' == c || '-' == c || '/' == c || '*' == c || '%' == c || '\n' == c || '|' == c || '\0' == c || '\x1A' == c;
        }
    ),
    stringValue.end()
    );
}

