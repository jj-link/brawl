#pragma force_active on

extern "C" {
extern char lbl_27_data_7DC48[];
extern char lbl_27_bss_74D8[0xC];
void fn_27_2EBDE4(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_74E4;

extern "C" void fn_27_2EBE24(void) {
    lbl_27_bss_74E4.vtable = 0;
    lbl_27_bss_74E4.vtable = (void*)&lbl_27_data_7DC48;
    __register_global_object(&lbl_27_bss_74E4, (void*)fn_27_2EBDE4, lbl_27_bss_74D8);
}

__declspec(section ".ctors") extern void* const fn_27_2EBE24_ctor = (void*)fn_27_2EBE24;
