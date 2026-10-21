#include <types.h>
#pragma force_active on

struct IF {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32 a, void* b);
    virtual void v4();
    virtual void v5(u32 a, u32 b);
    virtual void v6();
};

extern "C" void fn_27_155FA4(void* unused, void* a1, void* a2) {
    (*(IF**)(*(u8**)((u8*)a1 + 0xd8) + 0x64))->v5(*(u32*)((u8*)a2 + 0x4), 0x10000015);
    (*(IF**)(*(u8**)((u8*)a1 + 0xd8) + 0x64))->v5(*(u32*)((u8*)a2 + 0x8), 0x10000016);
    (*(IF**)(*(u8**)((u8*)a1 + 0xd8) + 0x64))->v5(*(u16*)((u8*)a2 + 0x2), 0x10000017);
    (*(IF**)(*(u8**)((u8*)a1 + 0xd8) + 0x70))->v3(0x92, a1);
}
