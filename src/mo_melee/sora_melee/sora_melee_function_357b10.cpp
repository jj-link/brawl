#pragma force_active on

extern "C" {
extern char lbl_27_data_8F548[];
extern void fn_27_357AD0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern "C" GlobalObject lbl_27_bss_8074;
extern "C" char lbl_27_bss_8068[0xC];

extern "C" void fn_27_357B10(void) {
    lbl_27_bss_8074.vtable = 0;
    lbl_27_bss_8074.vtable = (void*)lbl_27_data_8F548;
    __register_global_object(&lbl_27_bss_8074, (void*)fn_27_357AD0, lbl_27_bss_8068);
}

__declspec(section ".ctors") extern void* const fn_27_357B10_ctor = (void*)fn_27_357B10;
