#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" void fn_92_DB18(void** object);
extern "C" void* fn_92_DA90(void* ptr, short flag);
extern "C" void __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern "C" void fn_92_DAD0() {
    extern void* lbl_92_bss_1F4;
    extern DestructorChain lbl_92_bss_1E8;

    fn_92_DB18(&lbl_92_bss_1F4);
    __register_global_object(&lbl_92_bss_1F4, (void*)fn_92_DA90, &lbl_92_bss_1E8);
}

__declspec(section ".ctors") extern void* const fn_92_DAD0_ctor = (void*)fn_92_DAD0;
