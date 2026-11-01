#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_102_A22C(void*, int);

namespace {
struct State {
    bool first;
    bool second;
};

inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 6; ++i) {
        char* weapon = static_cast<char*>(fn_102_A22C(object + 0xC, i));
        if (!reinterpret_cast<soArticle*>(weapon + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_102_99E0(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return !allArticlesActive(object); }
    case 1: { State state = {false, false}; return false; }
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
