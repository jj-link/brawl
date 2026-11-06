#pragma force_active on

extern "C" {
extern char lbl_27_data_45D10[];
extern unsigned char lbl_27_bss_5100[12];
void fn_27_1DDEE0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_510C;

extern "C" void fn_27_1DDF20(void) {
    lbl_27_bss_510C.vtable = 0;
    lbl_27_bss_510C.vtable = (void*)&lbl_27_data_45D10;
    __register_global_object(&lbl_27_bss_510C, (void*)fn_27_1DDEE0, lbl_27_bss_5100);
}

__declspec(section ".ctors") extern void* const fn_27_1DDF20_ctor = (void*)fn_27_1DDF20;
