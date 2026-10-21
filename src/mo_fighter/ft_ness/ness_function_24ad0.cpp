#pragma force_active on
extern "C" {
extern unsigned char lbl_101_bss_5A4[];
extern unsigned char lbl_101_bss_598[];
void fn_101_24B18(void* ptr);
void* fn_101_24A90(void* object, short deleting);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_24AD0() {
    fn_101_24B18(lbl_101_bss_5A4);
    __register_global_object(lbl_101_bss_5A4,
        reinterpret_cast<void*>(fn_101_24A90), lbl_101_bss_598);
}

__declspec(section ".ctors") extern void* const fn_101_24AD0_ctor = (void*)fn_101_24AD0;
