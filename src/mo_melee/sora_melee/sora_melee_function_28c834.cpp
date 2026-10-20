#include <types.h>
#pragma force_active on

class Base71C8 {
public:
    u32 pad;
};

class Obj71C8 : public Base71C8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual float v5(void* a, int b, int c);
    virtual int v6(void* a, int b, int c);
    virtual void v7();
    virtual void v8();
};

extern Obj71C8 lbl_27_bss_71C8;

class itValueAccesser {
public:
    enum ParamFloat { PARAM_FLOAT_0, PARAM_FLOAT_1 };
};

class BaseItem {
public:
    float getParam(itValueAccesser::ParamFloat p);
    u8 pad[0xCC];
};

float BaseItem::getParam(itValueAccesser::ParamFloat p) {
    Obj71C8* o = &lbl_27_bss_71C8;
    return o->v5((u8*)this + 0xCC, (int)p, 0);
}
