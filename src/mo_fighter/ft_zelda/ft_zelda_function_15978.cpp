#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
extern unsigned int lbl_104_bss_33C;
extern DestructorChain lbl_104_bss_330;
void fn_104_159C0(void *object);
void *fn_104_15938(void *object, short count);
void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

void fn_104_15978(void) {
    fn_104_159C0(&lbl_104_bss_33C);
    __register_global_object(&lbl_104_bss_33C, (void *)fn_104_15938, &lbl_104_bss_330);
}
}

__declspec(section ".ctors") extern void* const fn_104_15978_ctor = (void*)fn_104_15978;
