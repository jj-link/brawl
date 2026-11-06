#pragma force_active on

extern "C" {
extern char lbl_27_data_45F68[];
extern char lbl_27_bss_5150[0xC];
void fn_27_1DF440(void*, int);
void __register_global_object(void* object, void* destructor, void* chain);

struct SoraMeleeGlobal {
    void* vtbl;
};

extern SoraMeleeGlobal lbl_27_bss_515C;

void fn_27_1DF480(void) {
    lbl_27_bss_515C.vtbl = 0;
    lbl_27_bss_515C.vtbl = (void*)&lbl_27_data_45F68;
    __register_global_object(&lbl_27_bss_515C, (void*)fn_27_1DF440, lbl_27_bss_5150);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DF480_ctor = (void*)fn_27_1DF480;
