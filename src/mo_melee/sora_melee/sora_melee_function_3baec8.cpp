#pragma force_active on

extern "C" {

extern char lbl_27_data_A1DE0[];
extern char lbl_27_bss_8BE0[0xC];
void fn_27_3BAE88(void*, int);
void __register_global_object(void*, void*, void*);

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8BEC;

void fn_27_3BAEC8(void) {
    lbl_27_bss_8BEC.vtable = 0;
    lbl_27_bss_8BEC.vtable = (void*)&lbl_27_data_A1DE0;
    __register_global_object(&lbl_27_bss_8BEC, (void*)fn_27_3BAE88, lbl_27_bss_8BE0);
}

}

__declspec(section ".ctors") extern void* const fn_27_3BAEC8_ctor = (void*)fn_27_3BAEC8;
