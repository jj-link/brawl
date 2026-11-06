#pragma force_active on
extern "C" {
struct Obj { void* vtable; };
extern Obj lbl_27_bss_4D6C;
extern char lbl_27_bss_4D60[0xC];
extern char lbl_27_data_31050[];
void* fn_27_187368(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_1873A8();
}
void fn_27_1873A8() {
    lbl_27_bss_4D6C.vtable = 0;
    lbl_27_bss_4D6C.vtable = lbl_27_data_31050;
    __register_global_object(&lbl_27_bss_4D6C, (void*)fn_27_187368, lbl_27_bss_4D60);
}

__declspec(section ".ctors") extern void* const fn_27_1873A8_ctor = (void*)fn_27_1873A8;
