#pragma force_active on
extern "C" {
void fn_27_13D34C();
void fn_27_358BF8(void*, void*, void*, void*);
extern char lbl_27_bss_8094[];
}

extern "C" void fn_110_9060(void* a, void* b, void* c)
{
    fn_27_13D34C();
    fn_27_358BF8(lbl_27_bss_8094, *(void**)((char*)a + 0x60), b, c);
}
