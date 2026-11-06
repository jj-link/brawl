#pragma force_active on

extern "C" {

struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_931F0[0x40];
extern GlobalObject lbl_27_bss_83CC;
extern char lbl_27_bss_83C0[0xC];
void* fn_27_373228(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_373268(void) {
    lbl_27_bss_83CC.vtable = 0;
    lbl_27_bss_83CC.vtable = (void*)&lbl_27_data_931F0;
    __register_global_object(&lbl_27_bss_83CC, (void*)fn_27_373228, lbl_27_bss_83C0);
}

}

__declspec(section ".ctors") extern void* const fn_27_373268_ctor = (void*)fn_27_373268;
