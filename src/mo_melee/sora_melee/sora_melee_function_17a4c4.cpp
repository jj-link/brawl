#pragma force_active on

struct GlobalObj {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern GlobalObj lbl_27_bss_4B7C;
extern unsigned char lbl_27_bss_4B70[0xC];
extern char lbl_27_data_30268[];
extern void __register_global_object(void*, void*, void*);
void* fn_27_17A484(void*);
void fn_27_17A4C4(void);
}

void fn_27_17A4C4(void) {
    lbl_27_bss_4B7C.vtable = 0;
    lbl_27_bss_4B7C.vtable = (void*)&lbl_27_data_30268;
    __register_global_object(&lbl_27_bss_4B7C, (void*)fn_27_17A484, lbl_27_bss_4B70);
}

__declspec(section ".ctors") extern void* const fn_27_17A4C4_ctor = (void*)fn_27_17A4C4;
