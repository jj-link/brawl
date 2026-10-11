struct NessTransitionProcess { void* vtable; };
struct NessTransitionRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern NessTransitionProcess lbl_101_bss_21C;
extern NessTransitionRegistration lbl_101_bss_210;
extern unsigned char lbl_101_data_8B38[];
NessTransitionProcess* fn_101_11D68(NessTransitionProcess*);
void* fn_101_11CE0(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_11D20() {
    fn_101_11D68(&lbl_101_bss_21C);
    __register_global_object(&lbl_101_bss_21C,
        reinterpret_cast<void*>(fn_101_11CE0), &lbl_101_bss_210);
}

#pragma dont_inline on
extern "C" NessTransitionProcess* fn_101_11D68(NessTransitionProcess* process) {
    process->vtable = lbl_101_data_8B38;
    return process;
}
#pragma dont_inline reset

__declspec(section ".ctors") extern void (*const nessTransitionInitializer)() = fn_101_11D20;
