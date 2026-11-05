#pragma force_active on
extern "C" {
extern char lbl_27_bss_49A8[];
extern char lbl_27_data_2EF30[];
extern int lbl_27_bss_4994;
extern char lbl_27_bss_4998[];
void fn_27_16A7C4(void*, int);
void __register_global_object(void*, void*, void*);

struct S {
    void* vtable;
    void* ptr;
};

void fn_27_16A804() {
    (*(S*)&lbl_27_bss_49A8).vtable = 0;
    (*(S*)&lbl_27_bss_49A8).vtable = (void*)lbl_27_data_2EF30;
    (*(S*)&lbl_27_bss_49A8).ptr = &lbl_27_bss_4994;
    __register_global_object(&lbl_27_bss_49A8, (void*)fn_27_16A7C4, lbl_27_bss_4998);
}
}

__declspec(section ".ctors") extern void* const fn_27_16A804_ctor = (void*)fn_27_16A804;
