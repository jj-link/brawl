#pragma force_active on
typedef unsigned int u32;

extern unsigned char lbl_27_bss_3210[];

extern "C" {
u32 fn_27_149B44() {
    u32* p = *(u32**)(lbl_27_bss_3210 + 0x6c);
    return *(u32*)((unsigned char*)p + 0x98);
}
}
