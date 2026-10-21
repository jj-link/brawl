#include <types.h>
#pragma force_active on

class fn27A {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(u32 a, u32 b);
};

class fn27B {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5(u32 a, void* b);
};

extern "C" void fn_27_155380(void* unused, u8* p, u8* q) {
    fn27A* a = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    a->v7(*(u32*)(q + 0x4), 0x10000015);
    a = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    a->v7(*(u32*)(q + 0x8), 0x10000016);
    a = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    a->v7(*(u16*)(q + 0x2), 0x10000017);
    fn27B* b = *(fn27B**)(*(u8**)(p + 0xD8) + 0x70);
    b->v5(0xC6, p);
}
