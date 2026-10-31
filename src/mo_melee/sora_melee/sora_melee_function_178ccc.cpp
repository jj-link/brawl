#include <types.h>
#pragma force_active on

struct V {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void call(s32, s32);
};

extern "C" void fn_27_178CCC(void*, void* p2, s32 p3) {
    if (p3 == 0xF1) {
        return;
    }
    if (p3 >= 0xF1) {
        goto invoke;
    }
    if (p3 >= 0x3D) {
        goto invoke;
    }
    if (p3 >= 0x39) {
        return;
    }

invoke:
    V* obj = (V*)*(void**)((u8*)*(void**)((u8*)p2 + 0xD8) + 0x3C);
    obj->call(0, 0);
}
