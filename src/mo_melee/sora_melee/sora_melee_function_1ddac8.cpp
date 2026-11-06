#pragma force_active on
extern "C" {
extern char lbl_27_data_45C20[0x40];
extern char lbl_27_bss_50E0[0xC];
void* fn_27_1DDA88(void*, int);
void* __register_global_object(void*, void*, void*);

struct Obj {
    void* vtable;
    unsigned char flag;
};

extern Obj lbl_27_bss_50EC;

void fn_27_1DDAC8() {
    lbl_27_bss_50EC.vtable = 0;
    lbl_27_bss_50EC.vtable = (void*)&lbl_27_data_45C20;
    __register_global_object(&lbl_27_bss_50EC, (void*)fn_27_1DDA88, lbl_27_bss_50E0);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DDAC8_ctor = (void*)fn_27_1DDAC8;
