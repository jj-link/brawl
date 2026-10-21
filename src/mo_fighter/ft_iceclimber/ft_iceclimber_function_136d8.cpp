#pragma force_active on
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" {
extern char lbl_105_bss_28C;
extern char lbl_105_bss_280;

void fn_105_13720(void *);
void *fn_105_13698(void *, short);
void *__register_global_object(void *, void *, DestructorChain *);

void fn_105_136D8(void) {
    fn_105_13720(&lbl_105_bss_28C);
    __register_global_object(&lbl_105_bss_28C, (void *)fn_105_13698,
                             (DestructorChain *)&lbl_105_bss_280);
}
}

__declspec(section ".ctors") extern void* const fn_105_136D8_ctor = (void*)fn_105_136D8;
