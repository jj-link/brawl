#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" void* fn_27_1481E0(void* unused, int type) {
    switch (type) {
    case 0x1d:
        return *(void**)((char*)*(void**)(lbl_27_bss_3210 + 0x15c) + 0x80);
    case 0x5:
        return *(void**)((char*)*(void**)(lbl_27_bss_3210 + 0x3c) + 0xac);
    default:
        return 0;
    }
}
