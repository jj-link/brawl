#pragma force_active on
extern "C" {
extern void* lbl_107_bss_20C;
extern void* lbl_107_bss_200;
void fn_107_13964(void**);
void* fn_107_138DC(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_107_1391C() {
    fn_107_13964(&lbl_107_bss_20C);
    __register_global_object(
        &lbl_107_bss_20C,
        (void*)fn_107_138DC,
        &lbl_107_bss_200
    );
}

__declspec(section ".ctors") extern void* const fn_107_1391C_ctor = (void*)fn_107_1391C;
