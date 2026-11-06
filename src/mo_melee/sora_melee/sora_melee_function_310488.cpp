#pragma force_active on

extern "C" {
extern char lbl_27_data_83770[];
extern char lbl_27_bss_7B10[0xC];
void* fn_27_310448(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7B1C;

extern "C" void fn_27_310488(void) {
    lbl_27_bss_7B1C.vtable = 0;
    lbl_27_bss_7B1C.vtable = (void*)&lbl_27_data_83770;
    __register_global_object(&lbl_27_bss_7B1C, (void*)fn_27_310448, lbl_27_bss_7B10);
}

__declspec(section ".ctors") extern void* const fn_27_310488_ctor = (void*)fn_27_310488;
