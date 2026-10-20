#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void* fn_27_149B08(int unused, int kind) {
    switch (kind) {
    case 0x29: {
        char* p = *(char**)(lbl_27_bss_3210 + 0x1ec);
        return *(void**)(p + 0xbc);
    }
    default:
        return 0;
    }
}
