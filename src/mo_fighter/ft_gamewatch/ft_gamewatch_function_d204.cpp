#pragma section data_type ".data" ".bss"

#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_107_E11C(void*, int);
void* fn_107_E104(void*, int);
void* fn_107_E0EC(void*, int);
void* fn_107_E0D4(void*, int);
void* fn_107_E0BC(void*, int);
void* fn_107_E0A4(void*, int);
void* fn_107_E08C(void*, int);
}

namespace {
struct State {
    bool first;
    bool second;
};
inline bool allActive0(char* object) {
    for (int i = 0; i < 5; ++i) {
        void* a = fn_107_E11C(object + 0xCDEC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive1(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E104(object + 0xAD00, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive2(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E0EC(object + 0x8C14, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive3(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E0D4(object + 0x6B0C, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive4(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E0BC(object + 0x4A20, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive5(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E0A4(object + 0x20F8, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
inline bool allActive6(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* a = fn_107_E08C(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(a) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}

extern "C" bool fn_107_D204(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !allActive0(object); }
    case 1: { State s = {false, false}; return !allActive1(object); }
    case 2: { State s = {false, false}; return !allActive2(object); }
    case 3: { State s = {false, false}; return !allActive3(object); }
    case 4: { State s = {false, false}; return !allActive4(object); }
    case 5: { State s = {false, false}; return !allActive5(object); }
    case 6: { State s = {false, false}; return !allActive6(object); }
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
