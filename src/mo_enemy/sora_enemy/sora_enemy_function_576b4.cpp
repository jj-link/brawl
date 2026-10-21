#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32);
};

extern "C" {
void* fn_41_473DC(void*, s32);
void fn_41_47470(void*, void*, void*);
void fn_41_47544(u8*, void*);
void fn_41_47A2C(void*, void*, u32);
void fn_41_47E80(void*, u8, void*, void*, void*);

extern "C" int fn_41_576B4(void* self, void* acc) {
    u32 buf[3];
    u8 flag;
    void* mods = *(void**)((u8*)acc + 0xd8);
    IValueMod* value = *(IValueMod**)((u8*)mods + 0x64);
    void* p = fn_41_473DC(acc, value->getValue(0x10000007));
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47E80(buf, flag, self, p, acc);
    return 0;
}
}
