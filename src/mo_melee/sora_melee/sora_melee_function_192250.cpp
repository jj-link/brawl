#pragma force_active on

struct Obj {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern void* __vt__Obj;
extern Obj lbl_27_bss_4FDC;
extern unsigned char lbl_27_bss_4FD0[0xC];
extern unsigned char lbl_27_data_32710[];
void* fn_27_192210(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_192250();
}

void fn_27_192250() {
    lbl_27_bss_4FDC.vtable = &__vt__Obj;
    lbl_27_bss_4FDC.vtable = lbl_27_data_32710;
    __register_global_object(&lbl_27_bss_4FDC, (void*)fn_27_192210, lbl_27_bss_4FD0);
}

__declspec(section ".ctors") extern void* const fn_27_192250_ctor = (void*)fn_27_192250;
