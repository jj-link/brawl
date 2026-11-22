#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_8B70;
extern char lbl_27_data_11880[];
extern void* lbl_27_bss_8B74;
extern char lbl_27_bss_8B64[];

void* fn_27_827D4(void* p, short n);
void __register_global_object(void*, void*, void*);
void fn_27_B4698(void*, void*, void*, void*, void*, void*);

void* fn_27_3B0274(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4) {
    if (lbl_27_bss_8B70 == 0) {
        lbl_27_bss_8B74 = 0;
        lbl_27_bss_8B74 = lbl_27_data_11880;
        __register_global_object(&lbl_27_bss_8B74, (void*)fn_27_827D4, lbl_27_bss_8B64);
        lbl_27_bss_8B70 = 1;
    }
    fn_27_B4698((char*)arg0 + 4, arg1, &lbl_27_bss_8B74, arg2, arg3, arg4);
    return arg0;
}
}
