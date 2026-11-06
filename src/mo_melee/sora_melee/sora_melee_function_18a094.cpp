#pragma force_active on
extern "C" {
struct SoraMeleeObj {
    void* vtbl;
};
extern SoraMeleeObj lbl_27_bss_4DFC;
extern char lbl_27_bss_4DF0[12];
extern char lbl_27_data_31508[64];
void* fn_27_18A054(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_18A094(void);
}

void fn_27_18A094() {
    lbl_27_bss_4DFC.vtbl = 0;
    lbl_27_bss_4DFC.vtbl = (void*)lbl_27_data_31508;
    __register_global_object((void*)&lbl_27_bss_4DFC, (void*)fn_27_18A054, (void*)lbl_27_bss_4DF0);
}

__declspec(section ".ctors") extern void* const fn_27_18A094_ctor = (void*)fn_27_18A094;
