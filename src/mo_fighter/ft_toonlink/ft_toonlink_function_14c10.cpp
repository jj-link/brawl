#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
    void *__register_global_object(void *object, void *destructor, DestructorChain *chain);
    void fn_121_14C58(void *p);
    void *fn_121_14BD0(void *ptr, short count);
    extern char lbl_121_bss_274[];
    extern DestructorChain lbl_121_bss_268;
}

extern "C" void fn_121_14C10() {
    fn_121_14C58(lbl_121_bss_274);
    __register_global_object(lbl_121_bss_274, (void *)fn_121_14BD0, &lbl_121_bss_268);
}

__declspec(section ".ctors") extern void* const fn_121_14C10_ctor = (void*)fn_121_14C10;
