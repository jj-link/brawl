#include <so/article/so_article.h>
#pragma force_active on

class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual int fn_96_23CE4(int);
};

extern "C" {
char* fn_96_117C8(void*, int);
char* fn_96_117B0(void*, int);
char* fn_96_11798(void*, int);
char* fn_96_11780(void*, int);
char* fn_96_11768(void*, int);
char* fn_96_11750(void*, int);
char* fn_96_11738(void*, int);
char* fn_96_11720(void*, int);
char* fn_96_11708(void*, int);
char* fn_96_116F0(void*, int);
char* fn_96_116D8(void*, int);
}

namespace {
struct State { bool first; bool second; };
struct Modules { char pad[0x84]; Class_CD28* module; };
struct Owner { char pad[0xD8]; Modules* modules; };

template<unsigned K>
inline bool all(char* p) {
    for (int i = 0; i < 1; ++i) {
        char* w =
            K == 0 ? fn_96_117C8(p + 0x10F74, i) :
            K == 1 ? fn_96_117B0(p + 0xEF8C, i) :
            K == 2 ? fn_96_11798(p + 0xCFA8, i) :
            K == 3 ? fn_96_11780(p + 0xAEA0, i) :
            K == 4 ? fn_96_11768(p + 0x8E1C, i) :
            K == 5 ? fn_96_11750(p + 0x7230, i) :
            K == 6 ? fn_96_11738(p + 0x5B5C, i) :
            K == 7 ? fn_96_11720(p + 0x4488, i) :
            K == 8 ? fn_96_11708(p + 0x2DB4, i) :
            K == 9 ? fn_96_116F0(p + 0x16E0, i) :
                     fn_96_116D8(p + 0xC, i);
        if (!reinterpret_cast<soArticle*>(w + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_96_103C8(char* p, Owner* owner, unsigned kind) {
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
    case 11: { State state = {false, false}; return owner->modules->module->fn_96_23CE4(11) < 2; }
    case 12: { State state = {false, false}; return false; }
    case 13: { State state = {false, false}; return false; }
    case 14: { State state = {false, false}; return false; }
    case 15: { State state = {false, false}; return false; }
    case 16: { State state = {false, false}; return false; }
    default: return false;
    }
}
