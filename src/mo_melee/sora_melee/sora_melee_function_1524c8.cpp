#pragma force_active on

struct Nullable {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern void* __vt__10soNullable;
extern Nullable lbl_27_bss_46AC;
extern unsigned char lbl_27_bss_46A0[0xC];
extern unsigned char lbl_27_data_2D950[];
void* fn_27_152488(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_1524C8();
}

void fn_27_1524C8() {
    lbl_27_bss_46AC.vtable = &__vt__10soNullable;
    lbl_27_bss_46AC.vtable = lbl_27_data_2D950;
    __register_global_object(&lbl_27_bss_46AC, (void*)fn_27_152488, lbl_27_bss_46A0);
}

__declspec(section ".ctors") extern void* const fn_27_1524C8_ctor = (void*)fn_27_1524C8;
