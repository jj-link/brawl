#pragma force_active on

struct Wrapper {
    void *vptr;
};

struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" Wrapper lbl_107_bss_15C;
extern "C" DestructorChain lbl_107_bss_150;
extern "C" void fn_107_11E84(Wrapper *object);
extern "C" void *fn_107_11DF4(void *ptr, short count);
extern "C" void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

extern "C" void fn_107_11E3C()
{
    fn_107_11E84(&lbl_107_bss_15C);
    __register_global_object(&lbl_107_bss_15C, (void *)fn_107_11DF4, &lbl_107_bss_150);
}

__declspec(section ".ctors") extern void* const fn_107_11E3C_ctor = (void*)fn_107_11E3C;
