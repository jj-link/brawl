#include <types.h>
#pragma force_active on

class fnA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(u32 a, u32 b);
};

class fnB {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3(u32 a, void* b);
};

extern "C" void fn_27_156490(void* unused, u8* src, u8* dst) {
    fnA* a = *(fnA**)(*(u8**)(src + 0xD8) + 0x64);
    a->v5(*(u32*)(dst + 0x4), 0x10000015);
    a = *(fnA**)(*(u8**)(src + 0xD8) + 0x64);
    a->v5(*(u32*)(dst + 0x8), 0x10000016);
    a = *(fnA**)(*(u8**)(src + 0xD8) + 0x64);
    a->v5(*(u16*)(dst + 0x2), 0x10000017);
    fnB* b = *(fnB**)(*(u8**)(src + 0xD8) + 0x70);
    b->w3(0xBF, src);
}
