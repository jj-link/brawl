#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void fn_95_139CC(void *);
extern "C" void fn_95_13944(void *, short);
extern "C" void *__register_global_object(void *, void *, DestructorChain *);
extern "C" unsigned int lbl_95_bss_42C;
extern "C" DestructorChain lbl_95_bss_420;

extern "C" void fn_95_13984(void) {
    fn_95_139CC(&lbl_95_bss_42C);
    __register_global_object(&lbl_95_bss_42C, (void *)fn_95_13944, &lbl_95_bss_420);
}

__declspec(section ".ctors") extern void* const fn_95_13984_ctor = (void*)fn_95_13984;
