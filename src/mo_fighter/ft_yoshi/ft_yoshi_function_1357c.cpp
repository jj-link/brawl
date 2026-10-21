#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
extern void *fn_95_135C4(void *);
extern void *fn_95_1353C(void *, short);
extern void *__register_global_object(void *, void *, DestructorChain *);
extern DestructorChain lbl_95_bss_400;
extern unsigned char lbl_95_bss_40C[];

void fn_95_1357C(void) {
    fn_95_135C4(lbl_95_bss_40C);
    __register_global_object(lbl_95_bss_40C, (void *)fn_95_1353C, &lbl_95_bss_400);
}
}

__declspec(section ".ctors") extern void* const fn_95_1357C_ctor = (void*)fn_95_1357C;
