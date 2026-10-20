#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void* fn_27_148EE8() {
    char* base = lbl_27_bss_3210;
    char* p = *(char**)(base + 0x138);
    return *(void**)(p + 0x9c);
}
