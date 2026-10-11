extern "C" {
extern char lbl_98_bss_3B4[];
extern char lbl_98_bss_3A8[];
void* fn_98_19118(void*);
void* fn_98_19128(void*, short);
void __register_global_object(void*, void* (*)(void*, short), void*);

void fn_98_190D0() {
    fn_98_19118(lbl_98_bss_3B4);
    __register_global_object(lbl_98_bss_3B4, fn_98_19128, lbl_98_bss_3A8);
}
}
__declspec(section ".ctors") extern void (*const pikachuOwnerInitializer)() = fn_98_190D0;
