#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" {
void* fn_27_14948C(int, int kind) {
    if (kind == 0x15) {
        return *(void**)(*(char**)(lbl_27_bss_3210 + 0xfc) + 0x8c);
    }
    return *(void**)(*(char**)(lbl_27_bss_3210 + 0x24c) + 0x90);
}
}
