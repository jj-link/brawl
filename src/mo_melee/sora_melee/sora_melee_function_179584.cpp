#pragma force_active on

struct Nullable {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern void* __vt__12ftStatusUniqProc;
extern Nullable lbl_27_bss_4B3C;
extern unsigned char lbl_27_bss_4B30[0xC];
extern unsigned char lbl_27_data_30068[];
void fn_27_179544(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_179584();
}

void fn_27_179584() {
    lbl_27_bss_4B3C.vtable = &__vt__12ftStatusUniqProc;
    lbl_27_bss_4B3C.vtable = lbl_27_data_30068;
    __register_global_object(&lbl_27_bss_4B3C, (void*)fn_27_179544, lbl_27_bss_4B30);
}

__declspec(section ".ctors") extern void* const fn_27_179584_ctor = (void*)fn_27_179584;
