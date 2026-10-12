extern "C" {
extern unsigned char lbl_99_bss_2BC[];
extern unsigned char lbl_99_bss_2B0[];
void* fn_99_10E9C(void*);
void* fn_99_10E14(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_99_10E54() {
    fn_99_10E9C(lbl_99_bss_2BC);
    __register_global_object(lbl_99_bss_2BC,
        reinterpret_cast<void*>(fn_99_10E14), lbl_99_bss_2B0);
}

__declspec(section ".ctors") extern void (*const luigiInitializer10E54)() = fn_99_10E54;
