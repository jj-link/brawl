#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4B0C;
extern char lbl_27_data_2FF08[];
extern char lbl_27_bss_4B00[12];
void* fn_27_178D0C(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_178D4C() {
    lbl_27_bss_4B0C.vtable = 0;
    lbl_27_bss_4B0C.vtable = (void*)&lbl_27_data_2FF08;
    __register_global_object(&lbl_27_bss_4B0C, (void*)fn_27_178D0C, lbl_27_bss_4B00);
}
}

__declspec(section ".ctors") extern void* const fn_27_178D4C_ctor = (void*)fn_27_178D4C;
