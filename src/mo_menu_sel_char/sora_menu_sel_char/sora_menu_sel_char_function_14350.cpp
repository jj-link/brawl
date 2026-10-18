#pragma force_active on
extern "C" {
extern char lbl_10_rodata_648[];
void fn_10_14414(void* a, const void* b, int c, void* d, void* e);
}

extern "C" void fn_10_14350(void* a, void* b, void* c)
{
    fn_10_14414(a, lbl_10_rodata_648, 8, b, c);
}
