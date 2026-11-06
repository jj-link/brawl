#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern void* fn_27_35782C(void*, int);
void __register_global_object(void*, void*, void*);
extern char lbl_27_data_8F4D0[0x40];
extern char lbl_27_bss_8058[0xC];
extern GlobalObject lbl_27_bss_8064;

void fn_27_35786C() {
    lbl_27_bss_8064.vtable = 0;
    lbl_27_bss_8064.vtable = (void*)&lbl_27_data_8F4D0;
    __register_global_object(&lbl_27_bss_8064, (void*)fn_27_35782C, lbl_27_bss_8058);
}
}

__declspec(section ".ctors") extern void* const fn_27_35786C_ctor = (void*)fn_27_35786C;
