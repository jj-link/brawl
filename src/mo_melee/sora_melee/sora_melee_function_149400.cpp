#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_27_bss_3210[];

extern "C" void* fn_27_149400(int unused, int kind) {
    switch (kind) {
    case 3:
        return *(void**)(*(u8**)(lbl_27_bss_3210 + 0x24) + 0x8c);
    default:
        return 0;
    }
}
