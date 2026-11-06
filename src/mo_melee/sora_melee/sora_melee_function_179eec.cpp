#pragma force_active on

extern "C" {
struct SoraObj {
    void* vtable;
};
extern SoraObj lbl_27_bss_4B4C;
extern char lbl_27_bss_4B40[0xC];
extern char lbl_27_data_300E8[];
void* fn_27_179EAC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_179EEC() {
    lbl_27_bss_4B4C.vtable = 0;
    lbl_27_bss_4B4C.vtable = lbl_27_data_300E8;
    __register_global_object(&lbl_27_bss_4B4C, (void*)fn_27_179EAC, lbl_27_bss_4B40);
}
}

__declspec(section ".ctors") extern void* const fn_27_179EEC_ctor = (void*)fn_27_179EEC;
