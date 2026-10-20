#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(u32 a, u32 b);
};

extern "C" {
void fn_27_358BF8(void* unused, void* src, void* dst) {
    fn27Obj* obj = *(fn27Obj**)(*(u8**)((u8*)src + 0xD8) + 0x64);
    obj->v7(*(u32*)((u8*)dst + 0x100), 0x10000041);
    obj->v7(*(u32*)((u8*)dst + 0x104), 0x10000042);
}
}
