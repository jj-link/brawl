#include <types.h>
#pragma force_active on

class ObjA {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(u32 a, u32 b) = 0;
};

class ObjB {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3(u32 a, void* b) = 0;
};

extern "C" void fn_27_1561C4(void* unused, void* arg1, void* arg2) {
    (*(ObjA**)(*(u8**)((u8*)arg1 + 0xd8) + 0x64))->v5(*(u32*)((u8*)arg2 + 0x4), 0x10000015);
    (*(ObjA**)(*(u8**)((u8*)arg1 + 0xd8) + 0x64))->v5(*(u32*)((u8*)arg2 + 0x8), 0x10000016);
    (*(ObjA**)(*(u8**)((u8*)arg1 + 0xd8) + 0x64))->v5(*(u16*)((u8*)arg2 + 0x2), 0x10000017);
    (*(ObjB**)(*(u8**)((u8*)arg1 + 0xd8) + 0x70))->v3(0xC1, arg1);
}
