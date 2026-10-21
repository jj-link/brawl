#pragma force_active on
struct MarioCommonGlobalRegistration { void* next; void* object; void* destructor; };
struct MarioCommonGlobalObject { void* vtable; };
extern "C" {
extern MarioCommonGlobalRegistration lbl_91_bss_400;
extern MarioCommonGlobalObject lbl_91_bss_40C;
void* fn_91_194CC(void*);
void* fn_91_19444(void*, short);
void __register_global_object(void*, void*, void*);
void fn_91_19484() {
    fn_91_194CC(&lbl_91_bss_40C);
    __register_global_object(&lbl_91_bss_40C, reinterpret_cast<void*>(fn_91_19444), &lbl_91_bss_400);
}
}

__declspec(section ".ctors") extern void* const fn_91_19484_ctor = (void*)fn_91_19484;
