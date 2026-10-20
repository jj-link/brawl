#include <types.h>
#pragma force_active on

class soControllerModuleImpl {
public:
    void activate();
};

class SubObj {
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
};

class ObjB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
};

struct Self {
    char pad0[0x30];
    SubObj m30;
    char pad1[0x148 - 0x30 - sizeof(SubObj)];
    ObjB* p148;
    char pad2[0x15c - 0x148 - sizeof(ObjB*)];
    s32 r15c;
    s32 r160;
    s32 r164;
};

extern "C" void fn_27_1505DC(Self* self) {
    self->m30.v12();
    ((soControllerModuleImpl*)self)->activate();
    self->r164 = 0;
    self->r160 = 0;
    self->r15c = self->p148->v3();
}
