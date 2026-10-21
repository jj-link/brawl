#include <types.h>
#pragma force_active on

class fn27A {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(u32 a, u32 b);
};

class fn27B {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3(u32 a, u8* b);
};

extern "C" {
void fn_27_156300(void* unused, u8* p, u8* q) {
    u32 base = 0x10000000;
    fn27A* obj = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    obj->v5(*(u32*)(q + 4), base + 0x15);
    obj = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    obj->v5(*(u32*)(q + 8), base + 0x16);
    obj = *(fn27A**)(*(u8**)(p + 0xD8) + 0x64);
    obj->v5(*(u16*)(q + 2), base + 0x17);
    fn27B* sub = *(fn27B**)(*(u8**)(p + 0xD8) + 0x70);
    sub->w3(0xC0, p);
}
}
