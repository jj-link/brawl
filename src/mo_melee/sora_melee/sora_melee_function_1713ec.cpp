#pragma force_active on

struct Nullable {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern void* __vt__10soNullable;
extern Nullable lbl_27_bss_4ABC;
extern unsigned char lbl_27_bss_4AB0[0xC];
extern char lbl_27_data_2F788[];
void* fn_27_1713AC(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_1713EC();
}

void fn_27_1713EC() {
    lbl_27_bss_4ABC.vtable = &__vt__10soNullable;
    lbl_27_bss_4ABC.vtable = lbl_27_data_2F788;
    __register_global_object(&lbl_27_bss_4ABC, (void*)fn_27_1713AC, lbl_27_bss_4AB0);
}

__declspec(section ".ctors") extern void* const fn_27_1713EC_ctor = (void*)fn_27_1713EC;
