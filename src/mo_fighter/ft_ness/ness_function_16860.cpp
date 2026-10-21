#pragma force_active on
struct NessTableHolder { void* vtable; };
struct NessTableRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern NessTableHolder lbl_101_bss_354;
extern NessTableRegistration lbl_101_bss_348;
void fn_101_168A8(NessTableHolder*);
void* fn_101_16820(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_16860() {
    fn_101_168A8(&lbl_101_bss_354);
    __register_global_object(&lbl_101_bss_354,
        reinterpret_cast<void*>(fn_101_16820), &lbl_101_bss_348);
}

__declspec(section ".ctors") extern void* const fn_101_16860_ctor = (void*)fn_101_16860;
