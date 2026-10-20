#include <types.h>
#pragma force_active on

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32 a);
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(u32 a, u32 b, u32 c);
};

extern "C" void fn_27_300530(void *p1, char *p2, s32 p3)
{
    if (p3 < 9) {
        if (p3 >= 1) {
            return;
        }
    }
    Obj *o = *(Obj **)(*(char **)(p2 + 0xd8) + 0x64);
    u32 ret = o->v4(0x10000006);
    Obj *o2 = *(Obj **)(*(char **)(p2 + 0xd8) + 0x88);
    o2->v22(ret, 1, 1);
}
