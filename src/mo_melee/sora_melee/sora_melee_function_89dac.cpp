#include <types.h>
#pragma force_active on

struct Obj {
    virtual ~Obj();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj* get(s32);
};

struct ObjN {
    virtual ~ObjN();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ObjN* get();
};

struct Mid {
    u8 pad[0x7C];
    Obj* obj;
};

struct Holder {
    u8 pad[0xD8];
    Mid* unkD8;
};

struct Bits {
    u8 pad[5];
    u8 hi : 1;
    u8 rest : 7;
};

extern "C" void fn_27_89DAC(s32 arg0, Holder* arg1) {
    ((ObjN*)arg1->unkD8->obj->get(arg0))->get();
    Bits* p = (Bits*)arg1->unkD8->obj->get(arg0);
    p->hi = 0;
}
