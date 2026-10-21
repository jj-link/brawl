#pragma force_active on
struct NessDestructorRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern void* lbl_101_bss_1FC;
extern NessDestructorRegistration lbl_101_bss_1F0;
void fn_101_1169C(void*);
void* fn_101_11614(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_11654() {
    fn_101_1169C(&lbl_101_bss_1FC);
    __register_global_object(&lbl_101_bss_1FC,
        reinterpret_cast<void*>(fn_101_11614), &lbl_101_bss_1F0);
}

__declspec(section ".ctors") extern void* const fn_101_11654_ctor = (void*)fn_101_11654;
