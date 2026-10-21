#pragma force_active on
struct NessCallbackConstructor {
    void* vtable;
};

struct NessCallbackRegistration {
    void* next;
    void* object;
    void* destructor;
};

extern "C" {
extern NessCallbackConstructor lbl_101_bss_1EC;
extern NessCallbackRegistration lbl_101_bss_1E0;
void* fn_101_1150C(void*);
void* fn_101_11484(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_114C4() {
    fn_101_1150C(&lbl_101_bss_1EC);
    __register_global_object(&lbl_101_bss_1EC,
        reinterpret_cast<void*>(fn_101_11484), &lbl_101_bss_1E0);
}

__declspec(section ".ctors") extern void* const fn_101_114C4_ctor = (void*)fn_101_114C4;
