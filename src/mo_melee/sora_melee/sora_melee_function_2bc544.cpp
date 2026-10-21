#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct BssLoc {
    u32 unk0;
    s32 unk4;
};

extern "C" {
    extern BssLoc lbl_27_bss_7168;
    extern BssLoc lbl_27_bss_7170;
    void fn_27_2BC544(void);
}

void fn_27_2BC544(void) {
    lbl_27_bss_7168.unk0 = 0xFF;
    lbl_27_bss_7168.unk4 = 0;
    lbl_27_bss_7170.unk0 = 0xFF;
    lbl_27_bss_7170.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_2BC544_ctor = (void*)fn_27_2BC544;
