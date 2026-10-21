#include <types.h>
#pragma force_active on

struct FnObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v6(u32 val);
    char pad[0x10 - 4];
    u32 m10;
    char pad2[4];
    u32 m18;
};

struct FnArg {
    char pad[0x18];
    u32 val;
};

extern FnObj* lbl_805A0EC8;

extern "C" {
void fn_8032BCD4(int a, int b, int c, FnArg* arg) {
    u32 val = arg->val;
    FnObj* obj = lbl_805A0EC8;
    obj->m10 = val;
    if (val == obj->m18) {
        obj->v6(val);
    }
}
}
