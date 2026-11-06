#pragma force_active on
extern "C" {
struct GlobalObj { void* vtable; };
extern GlobalObj lbl_27_bss_4E4C;
extern char lbl_27_data_317C8[];
extern char lbl_27_bss_4E40[0xC];
void* fn_27_18AE70(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_18AEB0() {
    lbl_27_bss_4E4C.vtable = 0;
    lbl_27_bss_4E4C.vtable = lbl_27_data_317C8;
    __register_global_object(&lbl_27_bss_4E4C, fn_27_18AE70, lbl_27_bss_4E40);
}
}

__declspec(section ".ctors") extern void* const fn_27_18AEB0_ctor = (void*)fn_27_18AEB0;
