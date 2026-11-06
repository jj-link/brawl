#pragma force_active on
extern "C" {

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4F0C;
extern char lbl_27_bss_4F00[12];
extern char lbl_27_data_31E78[0x40];
void fn_27_18EEF0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_18EF30(void) {
    lbl_27_bss_4F0C.vtable = 0;
    lbl_27_bss_4F0C.vtable = &lbl_27_data_31E78;
    __register_global_object(&lbl_27_bss_4F0C, (void*)fn_27_18EEF0, lbl_27_bss_4F00);
}

}

__declspec(section ".ctors") extern void* const fn_27_18EF30_ctor = (void*)fn_27_18EF30;
