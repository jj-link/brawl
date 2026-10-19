#include <types.h>
#pragma force_active on

class Vtbl17 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
};

struct Mid {
    char pad[0x70];
    Vtbl17* p;
};

struct LinkObj {
    char pad2[0xd8];
    Mid* m;
};

extern "C" void fn_93_FCC8(void*, void*);

extern "C" void fn_93_A3A8(void*, void* arg2, LinkObj* arg3) {
    if (arg3->m->p->v16() == 0x116) {
        fn_93_FCC8(arg2, arg3);
    }
}
