#pragma force_active on
extern "C" {
bool fn_93_CC30(void*);
char* fn_93_CD48(void*, int);
char* fn_93_CD00(void*, int);
char* fn_93_CCE8(void*, int);
char* fn_93_CCD0(void*, int);
char* fn_93_CCB8(void*, int);
char* fn_93_CCA0(void*, int);
}

struct State {
    bool (*predicate)(void*);
    unsigned accepted;
    unsigned rejected;
    explicit State(bool (*p)(void*)) : predicate(p), accepted(0), rejected(0) {}
};

extern "C" int fn_93_CC40(State*, void*);

namespace {
struct Flags { bool first; bool second; };

template<unsigned Kind>
struct Counter : State {
    Counter() : State(fn_93_CC30) {}
    inline void operator()(void* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};

template<unsigned Kind>
inline Counter<Kind> count(char* object) {
    Counter<Kind> counter;
    for (int i = 0; i < (Kind == 1 ? 4 : 1); ++i) {
        char* weapon =
            Kind == 0 ? fn_93_CD48(object + 0x106FC, i) :
            Kind == 1 ? fn_93_CD00(object + 0x8778, i) :
            Kind == 2 ? fn_93_CCE8(object + 0x6608, i) :
            Kind == 3 ? fn_93_CCD0(object + 0x2DB4, i) :
            Kind == 4 ? fn_93_CCB8(object + 0x16E0, i) :
                        fn_93_CCA0(object + 0xC, i);
        if (Kind < 4) {
            counter(weapon + 0x88);
        } else if (!fn_93_CC40(&counter, weapon)) {
            break;
        }
    }
    return counter;
}

struct Module {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual int get(int);
};
struct Modules { char pad[0x84]; Module* module; };
struct Owner { char pad[0xD8]; Modules* modules; };
}

extern "C" unsigned fn_93_C22C(char* object, Owner* owner, unsigned kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return count<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return count<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return count<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return count<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return count<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return count<5>(object).accepted; }
    case 6: {
        Flags f = {false, false};
        return 2 - owner->modules->module->get(6);
    }
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
