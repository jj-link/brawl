#pragma force_active on

extern "C" {
extern char lbl_27_data_7F0C0[];
extern char lbl_27_bss_7538[12];
void* fn_27_2F2674(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7544;

extern "C" void fn_27_2F26B4(void) {
    lbl_27_bss_7544.vtable = 0;
    lbl_27_bss_7544.vtable = (void*)&lbl_27_data_7F0C0;
    __register_global_object(&lbl_27_bss_7544, (void*)fn_27_2F2674, lbl_27_bss_7538);
}

__declspec(section ".ctors") extern void* const fn_27_2F26B4_ctor = (void*)fn_27_2F26B4;
