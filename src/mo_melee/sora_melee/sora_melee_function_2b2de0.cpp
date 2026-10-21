#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct BssLoc {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern BssLoc lbl_27_bss_7130;
extern BssLoc lbl_27_bss_7138;

void fn_27_2B2DE0() {
    lbl_27_bss_7130.unk0 = 0xFF;
    lbl_27_bss_7130.unk4 = 0;
    lbl_27_bss_7138.unk0 = 0xFF;
    lbl_27_bss_7138.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2B2DE0_ctor = (void*)fn_27_2B2DE0;
