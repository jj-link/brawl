#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" unsigned char lbl_92_bss_1D4[];
extern "C" DestructorChain lbl_92_bss_1C8[];
extern "C" void fn_92_D624(void **);
extern "C" void* fn_92_D59C(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" void fn_92_D5DC(void) {
    fn_92_D624((void**)lbl_92_bss_1D4);
    __register_global_object(lbl_92_bss_1D4, (void*)fn_92_D59C, lbl_92_bss_1C8);
}

__declspec(section ".ctors") extern void* const fn_92_D5DC_ctor = (void*)fn_92_D5DC;
