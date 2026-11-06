#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4E0C;
extern char lbl_27_bss_4E00[0xC];
extern char lbl_27_data_31580[];
void* fn_27_18A184(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_18A1C4() {
    lbl_27_bss_4E0C.vtable = 0;
    lbl_27_bss_4E0C.vtable = (void*)&lbl_27_data_31580;
    __register_global_object(&lbl_27_bss_4E0C, (void*)fn_27_18A184, lbl_27_bss_4E00);
}
}

__declspec(section ".ctors") extern void* const fn_27_18A1C4_ctor = (void*)fn_27_18A1C4;
