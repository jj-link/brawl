#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(u32 id);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47D8C(void* out, u8 flag, void* self, void* p, void* acc);
float fn_41_6AD8(void* self, void* acc);
void mtSinCosf__FfPfPf(float, float*, float*);
extern float lbl_41_rodata_EA8;
extern u8 lbl_41_bss_504[];
}

static Object_vptr_0* getMod(void* acc, u32 off) {
    void* p = *(void**)((u8*)acc + 0xd8);
    return *(Object_vptr_0**)((u8*)p + off);
}

#define G(o) (*(float*)(lbl_41_bss_504 + (o)))

extern "C" s32 fn_41_37DDC(void* self, void* acc) {
    float buf[3];
    float sc[3];
    void* p = fn_41_473DC(acc, getMod(acc, 0x64)->slot4(0x10000007));
    fn_41_47470(buf, p, acc);
    mtSinCosf__FfPfPf(lbl_41_rodata_EA8 * fn_41_6AD8((u8*)p + 0x48, acc), &sc[1], &sc[0]);
    float r = fn_41_6AD8((u8*)p + 0x38, acc);
    G(0x18) = sc[0] * r;
    G(0x1c) = sc[1] * r;
    G(0x20) = sc[0] * *(float*)((u8*)p + 0x58);
    G(0x24) = sc[1] * *(float*)((u8*)p + 0x58);
    float m = getMod(acc, 0xc)->slot9();
    G(0x18) *= m;
    G(0x20) *= m;
    fn_41_47D8C(buf, 0, self, p, acc);
    return 0;
}
