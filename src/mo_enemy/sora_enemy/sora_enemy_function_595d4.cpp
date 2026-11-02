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
s32 fn_41_69C8(void*, void*);
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);
void* getInstance__15emWeaponManagerFv();
void fn_41_2C448(void*, void*);
void fn_27_23317C(void*, void*);
void fn_27_2331A0(void*, void*);
extern u8 lbl_41_bss_504[];
extern void* g_stTriggerMng;

int fn_41_595D4(void* self, void* acc)
{
    u32 buf[3];
    u8 flag;
    void* mods = *(void**)((u8*)acc + 0xd8);
    IValueMod* value = *(IValueMod**)((u8*)mods + 0x64);
    u8* p = (u8*)fn_41_473DC(acc, value->getValue(0x10000007));
    if (*(s32*)(p + 0x74) > 0x10000 - 0x5421) {
        void* r = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc, *(u32*)(p + 0x74), 0);
        *(void**)(lbl_41_bss_504 + 0x28) = r;
        *(s32*)p = fn_41_69C8(r, acc);
    }
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47E80(buf, flag, self, p, acc);
    s32 id = *(s32*)(p + 0x74);
    if (id == 0xABEE) {
        if (g_stTriggerMng != 0) {
            fn_41_2C448(getInstance__15emWeaponManagerFv(), self);
            fn_27_23317C(g_stTriggerMng, *(void**)((u8*)self + 0x34));
        }
    } else if (id == 0xABEF) {
        if (g_stTriggerMng != 0) {
            fn_41_2C448(getInstance__15emWeaponManagerFv(), self);
            fn_27_2331A0(g_stTriggerMng, *(void**)((u8*)self + 0x34));
        }
    }
    return 0;
}
}
