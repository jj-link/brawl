#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_92_AC68(void*, int);
extern "C" void* fn_92_AC20(void*, int);

namespace {
struct State { bool first; bool second; };
template <unsigned Kind>
inline bool allActive(char* object) {
    for (int i = 0; i < (Kind == 0 ? 1 : 4); ++i) {
        char* w = (Kind == 0) ? static_cast<char*>(fn_92_AC68(object + 0x7F60, i))
                              : static_cast<char*>(fn_92_AC20(object + 0xC, i));
        if (!reinterpret_cast<soArticle*>(w + 0x88)->isActiveArticle())
            return false;
    }
    return true;
}
}

extern "C" bool fn_92_A2D0(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return !allActive<0>(object); }
    case 1: { State state = {false, false}; return !allActive<1>(object); }
    case 2: { State state = {false, false}; return false; }
    case 3: { State state = {false, false}; return false; }
    case 4: { State state = {false, false}; return false; }
    case 5: { State state = {false, false}; return false; }
    case 6: { State state = {false, false}; return false; }
    case 7: { State state = {false, false}; return false; }
    case 8: { State state = {false, false}; return false; }
    case 9: { State state = {false, false}; return false; }
    case 10: { State state = {false, false}; return false; }
    case 11: { State state = {false, false}; return false; }
    case 12: { State state = {false, false}; return false; }
    case 13: { State state = {false, false}; return false; }
    case 14: { State state = {false, false}; return false; }
    case 15: { State state = {false, false}; return false; }
    case 16: { State state = {false, false}; return false; }
    default: return false;
    }
}