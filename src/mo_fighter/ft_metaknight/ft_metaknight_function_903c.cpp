#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_111_9884(void* array, int index);

namespace {
struct State {
    bool first;
    bool second;
};
inline bool allActive(char* object) {
    int i = 0;
    while (i < 1) {
        char* weapon = static_cast<char*>(fn_111_9884(object + 0xC, i));
        if (!reinterpret_cast<soArticle*>(weapon + 0x88)->isActiveArticle()) {
            return false;
        }
        ++i;
    }
    return true;
}
}

extern "C" bool fn_111_903C(char* object, void* operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !allActive(object); }
    case 1: { State s = {false, false}; return false; }
    case 2: { State s = {false, false}; return false; }
    case 3: { State s = {false, false}; return false; }
    case 4: { State s = {false, false}; return false; }
    case 5: { State s = {false, false}; return false; }
    case 6: { State s = {false, false}; return false; }
    case 7: { State s = {false, false}; return false; }
    case 8: { State s = {false, false}; return false; }
    case 9: { State s = {false, false}; return false; }
    case 10: { State s = {false, false}; return false; }
    case 11: { State s = {false, false}; return false; }
    case 12: { State s = {false, false}; return false; }
    case 13: { State s = {false, false}; return false; }
    case 14: { State s = {false, false}; return false; }
    case 15: { State s = {false, false}; return false; }
    case 16: { State s = {false, false}; return false; }
    default: return false;
    }
}
