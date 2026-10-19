#pragma force_active on
extern "C" {
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern signed char lbl_96_bss_10B0;
extern unsigned char lbl_96_bss_10B4[];
extern unsigned char lbl_96_bss_F94[];

void fn_27_3BB610(void *);
void fn_27_3BB620(void *, int);
void *__register_global_object(void *, void *, DestructorChain *);

void *fn_96_2091C() {
    if (!lbl_96_bss_10B0) {
        fn_27_3BB610(lbl_96_bss_10B4);
        __register_global_object(
            lbl_96_bss_10B4,
            (void *)fn_27_3BB620,
            (DestructorChain *)lbl_96_bss_F94
        );
        lbl_96_bss_10B0 = 1;
    }
    return lbl_96_bss_10B4;
}
}
