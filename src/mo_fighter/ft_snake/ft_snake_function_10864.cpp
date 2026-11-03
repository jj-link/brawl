#include <so/article/so_article.h>
#pragma force_active on

class Class_E104 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_176B0();
    virtual void fn_122_18F4C();
    virtual void fn_122_18F44();
    virtual void fn_122_18F3C();
    virtual void fn_122_18F34();
    virtual void fn_122_18F2C();
    virtual void fn_122_18F24();
    virtual void fn_122_18F1C();
    virtual void fn_122_18F14();
    virtual void fn_122_18F0C();
    virtual void fn_122_18F04();
    virtual void fn_122_18EFC();
    virtual void fn_122_18EF4();
    virtual void fn_122_18EA4();
    virtual void fn_122_18EEC();
    virtual void fn_122_18EDC();
    virtual void fn_122_18ECC();
    virtual void fn_122_18EBC();
    virtual int fn_122_18EAC(int);
};

extern "C" {
char* fn_122_11F7C(void*, int);
char* fn_122_11F64(void*, int);
char* fn_122_11F4C(void*, int);
char* fn_122_11F34(void*, int);
char* fn_122_11F1C(void*, int);
char* fn_122_11F04(void*, int);
char* fn_122_11EEC(void*, int);
char* fn_122_11ED4(void*, int);
char* fn_122_11EBC(void*, int);
char* fn_122_11EA4(void*, int);
char* fn_122_11E8C(void*, int);
char* fn_122_11E74(void*, int);
char* fn_122_11E4C(void*, int);
}

namespace {
struct State { bool first; bool second; };
struct Modules { char pad[0x84]; Class_E104* module; };
struct Owner { char pad[0xD8]; Modules* modules; };

template<unsigned K>
inline bool all(char* p) {
    for (int i = 0; i < (K == 12 ? 2 : 1); ++i) {
        char* w =
            K == 0 ? fn_122_11F7C(p + 0x22070, i) : 
            K == 1 ? fn_122_11F64(p + 0x1A37C, i) : 
            K == 2 ? fn_122_11F4C(p + 0x18CC0, i) : 
            K == 3 ? fn_122_11F34(p + 0x16A94, i) : 
            K == 4 ? fn_122_11F1C(p + 0x14658, i) : 
            K == 5 ? fn_122_11F04(p + 0x132E8, i) : 
            K == 6 ? fn_122_11EEC(p + 0xCB18, i) : 
            K == 7 ? fn_122_11ED4(p + 0xABE4, i) : 
            K == 8 ? fn_122_11EBC(p + 0x8C80, i) : 
            K == 9 ? fn_122_11EA4(p + 0x6CB0, i) : 
            K == 10 ? fn_122_11E8C(p + 0x4D60, i) : 
            K == 11 ? fn_122_11E74(p + 0x2DB0, i) : 
                     fn_122_11E4C(p + 0xC, i); 
        if (!reinterpret_cast<soArticle*>(w + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_122_10864(char* p, Owner* owner, unsigned kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return !all<0>(p); }
    case 1: { State state = {false, false}; return !all<1>(p); }
    case 2: { State state = {false, false}; return !all<2>(p); }
    case 3: { State state = {false, false}; return !all<3>(p); }
    case 4: { State state = {false, false}; return !all<4>(p); }
    case 5: { State state = {false, false}; return !all<5>(p); }
    case 6: { State state = {false, false}; return !all<6>(p); }
    case 7: { State state = {false, false}; return !all<7>(p); }
    case 8: { State state = {false, false}; return !all<8>(p); }
    case 9: { State state = {false, false}; return !all<9>(p); }
    case 10: { State state = {false, false}; return !all<10>(p); }
    case 11: { State state = {false, false}; return !all<11>(p); }
    case 12: { State state = {false, false}; return !all<12>(p); }
    case 13: { State state = {false, false}; return owner->modules->module->fn_122_18EAC(13) < 2; }
    case 14: { State state = {false, false}; return owner->modules->module->fn_122_18EAC(14) < 1; }
    case 15: { State state = {false, false}; return false; }
    case 16: { State state = {false, false}; return false; }
    default: return false;
    }
}
