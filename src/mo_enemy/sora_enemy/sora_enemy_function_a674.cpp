#include <types.h>
#pragma force_active on

class Vt {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(u32 a, u32 b);
    virtual void s6(s32 a);
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16(s32 a, u32 b);
    virtual u32 s17(u32 a);
    virtual void s18(u32 a);
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25(s32 a, void* b);
};

extern "C" {
extern const float lbl_41_rodata_18;
s32 getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 def);

s32 fn_41_A674(void* self, u32 flag) {
    u8* p = (u8*)self;

    if (lbl_41_rodata_18 == *(f32*)(p + 0xc0)) {
        return 0;
    }
    if (flag & 8) {
        return 0;
    }

    if ((*(Vt**)(*(u8**)(p + 0x1b4) + 0x64))->s17(0x12000001) == 1) {
        s32 v = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(p + 0xdc, 0x59df, 0);
        (*(Vt**)(*(u8**)(p + 0x1b4) + 0x44))->s6(v);

        s32 v2 = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(p + 0xdc, 0x59e0, 0);
        (*(Vt**)(*(u8**)(p + 0x1b4) + 0x60))->s25(v2, p + 0xdc);

        if (getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(p + 0xdc, 0x59ea, 0) == 0) {
            (*(Vt**)(*(u8**)(p + 0x1b4) + 0x64))->s5(0, 0x10000000);
        }
    } else {
        s32 c4 = *(s32*)(p + 0xc4);
        if (c4 > 0) {
            (*(Vt**)(*(u8**)(p + 0x1b4) + 0x44))->s16(c4, 0);
        }
    }

    (*(Vt**)(*(u8**)(p + 0x1b4) + 0x64))->s18(0x12000005);
    return 0;
}
}
