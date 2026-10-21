#pragma force_active on
extern "C" {
struct NessObject {
    void* vtable;
};

struct NessRegistration {
    void* next;
    void* object;
    void* destructor;
};

extern NessObject lbl_101_bss_594;
extern NessRegistration lbl_101_bss_588;
NessObject* fn_101_246A4(NessObject*);
void* fn_101_2461C(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_2465C() {
    fn_101_246A4(&lbl_101_bss_594);
    __register_global_object(&lbl_101_bss_594,
        reinterpret_cast<void*>(fn_101_2461C), &lbl_101_bss_588);
}

__declspec(section ".ctors") extern void* const fn_101_2465C_ctor = (void*)fn_101_2465C;
