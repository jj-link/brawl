#pragma force_active on

extern "C" {
extern char lbl_27_data_31FF0[];
extern char lbl_27_bss_4F30[12];
void fn_27_18FAE0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4F3C;

extern "C" void fn_27_18FB20(void) {
    lbl_27_bss_4F3C.vtable = 0;
    lbl_27_bss_4F3C.vtable = (void*)&lbl_27_data_31FF0;
    __register_global_object(&lbl_27_bss_4F3C, (void*)fn_27_18FAE0, lbl_27_bss_4F30);
}

__declspec(section ".ctors") extern void* const fn_27_18FB20_ctor;

__declspec(section ".ctors") extern void* const fn_27_18FB20_ctor = (void*)fn_27_18FB20;
