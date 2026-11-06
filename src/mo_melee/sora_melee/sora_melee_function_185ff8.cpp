#pragma force_active on

extern "C" {
extern char lbl_27_data_30D00[];
extern char lbl_27_bss_4CF0[0xC];
void fn_27_185FB8(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4CFC;

extern "C" void fn_27_185FF8() {
    lbl_27_bss_4CFC.vtable = 0;
    lbl_27_bss_4CFC.vtable = (void*)&lbl_27_data_30D00;
    __register_global_object(&lbl_27_bss_4CFC, (void*)fn_27_185FB8, lbl_27_bss_4CF0);
}

__declspec(section ".ctors") extern void* const fn_27_185FF8_ctor = (void*)fn_27_185FF8;
