#pragma force_active on

struct Nullable {
    void* vtable;
    unsigned char flag;
};

extern "C" {
extern Nullable lbl_27_bss_4A6C;
extern unsigned char lbl_27_bss_4A60[0xC];
extern unsigned char lbl_27_data_2F500[];
void* fn_27_16EB10(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_16EB50() {
    lbl_27_bss_4A6C.vtable = 0;
    lbl_27_bss_4A6C.vtable = lbl_27_data_2F500;
    __register_global_object(&lbl_27_bss_4A6C, (void*)fn_27_16EB10, lbl_27_bss_4A60);
}

__declspec(section ".ctors") extern void* const fn_27_16EB50_ctor = (void*)fn_27_16EB50;
