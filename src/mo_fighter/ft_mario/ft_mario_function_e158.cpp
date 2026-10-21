#pragma force_active on
struct MarioRegistration { void* next; void* object; void* destructor; };
struct MarioGlobalObject { void* vtable; };
extern "C" {
extern MarioRegistration lbl_91_bss_1D8;
extern MarioGlobalObject lbl_91_bss_1E4;
void fn_91_E1A0(void*);
void fn_91_E110(void*, short);
void __register_global_object(void*, void*, void*);
void fn_91_E158() {
    fn_91_E1A0(&lbl_91_bss_1E4);
    __register_global_object(&lbl_91_bss_1E4, reinterpret_cast<void*>(fn_91_E110), &lbl_91_bss_1D8);
}
}

__declspec(section ".ctors") extern void* const fn_91_E158_ctor = (void*)fn_91_E158;
