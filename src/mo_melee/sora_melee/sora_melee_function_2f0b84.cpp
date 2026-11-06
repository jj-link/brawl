#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_7E9F0[];
extern char lbl_27_bss_7518[12];
extern GlobalBase lbl_27_bss_7524;
void fn_27_2F0B44(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_2F0B84() {
    lbl_27_bss_7524.vtbl = 0;
    lbl_27_bss_7524.vtbl = lbl_27_data_7E9F0;
    __register_global_object(&lbl_27_bss_7524, fn_27_2F0B44, lbl_27_bss_7518);
}

__declspec(section ".ctors") extern void* const fn_27_2F0B84_ctor;
}

__declspec(section ".ctors") extern void* const fn_27_2F0B84_ctor = (void*)fn_27_2F0B84;
