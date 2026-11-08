#pragma force_active on
extern "C" {
unsigned int fn_122_11E3C(void*);
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
struct State {
    unsigned int (*predicate)(void*);
    int accepted, rejected;
    explicit State(unsigned int (*p)(void*)) : predicate(p), accepted(0), rejected(0) {}
};
namespace {
struct Flags { bool first, second; };
template<unsigned Kind> struct Counter : State {
    Counter() : State(fn_122_11E3C) {}
    void operator()(void* article) {
        if (predicate(article) == 1) { ++accepted; return; }
        ++rejected;
    }
};
template<unsigned Kind> inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter;
    for (int i = 0; i < (Kind == 12 ? 2 : 1); ++i) {
        char* article;
        if (Kind == 0) article = fn_122_11F7C(object + 0x22070, i);
        else if (Kind == 1) article = fn_122_11F64(object + 0x1A37C, i);
        else if (Kind == 2) article = fn_122_11F4C(object + 0x18CC0, i);
        else if (Kind == 3) article = fn_122_11F34(object + 0x16A94, i);
        else if (Kind == 4) article = fn_122_11F1C(object + 0x14658, i);
        else if (Kind == 5) article = fn_122_11F04(object + 0x132E8, i);
        else if (Kind == 6) article = fn_122_11EEC(object + 0xCB18, i);
        else if (Kind == 7) article = fn_122_11ED4(object + 0xABE4, i);
        else if (Kind == 8) article = fn_122_11EBC(object + 0x8C80, i);
        else if (Kind == 9) article = fn_122_11EA4(object + 0x6CB0, i);
        else if (Kind == 10) article = fn_122_11E8C(object + 0x4D60, i);
        else if (Kind == 11) article = fn_122_11E74(object + 0x2DB0, i);
        else article = fn_122_11E4C(object + 0xC, i);
        counter(article + 0x88);
    }
    return counter;
}
}
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
struct Modules { char pad[0x84]; Class_E104* module; };
struct Owner { char pad[0xD8]; Modules* modules; };
extern "C" unsigned int fn_122_10E38(char* object, Owner* owner, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return countArticles<5>(object).accepted; }
    case 6: { Flags f = {false, false}; return countArticles<6>(object).accepted; }
    case 7: { Flags f = {false, false}; return countArticles<7>(object).accepted; }
    case 8: { Flags f = {false, false}; return countArticles<8>(object).accepted; }
    case 9: { Flags f = {false, false}; return countArticles<9>(object).accepted; }
    case 10: { Flags f = {false, false}; return countArticles<10>(object).accepted; }
    case 11: { Flags f = {false, false}; return countArticles<11>(object).accepted; }
    case 12: { Flags f = {false, false}; return countArticles<12>(object).accepted; }
    case 13: { Flags f = {false, false}; return 2 - owner->modules->module->fn_122_18EAC(13); }
    case 14: { Flags f = {false, false}; return 1 - owner->modules->module->fn_122_18EAC(14); }
    case 15: { Flags f = {false, false}; return 0; }
    case 16: { Flags f = {false, false}; return 0; }
    default: return 0;
    }
}