#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern char lbl_27_data_32978[];
extern GlobalObject lbl_27_bss_502C;
extern char lbl_27_bss_5020[0xC];
void* fn_27_192A90(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_192AD0() {
    lbl_27_bss_502C.vtable = 0;
    lbl_27_bss_502C.vtable = (void*)&lbl_27_data_32978;
    __register_global_object(&lbl_27_bss_502C, (void*)fn_27_192A90, lbl_27_bss_5020);
}
}

__declspec(section ".ctors") extern void* const fn_27_192AD0_ctor = (void*)fn_27_192AD0;
