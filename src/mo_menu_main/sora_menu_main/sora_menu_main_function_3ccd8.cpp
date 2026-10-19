#pragma force_active on
struct Bss58 {
    char pad0[8];
    int f8;
    int fC;
    char pad10[4];
    unsigned char f14;
    char pad15[3];
    int f18;
};

extern "C" {
extern Bss58 lbl_2_bss_58;
extern void* g_GameGlobal;
unsigned char fn_8004EAD4(void*);
}

extern "C" void fn_2_3CCD8() {
    lbl_2_bss_58.f8 = 1;
    lbl_2_bss_58.fC = 0;
    lbl_2_bss_58.f18 = 0;
    lbl_2_bss_58.f14 = fn_8004EAD4(g_GameGlobal);
}
