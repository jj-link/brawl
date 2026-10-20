#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void* fn_27_147F38(void)
{
    char* p = *(char**)(lbl_27_bss_3210 + 0x228);
    return *(void**)(p + 0x90);
}
