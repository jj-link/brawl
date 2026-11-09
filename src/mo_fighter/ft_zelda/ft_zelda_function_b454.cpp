#pragma section data_type ".data" ".bss"
#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
void* fn_104_C020(char* p, int i);
void* fn_104_BFE8(char* p, int i);
void* fn_104_BFD0(void* object, int i);
void* fn_104_BFB8(void* object, int i);
}
namespace {
struct State { bool first; bool second; };
inline bool allActive0(char* object) {
    for (int i = 0; i < 3; ++i) {
        void* a = fn_104_C020(object + 0x9BE0, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive1(char* object) {
    for (int i = 0; i < 3; ++i) {
        void* a = fn_104_BFE8(object + 0x3E7C, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive2(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_BFD0(object + 0x1F48, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive3(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_BFB8(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}
extern "C" bool fn_104_B454(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !allActive0(object); }
    case 1: { State s = {false, false}; return !allActive1(object); }
    case 2: { State s = {false, false}; return !allActive2(object); }
    case 3: { State s = {false, false}; return !allActive3(object); }
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
