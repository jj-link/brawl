#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

int fn_27_1492A4(void* unused, int kind) {
    switch (kind) {
    case 3:
        return *(int*)(*(int*)(lbl_27_bss_3210 + 0x24) + 0x7c);
    case 5:
        return *(int*)(*(int*)(lbl_27_bss_3210 + 0x3c) + 0x10c);
    }
    return 0;
}
}
