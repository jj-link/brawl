#pragma force_active on
extern "C" void fn_27_A7CAC(void* self, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
extern "C" char lbl_41_data_33B0[];

extern "C" void* fn_41_27780(void* p, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    fn_27_A7CAC(p, a2, a3, a4, a5, a6, a7, a8, a9);
    ((void**)p)[0] = lbl_41_data_33B0;
    ((char**)p)[2] = lbl_41_data_33B0 + 0x3c;
    return p;
}
