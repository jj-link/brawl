#pragma force_active on
extern "C" {
unsigned int fn_96_11668(void*);
int fn_96_11678(void*, void*);
char* fn_96_116D8(void*, int);
char* fn_96_116F0(void*, int);
char* fn_96_11708(void*, int);
char* fn_96_11720(void*, int);
char* fn_96_11738(void*, int);
char* fn_96_11750(void*, int);
char* fn_96_11768(void*, int);
char* fn_96_11780(void*, int);
char* fn_96_11798(void*, int);
char* fn_96_117B0(void*, int);
char* fn_96_117C8(void*, int);
}
struct State {
    unsigned int (*predicate)(void*);
    int accepted, rejected;
    explicit State(unsigned int (*p)(void*)) : predicate(p), accepted(0), rejected(0) {}
};
namespace {
struct Flags { bool first, second; };
template<unsigned Kind> struct Counter : State {
    Counter() : State(fn_96_11668) {}
    void operator()(void* article) {
        if (predicate(article) == 1) { ++accepted; return; }
        ++rejected;
    }
};
template<unsigned Kind> inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter;
    for (int i = 0; i < 1; ++i) {
        char* article;
        if (Kind == 0) article = fn_96_117C8(object + 0x10F74, i);
        else if (Kind == 1) article = fn_96_117B0(object + 0xEF8C, i);
        else if (Kind == 2) article = fn_96_11798(object + 0xCFA8, i);
        else if (Kind == 3) article = fn_96_11780(object + 0xAEA0, i);
        else if (Kind == 4) article = fn_96_11768(object + 0x8E1C, i);
        else if (Kind == 5) article = fn_96_11750(object + 0x7230, i);
        else if (Kind == 6) article = fn_96_11738(object + 0x5B5C, i);
        else if (Kind == 7) article = fn_96_11720(object + 0x4488, i);
        else if (Kind == 8) article = fn_96_11708(object + 0x2DB4, i);
        else if (Kind == 9) article = fn_96_116F0(object + 0x16E0, i);
        else article = fn_96_116D8(object + 0xC, i);
        if (Kind >= 6) {
            if (!fn_96_11678(&counter, article)) break;
        } else {
            counter(article + 0x88);
        }
    }
    return counter;
}
}
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
struct Modules { char pad[0x84]; Class_CD28* module; };
struct Owner { char pad[0xD8]; Modules* modules; };
extern "C" unsigned int fn_96_108CC(char* object, Owner* owner, unsigned int kind) {
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
    case 11: { Flags f = {false, false}; return 2 - owner->modules->module->fn_96_23CE4(11); }
    case 12: { Flags f = {false, false}; return 0; }
    case 13: { Flags f = {false, false}; return 0; }
    case 14: { Flags f = {false, false}; return 0; }
    case 15: { Flags f = {false, false}; return 0; }
    case 16: { Flags f = {false, false}; return 0; }
    default: return 0;
    }
}