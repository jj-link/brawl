#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_3210[];
}

extern "C" void* fn_27_149644(void)
{
    char* p = *(char**)(lbl_27_bss_3210 + 0x78);
    return *(void**)(p + 0xa0);
}
