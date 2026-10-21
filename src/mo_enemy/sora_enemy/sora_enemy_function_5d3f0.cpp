#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32 id);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual float getFloat(u32 id);
};

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(u8* out, void* p);
void fn_41_47A2C(void* p, void* acc, u32 flag);
void fn_41_47D8C(void* out, u8 flag, void* self, void* p, void* acc);
}

static IValueMod* getValueMod(void* acc) {
    void* p = *(void**)((u8*)acc + 0xd8);
    return *(IValueMod**)((u8*)p + 0x64);
}

extern "C" s32 fn_41_5D3F0(void* self, void* acc) {
    float buf[4];
    u8 flag;
    void* p = fn_41_473DC(acc, getValueMod(acc)->getValue(0x10000007));
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);

    u32 c = *(u32*)((u8*)p + 0xc);
    if (c == 0 || c == 3) {
        buf[0] = getValueMod(acc)->getFloat(0x1100000A);
        buf[1] = getValueMod(acc)->getFloat(0x1100000B);
    }

    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, flag, self, p, acc);
    return 0;
}
