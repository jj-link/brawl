#pragma force_active on
struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
void fn_94_1A418(void* p);
void* fn_94_1A390(void* p, short flag);

extern int lbl_94_bss_31C;
extern DestructorChain lbl_94_bss_310;

void fn_94_1A3D0() {
    fn_94_1A418(&lbl_94_bss_31C);
    __register_global_object(&lbl_94_bss_31C, (void*)fn_94_1A390, &lbl_94_bss_310);
}
}

__declspec(section ".ctors") extern void* const fn_94_1A3D0_ctor = (void*)fn_94_1A3D0;
