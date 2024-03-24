#ifndef TN_TEXT_H
#define TN_TEXT_H

#include <string_view>


inline std::string_view TN_utf8_bom()
{
    static const unsigned char ret[] = { 0xEF, 0xBB, 0xBF };
    return { (const char*)ret, sizeof(ret) };
}

#endif
