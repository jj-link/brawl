#pragma force_active on
extern "C" {
extern char lbl_27_data_304A8[];
extern void* lbl_27_bss_4BCC;
extern char lbl_27_bss_4BC0[12];
void* fn_27_17B5CC(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_17B60C() {
    lbl_27_bss_4BCC = 0;
    lbl_27_bss_4BCC = lbl_27_data_304A8;
    __register_global_object(&lbl_27_bss_4BCC, (void*)fn_27_17B5CC, lbl_27_bss_4BC0);
}
}

__declspec(section ".ctors") extern void* const fn_27_17B60C_ctor = (void*)fn_27_17B60C;
