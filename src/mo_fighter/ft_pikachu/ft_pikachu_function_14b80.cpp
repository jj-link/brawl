#pragma force_active on
extern "C" {
extern char lbl_98_bss_360[];
extern char lbl_98_bss_364[];
extern char lbl_98_bss_2F0[];
extern char lbl_98_data_856C[];
extern char lbl_98_data_8518[];
void* fn_98_14C44(void*, int);
void __register_global_object(void*, void* (*)(void*, int), void*);

void* fn_98_14B80() {
    if (lbl_98_bss_360[0] == 0) {
        *(int*)(lbl_98_bss_364 + 4) = (int)&lbl_98_data_856C;
        lbl_98_bss_364[0] = 1;
        *(int*)(lbl_98_bss_364 + 4) = (int)&lbl_98_data_8518;
        __register_global_object(lbl_98_bss_364, fn_98_14C44, lbl_98_bss_2F0);
        lbl_98_bss_360[0] = 1;
    }
    return lbl_98_bss_364;
}
}
