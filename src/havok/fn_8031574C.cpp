#include <types.h>
#pragma force_active on

struct FnObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(u32 val);
    char pad[0x10 - 4];
    u32 m10;
    char pad2[4];
    u32 m18;
};

extern FnObj* lbl_805A0EC8;

extern "C" void fn_8031574C(u32 val) {
    FnObj* obj = lbl_805A0EC8;
    obj->m10 = val;
    if (val == obj->m18) {
        obj->v4(val);
    }
}
