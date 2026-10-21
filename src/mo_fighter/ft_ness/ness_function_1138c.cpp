#pragma force_active on
struct NessObject { void* vtable; };
struct NessRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern NessObject lbl_101_bss_1DC;
extern NessRegistration lbl_101_bss_1D0;
NessObject* fn_101_113D4(NessObject*);
void* fn_101_11344(void*, short);
void __register_global_object(void*, void*, void*);

void fn_101_1138C() {
    fn_101_113D4(&lbl_101_bss_1DC);
    __register_global_object(&lbl_101_bss_1DC,
        reinterpret_cast<void*>(fn_101_11344), &lbl_101_bss_1D0);
}
}

__declspec(section ".ctors") extern void* const fn_101_1138C_ctor = (void*)fn_101_1138C;
