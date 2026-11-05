#pragma section data_type ".data" ".bss"
#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
void* fn_104_1D0DC(void*, int);
void* fn_104_1D0C4(void*, int);
void* fn_104_1D0AC(void*, int);
void* fn_104_1D094(void*, int);
void* fn_104_1D07C(void*, int);
void* fn_104_1D064(void*, int);
}
namespace {
struct State { bool first; bool second; };
inline bool active0(char* object) {
    for (int i = 0; i < 8; ++i) {
        void* a = fn_104_1D0DC(object + 0x96fc, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active1(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_1D0C4(object + 0x7efc, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active2(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_1D0AC(object + 0x5dc8, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active3(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_1D094(object + 0x3e7c, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active4(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_1D07C(object + 0x1f48, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool active5(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_104_1D064(object + 0xc, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}
extern "C" bool fn_104_1C33C(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !active0(object); }
    case 1: { State s = {false, false}; return !active1(object); }
    case 2: { State s = {false, false}; return !active2(object); }
    case 3: { State s = {false, false}; return !active3(object); }
    case 4: { State s = {false, false}; return !active4(object); }
    case 5: { State s = {false, false}; return !active5(object); }
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
