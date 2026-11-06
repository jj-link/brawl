#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_514C;
extern char lbl_27_bss_5140[0xC];
extern char lbl_27_data_45EF0[0x40];
void fn_27_1DF194(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DF1D4() {
    lbl_27_bss_514C.vtable = 0;
    lbl_27_bss_514C.vtable = (void*)lbl_27_data_45EF0;
    __register_global_object(&lbl_27_bss_514C, (void*)fn_27_1DF194, (void*)lbl_27_bss_5140);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DF1D4_ctor = (void*)fn_27_1DF1D4;
