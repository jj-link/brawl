#pragma force_active on

extern "C" {
struct Nullable {
    void* vtable;
    unsigned char flag;
};
extern Nullable lbl_27_bss_4DDC;
extern char lbl_27_bss_4DD0[0xC];
extern char lbl_27_data_31420[0x40];
extern char lbl_27_data_31490[0x40];
void fn_27_189300(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_189340() {
    lbl_27_bss_4DDC.vtable = (void*)lbl_27_data_31490;
    lbl_27_bss_4DDC.vtable = (void*)lbl_27_data_31420;
    __register_global_object(&lbl_27_bss_4DDC, (void*)fn_27_189300, lbl_27_bss_4DD0);
}
}

__declspec(section ".ctors") extern void* const fn_27_189340_ctor = (void*)fn_27_189340;
