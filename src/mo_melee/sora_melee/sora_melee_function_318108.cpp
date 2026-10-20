#include <types.h>
#pragma force_active on

struct Buf {
    u32 a;
    u8 b;
    u8 pad[3];
    u32 c;
};

struct VObj {
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
    virtual void v17(s32 id, Buf* buf);
};

extern "C" {
void fn_27_318108(void* p, u32 arg) {
    Buf buf;
    buf.a = 0x83a;
    buf.b = 0;
    buf.c = arg;
    void* o = *(void**)((u8*)p + 0x60);
    o = *(void**)((u8*)o + 0xd8);
    o = *(void**)((u8*)o + 0x54);
    ((VObj*)o)->v17(3, &buf);
}
}
