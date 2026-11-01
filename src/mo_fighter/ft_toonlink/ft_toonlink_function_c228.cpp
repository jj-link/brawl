#pragma force_active on

struct State {
    unsigned int (*predicate)(void*);
    int accepted;
    int rejected;
    explicit State(unsigned int (*p)(void*)) : predicate(p), accepted(0), rejected(0) {}
};

extern "C" {
unsigned int fn_121_CC2C(void*);
char* fn_121_CD44(void*, int);
char* fn_121_CCFC(void*, int);
char* fn_121_CCE4(void*, int);
char* fn_121_CCCC(void*, int);
int fn_121_CC3C(State*, void*);
char* fn_121_CCB4(void*, int);
char* fn_121_CC9C(void*, int);
}

namespace {
struct Flags { bool first; bool second; };

template<unsigned Kind>
struct Counter : State {
    Counter() : State(fn_121_CC2C) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};

template<unsigned Kind>
inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter;
    for (int i = 0; i < (Kind == 1 ? 4 : 1); ++i) {
        char* article;
        if (Kind == 0) article = fn_121_CD44(object + 0x106FC, i);
        else if (Kind == 1) article = fn_121_CCFC(object + 0x8778, i);
        else if (Kind == 2) article = fn_121_CCE4(object + 0x6608, i);
        else if (Kind == 3) article = fn_121_CCCC(object + 0x4F34, i);
        else if (Kind == 4) article = fn_121_CCB4(object + 0x16E0, i);
        else article = fn_121_CC9C(object + 0xC, i);
        if (Kind == 3 || Kind == 5) {
            if (!fn_121_CC3C(&counter, article)) break;
        } else {
            counter(article + 0x88);
        }
    }
    return counter;
}

struct Module {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    virtual int get(int);
};

struct Modules { char pad[0x84]; Module* module; };
struct Owner { char pad[0xD8]; Modules* modules; };
}

extern "C" unsigned int fn_121_C228(char* object, Owner* owner, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return countArticles<5>(object).accepted; }
    case 6: { Flags f = {false, false}; return 2 - owner->modules->module->get(6); }
    case 7: { Flags f = {false, false}; return 0; }
    case 8: { Flags f = {false, false}; return 0; }
    case 9: { Flags f = {false, false}; return 0; }
    case 10: { Flags f = {false, false}; return 0; }
    case 11: { Flags f = {false, false}; return 0; }
    case 12: { Flags f = {false, false}; return 0; }
    case 13: { Flags f = {false, false}; return 0; }
    case 14: { Flags f = {false, false}; return 0; }
    case 15: { Flags f = {false, false}; return 0; }
    case 16: { Flags f = {false, false}; return 0; }
    default: return 0;
    }
}
