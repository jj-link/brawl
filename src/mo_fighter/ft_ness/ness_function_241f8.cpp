#pragma force_active on
struct NessProcess {
    void* vtable;
};

struct NessProcessRegistration {
    void* next;
    void* object;
    void* destructor;
};

extern "C" {
extern NessProcess lbl_101_bss_584;
extern NessProcessRegistration lbl_101_bss_578;

NessProcess* fn_101_24240(NessProcess*);
void* fn_101_241B8(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_241F8() {
    fn_101_24240(&lbl_101_bss_584);
    __register_global_object(
        &lbl_101_bss_584,
        reinterpret_cast<void*>(fn_101_241B8),
        &lbl_101_bss_578);
}

__declspec(section ".ctors") extern void* const fn_101_241F8_ctor = (void*)fn_101_241F8;
