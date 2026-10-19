#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
extern signed char lbl_96_bss_1080;
extern unsigned char lbl_96_bss_1084[4];
extern DestructorChain lbl_96_bss_F4C;

void fn_27_3A134C(void *);
void *fn_27_3A135C(void *, int);
void *__register_global_object(void *, void *, DestructorChain *);
}

extern "C" unsigned char *fn_96_2067C(void) {
    if (!lbl_96_bss_1080) {
        fn_27_3A134C(lbl_96_bss_1084);
        __register_global_object(lbl_96_bss_1084,
                                 (void *)fn_27_3A135C,
                                 &lbl_96_bss_F4C);
        lbl_96_bss_1080 = 1;
    }
    return lbl_96_bss_1084;
}
