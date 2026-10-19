#pragma force_active on
extern "C" char lbl_27_bss_3210[];

extern "C" {
void* fn_27_1482C0(void* p1, int p2);
}

void* fn_27_1482C0(void* p1, int p2) {
    switch (p2) {
    case 0x1E:
        return *(void**)(*(char**)(lbl_27_bss_3210 + 0x168) + 0x90);
    case 0x5:
        return *(void**)(*(char**)(lbl_27_bss_3210 + 0x3c) + 0x158);
    default:
        return 0;
    }
}
