#pragma section data_type ".data" ".bss"

#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_103_B3B8(void*, int);
void* fn_103_B3D0(void*, int);
}

namespace {
struct State {
    bool first;
    bool second;
};
inline bool allActiveD3(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_103_B3D0(object + 0xDD10, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActiveB8(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_103_B3B8(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}

extern "C" bool fn_103_AA5C(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !allActiveD3(object); }
    case 1: { State s = {false, false}; return !allActiveB8(object); }
    case 2: { State s = {false, false}; return true; }
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
