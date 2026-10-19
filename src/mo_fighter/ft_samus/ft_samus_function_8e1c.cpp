#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
void fn_27_197E44(void *);
void fn_27_197E54(void *, int);
void *__register_global_object(void *, void *, DestructorChain *);

extern unsigned char lbl_94_bss_1B8;
extern unsigned char lbl_94_bss_1BC;
extern DestructorChain lbl_94_bss_1AC;

void *fn_94_8E1C(void) {
    if (*(signed char *)&lbl_94_bss_1B8 == 0) {
        fn_27_197E44(&lbl_94_bss_1BC);
        __register_global_object(
            &lbl_94_bss_1BC,
            (void *)fn_27_197E54,
            &lbl_94_bss_1AC
        );
        lbl_94_bss_1B8 = 1;
    }
    return &lbl_94_bss_1BC;
}
}
