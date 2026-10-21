#pragma force_active on
extern "C" {
extern unsigned char lbl_113_bss_38C[];
extern unsigned char lbl_113_bss_380[];

void fn_113_2DCD4(void*);
void* fn_113_2DC4C(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_113_2DC8C() {
    fn_113_2DCD4(lbl_113_bss_38C);
    __register_global_object(
        lbl_113_bss_38C,
        reinterpret_cast<void*>(fn_113_2DC4C),
        lbl_113_bss_380);
}
}

__declspec(section ".ctors") extern void* const fn_113_2DC8C_ctor = (void*)fn_113_2DC8C;
