#include <types.h>
#pragma force_active on

class fn27A {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v7(u32 a, u32 b) = 0;
};

class fn27B {
public:
    virtual void w0() = 0;
    virtual void w1() = 0;
    virtual void w2() = 0;
    virtual void w5(u32 a, void* b) = 0;
};

extern "C" void fn_27_155B80(void* unused, u8* self, u8* p) {
    (*(fn27A**)(*(u8**)(self + 0xd8) + 0x64))->v7(*(u32*)(p + 0x4), 0x10000015);
    (*(fn27A**)(*(u8**)(self + 0xd8) + 0x64))->v7(*(u32*)(p + 0x8), 0x10000016);
    (*(fn27A**)(*(u8**)(self + 0xd8) + 0x64))->v7(*(u16*)(p + 0x2), 0x10000017);
    (*(fn27B**)(*(u8**)(self + 0xd8) + 0x70))->w5(0xC3, self);
}
