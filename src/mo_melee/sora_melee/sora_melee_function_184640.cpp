#pragma force_active on

extern "C" {
extern char lbl_27_data_30B18[];
extern char lbl_27_bss_4C90[0xC];
void* fn_27_184600(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern "C" GlobalObject lbl_27_bss_4C9C;

extern "C" void fn_27_184640(void) {
    lbl_27_bss_4C9C.vtable = 0;
    lbl_27_bss_4C9C.vtable = &lbl_27_data_30B18;
    __register_global_object(&lbl_27_bss_4C9C, (void*)fn_27_184600, lbl_27_bss_4C90);
}

__declspec(section ".ctors") extern void* const fn_27_184640_ctor = (void*)fn_27_184640;
