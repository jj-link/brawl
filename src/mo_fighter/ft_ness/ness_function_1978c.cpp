#pragma section data_type ".data" ".bss"

#include <so/article/so_article.h>
#pragma force_active on

extern "C" char* fn_101_19FC4(void*, int);

namespace {
struct State {
    bool first;
    bool second;
};
inline bool allActive(char* object) {
    for (int i = 0; i < 6; ++i) {
        char* a = fn_101_19FC4(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(a + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}

extern "C" bool fn_101_1978C(char* object, unsigned int operation, unsigned int kind) {
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
