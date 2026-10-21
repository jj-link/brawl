#pragma force_active on
typedef unsigned char u8;

struct DestructorChain {
    void* next;
    void* destructor;
    void* object;
};

extern "C" {
extern void* __vt__10soNullable;
extern u8 lbl_27_data_2DAD8[];
extern u8 lbl_27_bss_46D8[];
extern u8 lbl_27_bss_46C8[];
extern void* fn_27_15400C(void*, int);
extern void* __register_global_object(void*, void*, DestructorChain*);

void fn_27_15404C(void) {
    *(void**)lbl_27_bss_46D8 = &__vt__10soNullable;
    lbl_27_bss_46D8[4] = 0;
    *(void**)lbl_27_bss_46D8 = lbl_27_data_2DAD8;
    __register_global_object(
        lbl_27_bss_46D8,
        (void*)fn_27_15400C,
        (DestructorChain*)lbl_27_bss_46C8
    );
}
}

__declspec(section ".ctors") extern void* const fn_27_15404C_ctor = (void*)fn_27_15404C;
