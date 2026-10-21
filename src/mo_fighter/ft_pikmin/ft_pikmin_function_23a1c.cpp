#pragma force_active on
extern "C" {
extern char lbl_113_bss_1DC[12];
extern char lbl_113_bss_1D0[12];
void fn_113_23A64(void* self);
void* fn_113_2397C(void* object, short deleting);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_113_23A1C() {
    fn_113_23A64(lbl_113_bss_1DC);
    __register_global_object(lbl_113_bss_1DC, (void*)fn_113_2397C, lbl_113_bss_1D0);
}
}

__declspec(section ".ctors") extern void* const fn_113_23A1C_ctor = (void*)fn_113_23A1C;
