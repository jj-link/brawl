#pragma force_active on
extern "C" {
void fn_27_D2FF0(void* self, int a, int b);
void* fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);
extern char lbl_27_bss_4694[];
extern char lbl_27_bss_46AC[];
}

extern "C" void* fn_102_6C64(void* r3, void* r4, void* r5)
{
    fn_27_D2FF0(r3, 1, 0);
    fn_27_61454((char*)r3 + 0xAC, r4, r3, lbl_27_bss_4694, lbl_27_bss_46AC, r5);
    return r3;
}
