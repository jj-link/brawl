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
    virtual void v5();
    virtual int v6(void* a, int b, int c);
    virtual void v7();
    virtual void v8();
};

extern Obj71C8 lbl_27_bss_71C8;

class itValueAccesser {
public:
    enum ParamInt { PARAM_INT_0, PARAM_INT_1 };
};

class BaseItem {
public:
    int getParam(itValueAccesser::ParamInt p);
    u8 pad[0xCC];
};

int BaseItem::getParam(itValueAccesser::ParamInt p) {
    Obj71C8* o = &lbl_27_bss_71C8;
    return o->v6((u8*)this + 0xCC, (int)p, 0);
}
