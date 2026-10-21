#pragma force_active on
extern "C" {
extern unsigned char lbl_122_bss_1BC[];
extern unsigned char lbl_122_bss_1B0[];

void fn_122_15338(void*);
void* fn_122_152B0(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_122_152F0() {
    fn_122_15338(lbl_122_bss_1BC);
    __register_global_object(
        lbl_122_bss_1BC,
        reinterpret_cast<void*>(fn_122_152B0),
        lbl_122_bss_1B0
    );
}
}

__declspec(section ".ctors") extern void* const fn_122_152F0_ctor = (void*)fn_122_152F0;
