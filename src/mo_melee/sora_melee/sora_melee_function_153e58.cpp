#pragma force_active on
typedef unsigned int u32;

struct Nullable {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern void* __vt__10soNullable;
extern unsigned char lbl_27_data_2DA78[];
extern Nullable lbl_27_bss_46C0;
extern unsigned char lbl_27_bss_46B0[];
extern void* fn_27_153E18(void*, int);
extern void* __register_global_object(void*, void*, void*);

void fn_27_153E58() {
    lbl_27_bss_46C0.vtable = &__vt__10soNullable;
    lbl_27_bss_46C0.flag = 0;
    lbl_27_bss_46C0.vtable = lbl_27_data_2DA78;
    __register_global_object(&lbl_27_bss_46C0, (void*)fn_27_153E18, lbl_27_bss_46B0);
}
}

__declspec(section ".ctors") extern void* const fn_27_153E58_ctor = (void*)fn_27_153E58;
