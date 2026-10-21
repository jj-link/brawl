#pragma force_active on
struct NessProcess { void* vtable; };
struct NessProcessRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern NessProcess lbl_101_bss_24C;
extern NessProcessRegistration lbl_101_bss_240;
NessProcess* fn_101_12EA4(NessProcess*);
void* fn_101_12E1C(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_12E5C() {
    fn_101_12EA4(&lbl_101_bss_24C);
    __register_global_object(&lbl_101_bss_24C,
        reinterpret_cast<void*>(fn_101_12E1C), &lbl_101_bss_240);
}

__declspec(section ".ctors") extern void* const fn_101_12E5C_ctor = (void*)fn_101_12E5C;
