#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void* fn_27_1489A4(void)
{
    char* p = *(char**)(lbl_27_bss_3210 + 0x180);
    return *(void**)(p + 0xB4);
}
