#pragma force_active on

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void fn_95_1100C(void*);
extern "C" void* fn_95_10F84(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);
extern "C" unsigned char lbl_95_bss_3CC;
extern "C" DestructorChain lbl_95_bss_3C0;

extern "C" void fn_95_10FC4(void) {
    fn_95_1100C(&lbl_95_bss_3CC);
    __register_global_object(&lbl_95_bss_3CC, (void*)fn_95_10F84, &lbl_95_bss_3C0);
}

__declspec(section ".ctors") extern void* const fn_95_10FC4_ctor = (void*)fn_95_10FC4;
