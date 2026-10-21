#pragma force_active on

extern "C" {
extern char lbl_41_bss_AC[];
extern char lbl_41_bss_A0[];

void fn_41_21424(void*);
void fn_41_22BE4();
void __register_global_object(void*, void (*)(), void*);

void fn_41_22C40() {
    fn_41_21424(lbl_41_bss_AC);
    __register_global_object(lbl_41_bss_AC, fn_41_22BE4, lbl_41_bss_A0);
}
}

__declspec(section ".ctors") extern void* const fn_41_22C40_ctor = (void*)fn_41_22C40;
