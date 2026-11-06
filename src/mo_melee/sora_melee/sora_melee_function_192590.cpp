#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_32808[];
extern char lbl_27_bss_4FF0[0xC];
extern GlobalObject lbl_27_bss_4FFC;
void* fn_27_192550(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_192590() {
    lbl_27_bss_4FFC.vtable = 0;
    lbl_27_bss_4FFC.vtable = (void*)&lbl_27_data_32808;
    __register_global_object(&lbl_27_bss_4FFC, (void*)fn_27_192550, lbl_27_bss_4FF0);
}
}

__declspec(section ".ctors") extern void* const fn_27_192590_ctor = (void*)fn_27_192590;
