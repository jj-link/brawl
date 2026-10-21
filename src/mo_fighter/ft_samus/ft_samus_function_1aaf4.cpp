#pragma force_active on
struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_94_1AB3C(void* p);
void* fn_94_1AAB4(void* p, short flags);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
extern int lbl_94_bss_34C;
extern DestructorChain lbl_94_bss_340;
}

extern "C" void fn_94_1AAF4() {
    fn_94_1AB3C(&lbl_94_bss_34C);
    __register_global_object(&lbl_94_bss_34C, (void*)fn_94_1AAB4, &lbl_94_bss_340);
}

__declspec(section ".ctors") extern void* const fn_94_1AAF4_ctor = (void*)fn_94_1AAF4;
