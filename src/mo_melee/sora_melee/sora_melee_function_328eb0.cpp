#include <types.h>
#pragma force_active on

struct P2 {
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
};

struct Q {
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
    virtual void v15(u32 value);
};

struct P1 {
    char pad0[0xc];
    P2* a;
    char pad1[0x64 - 0x10];
    Q* b;
};

struct Obj {
    char pad[0xd8];
    P1* p;
};

extern "C" {
void fn_27_328EB0(void*, Obj* obj) {
    obj->p->a->v11();
    obj->p->b->v15(0x21000004);
}
}
