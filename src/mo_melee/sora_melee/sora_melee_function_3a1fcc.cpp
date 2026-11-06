#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_9C788[];
extern GlobalObject lbl_27_bss_8A24;
extern char lbl_27_bss_8A18[0xC];
void* fn_27_3A1F8C(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3A1FCC(void) {
    lbl_27_bss_8A24.vtable = 0;
    lbl_27_bss_8A24.vtable = (void*)lbl_27_data_9C788;
    __register_global_object(&lbl_27_bss_8A24, (void*)fn_27_3A1F8C, lbl_27_bss_8A18);
}
}

__declspec(section ".ctors") extern void* const fn_27_3A1FCC_ctor = (void*)fn_27_3A1FCC;
