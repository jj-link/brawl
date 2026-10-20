#include <types.h>
#pragma force_active on

struct VObj {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void target(s32, s32, s32);
};

extern "C" {
void fn_27_3B5FBC(u8* p) {
    u8* a = *(u8**)(p + 0x60);
    a = *(u8**)(a + 0xd8);
    a = *(u8**)(a + 0x88);
    return ((VObj*)a)->target(0, 0, 1);
}
}
