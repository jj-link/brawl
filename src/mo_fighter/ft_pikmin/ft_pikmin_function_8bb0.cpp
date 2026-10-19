#pragma force_active on
extern "C" void fn_27_D2FF0(void*, int, int);
extern "C" void fn_27_61454(void*, void*, void*, void*, void*, void*);
extern "C" unsigned char lbl_27_bss_4694[12];
extern "C" unsigned char lbl_27_bss_46AC[4];

extern "C" void* fn_113_8BB0(void* a, void* b, void* c) {
    fn_27_D2FF0(a, 1, 0);
    fn_27_61454((char*)a + 0xAC, b, a, lbl_27_bss_4694, lbl_27_bss_46AC, c);
    return a;
}
