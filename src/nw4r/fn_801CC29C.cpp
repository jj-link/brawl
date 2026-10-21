#pragma force_active on
extern "C" {
void fn_801D0180(void*);
void fn_801D0194(void*);
void __register_global_object(void*, void (*)(void*), void*);
extern char lbl_804C2000[];
extern char lbl_804C2010[];
}

extern "C" void fn_801CC29C() {
    fn_801D0180(lbl_804C2010);
    __register_global_object(lbl_804C2010, fn_801D0194, lbl_804C2000);
}

__declspec(section ".ctors") extern void* const fn_801CC29C_ctor = (void*)fn_801CC29C;
