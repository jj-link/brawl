#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
extern unsigned char lbl_124_bss_23C[];
extern unsigned char lbl_124_bss_230[];
extern void fn_124_BC40(void *);
extern void *fn_124_BBB8(void *, short);
extern void *__register_global_object(void *, void *, DestructorChain *);

void fn_124_BBF8(void) {
    fn_124_BC40(lbl_124_bss_23C);
    __register_global_object(lbl_124_bss_23C, (void *)fn_124_BBB8,
                             (DestructorChain *)lbl_124_bss_230);
}
}

__declspec(section ".ctors") extern void* const fn_124_BBF8_ctor = (void*)fn_124_BBF8;
