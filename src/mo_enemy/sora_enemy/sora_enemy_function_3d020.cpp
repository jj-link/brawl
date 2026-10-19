#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32 id);
};

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47A2C(void* p, void* acc, u32 flag);
void fn_41_47D8C(void* out, u32 zero, void* self, void* p, void* acc);
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);
float randf__Fv();
extern u8 lbl_41_bss_504[];
extern float lbl_41_rodata_F00;
}

static IValueMod* getValueMod(void* acc) {
    void* p = *(void**)((u8*)acc + 0xd8);
    return *(IValueMod**)((u8*)p + 0x64);
}

extern "C" s32 fn_41_3D020(void* self, void* acc) {
    u8 buf[0x10];
    void* p = fn_41_473DC(acc, getValueMod(acc)->getValue(0x10000007));
    fn_41_47470(buf, p, acc);
    float f = lbl_41_rodata_F00 * randf__Fv();
    *(float*)(lbl_41_bss_504 + 0x10) = f;
    s32 v = getValueMod(acc)->getValue(0x10000001);
    if (v > 0x10000 - 0x5421) {
        *(void**)(lbl_41_bss_504 + 0x28) = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc, v, 0);
    }
    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, 0, self, p, acc);
    return 0;
}
