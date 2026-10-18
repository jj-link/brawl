#pragma force_active on
extern "C" {
extern int lbl_103_bss_1F4;
void fn_103_106E4(int* a, void* b);

void fn_103_910C(void* p)
{
    fn_103_106E4(&lbl_103_bss_1F4, *(void**)((char*)p + 0x60));
}
}
