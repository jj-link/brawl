#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void fn_124_BA20(void **self);
extern "C" void *fn_124_B998(void *p, short size);
extern "C" void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

extern "C" void *lbl_124_bss_22C;
extern "C" DestructorChain lbl_124_bss_220;

extern "C" void fn_124_B9D8()
{
    fn_124_BA20(&lbl_124_bss_22C);
    __register_global_object(&lbl_124_bss_22C, (void *)fn_124_B998, &lbl_124_bss_220);
}

__declspec(section ".ctors") extern void* const fn_124_B9D8_ctor = (void*)fn_124_B9D8;
