#pragma force_active on

typedef unsigned int u32;
typedef int s32;

class IFirst {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual u32 target(u32 a);
};

class ISecond {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void call();
};

struct X {
    char pad1[0x64];
    IFirst* first;
    char pad2[0x7C - 0x68];
    ISecond* second;
};

struct Ft {
    char pad[0xD8];
    X* x;
};

extern "C" void fn_27_169914(void*, Ft* p, s32 arg) {
    if (p->x->first->target(0x2200001F) == 1) {
        switch (arg) {
        case 0x16:
        case 0x17:
        case 0x18:
            p->x->second->call();
            break;
        }
    }
}
