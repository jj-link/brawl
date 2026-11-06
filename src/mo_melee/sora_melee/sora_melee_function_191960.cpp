#pragma force_active on

extern "C" {
extern char lbl_27_data_32598[];
extern char lbl_27_bss_4FA0[12];
void* fn_27_191920(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4FAC;

extern "C" void fn_27_191960(void) {
    lbl_27_bss_4FAC.vtable = 0;
    lbl_27_bss_4FAC.vtable = (void*)&lbl_27_data_32598;
    __register_global_object((void*)&lbl_27_bss_4FAC, (void*)fn_27_191920, lbl_27_bss_4FA0);
}

__declspec(section ".ctors") extern void* const fn_27_191960_ctor = (void*)fn_27_191960;
