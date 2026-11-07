#pragma section data_type ".data" ".bss"
#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
void* fn_116_BD58(void*, int);
void* fn_116_BD30(void*, int);
void* fn_116_BCE8(void*, int);
}
namespace {
struct State { bool first; bool second; };
inline bool active0(char* object) {
    for (int i = 0; i < 5; ++i) {
        void* a = fn_116_BD58(object + 0x8D8C, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active1(char* object) {
    for (int i = 0; i < 2; ++i) {
        void* a = fn_116_BD30(object + 0x5BA0, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active2(char* object) {
    for (int i = 0; i < 4; ++i) {
        void* a = fn_116_BCE8(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}
extern "C" bool fn_116_B24C(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !active0(object); }
    case 1: { State s = {false, false}; return !active1(object); }
    case 2: { State s = {false, false}; return !active2(object); }
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