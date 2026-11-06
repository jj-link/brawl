#pragma force_active on

extern "C" {

struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_99060[];
extern char lbl_27_bss_87F0[0xC];
extern GlobalObject lbl_27_bss_87FC;
void* fn_27_386D98(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_386DD8(void) {
    lbl_27_bss_87FC.vtable = 0;
    lbl_27_bss_87FC.vtable = (void*)&lbl_27_data_99060;
    __register_global_object(&lbl_27_bss_87FC, (void*)fn_27_386D98, lbl_27_bss_87F0);
}

}

__declspec(section ".ctors") extern void* const fn_27_386DD8_ctor = (void*)fn_27_386DD8;
