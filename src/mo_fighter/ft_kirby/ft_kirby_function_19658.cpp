#pragma scheduling off
#pragma optimize_for_size on

#include <types.h>
#pragma force_active on

struct soModuleAccesser;

struct WorkObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(unsigned long);
    virtual void s5(int, unsigned long);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(int, unsigned long);
};

struct Inner {
    char pad[0x64];
    WorkObj* obj;
};

struct soValueAccesser {
    char pad[0xd8];
    Inner* inner;
    int getConstantInt(soModuleAccesser*, unsigned long, unsigned long);
};

extern "C" int fn_96_19658(void*, soValueAccesser* acc) {
    unsigned long unused;
    acc->inner->obj->s10(1, 0x20000012);
    if (acc->inner->obj->s4(0x20000012) <= 0) {
        WorkObj* o = acc->inner->obj;
        int v = acc->getConstantInt((soModuleAccesser*)0x5DC7, 0, unused);
        o->s5(v, 0x20000012);
        return 1;
    }
    return 0;
}
