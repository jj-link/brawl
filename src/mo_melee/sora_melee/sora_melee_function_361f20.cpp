#pragma force_active on

extern "C" {
extern char lbl_27_data_90910[];
extern char lbl_27_bss_81F8[0xC];
void fn_27_361EE0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8204;

extern "C" void fn_27_361F20(void) {
    lbl_27_bss_8204.vtable = 0;
    lbl_27_bss_8204.vtable = (void*)&lbl_27_data_90910;
    __register_global_object((void*)&lbl_27_bss_8204, (void*)fn_27_361EE0, lbl_27_bss_81F8);
}

__declspec(section ".ctors") extern void* const fn_27_361F20_ctor = (void*)fn_27_361F20;
