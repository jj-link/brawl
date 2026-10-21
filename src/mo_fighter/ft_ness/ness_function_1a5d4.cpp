#pragma force_active on
struct NessAirRegistrationSlot { void* next; void* object; void* destructor; };

extern "C" {
extern void* lbl_101_bss_3D4;
extern NessAirRegistrationSlot lbl_101_bss_3C8;
void fn_101_1A61C(void** object);
void* fn_101_1A594(void* object, short deleting);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_1A5D4() {
    fn_101_1A61C(&lbl_101_bss_3D4);
    __register_global_object(&lbl_101_bss_3D4,
        reinterpret_cast<void*>(fn_101_1A594), &lbl_101_bss_3C8);
}

__declspec(section ".ctors") extern void* const fn_101_1A5D4_ctor = (void*)fn_101_1A5D4;
