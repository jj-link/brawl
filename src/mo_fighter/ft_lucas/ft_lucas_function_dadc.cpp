#pragma section data_type ".data" ".bss"
#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
void* fn_114_E918(void*, int);
void* fn_114_E8F0(void*, int);
void* fn_114_E8C4(void*, int);
void* fn_114_E790(void*, int);
void* fn_114_E778(void*, int);
}
namespace {
struct State { bool first; bool second; };
inline bool active0(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_114_E918(object + 0x3E6F8, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active1(char* object) {
    for (int i = 0; i < 2; ++i) {
        void* a = fn_114_E8F0(object + 0x39ED4, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active2(char* object) {
    for (int i = 0; i < 2; ++i) {
        void* a = fn_114_E8C4(object + 0x1E2A0, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active3(char* object) {
    for (int i = 0; i < 16; ++i) {
        void* a = fn_114_E790(object + 0x211C, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active4(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_114_E778(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}
extern "C" bool fn_114_DADC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !active0(object); }
    case 1: { State s = {false, false}; return !active1(object); }
    case 2: { State s = {false, false}; return !active2(object); }
    case 3: { State s = {false, false}; return !active3(object); }
    case 4: { State s = {false, false}; return !active4(object); }
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