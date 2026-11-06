#include <types.h>
#pragma force_active on

class Obj1 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(u32 a);
    virtual void slot19(u32 a);
};

class Obj2 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(s32 a, void* b);
};

struct Inner {
    char pad0[0x64];
    Obj1* m64;
    char pad1[0x8];
    Obj2* m70;
};

struct Mid {
    char pad[0xd8];
    Inner* d8;
};

struct Top {
    char pad[0x60];
    Mid* m60;
};

extern "C" void fn_27_29A934(void* unused, void* obj, s32 arg) {
    Top* top = (Top*)obj;
    Obj1* p = top->m60->d8->m64;
    switch (arg) {
    case 0: {
        p->slot18(0x12000000);
        Mid* m = top->m60;
        m->d8->m70->s3(3, m);
        break;
    }
    case 1: {
        u32 base = 0x12000000;
        p->slot18(base + 1);
        p->slot19(base + 8);
        Mid* m = top->m60;
        m->d8->m70->s3(8, m);
        break;
    }
    }
}
