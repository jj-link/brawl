#pragma force_active on

struct GlobalBase {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_308C0[];
extern char lbl_27_bss_4C40[0xC];
extern GlobalBase lbl_27_bss_4C4C;
void fn_27_1828B8(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1828F8(void) {
    lbl_27_bss_4C4C.vtable = 0;
    lbl_27_bss_4C4C.vtable = lbl_27_data_308C0;
    __register_global_object(&lbl_27_bss_4C4C, (void*)fn_27_1828B8, lbl_27_bss_4C40);
}
}

__declspec(section ".ctors") extern void* const fn_27_1828F8_ctor = (void*)fn_27_1828F8;
