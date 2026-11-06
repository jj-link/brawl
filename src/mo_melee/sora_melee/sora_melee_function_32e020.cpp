#pragma force_active on

extern "C" void fn_27_32DFE0(void *, int);
extern "C" void __register_global_object(void *, void *, void *);
extern unsigned char lbl_27_data_887A0[0x40];
extern unsigned char lbl_27_bss_7D48[12];

struct Obj { void *vt; };
extern Obj lbl_27_bss_7D54;

extern "C" void fn_27_32E020() {
    lbl_27_bss_7D54.vt = 0;
    lbl_27_bss_7D54.vt = &lbl_27_data_887A0;
    __register_global_object(&lbl_27_bss_7D54, (void *)fn_27_32DFE0, (void *)lbl_27_bss_7D48);
}

__declspec(section ".ctors") extern void* const fn_27_32E020_ctor = (void*)fn_27_32E020;
