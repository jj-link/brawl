#pragma force_active on

extern "C" {
extern char lbl_27_data_31EF0[];
extern char lbl_27_bss_4F10[12];
void fn_27_18F658(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4F1C;

extern "C" void fn_27_18F698(void) {
    lbl_27_bss_4F1C.vtable = 0;
    lbl_27_bss_4F1C.vtable = (void*)&lbl_27_data_31EF0;
    __register_global_object(&lbl_27_bss_4F1C, (void*)fn_27_18F658, lbl_27_bss_4F10);
}

__declspec(section ".ctors") extern void* const fn_27_18F698_ctor = (void*)fn_27_18F698;
