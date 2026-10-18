#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void *__register_global_object(void *, void *, DestructorChain *);
extern "C" void fn_27_25290();

extern "C" {
    extern unsigned char lbl_27_bss_1358[];
    extern unsigned char lbl_27_bss_1360[];
    extern unsigned char lbl_27_bss_F2C[];
}

extern "C" void *fn_27_853A0(void) {
    if ((signed char)lbl_27_bss_1358[0] == 0) {
        __register_global_object(
            lbl_27_bss_1360,
            (void *)fn_27_25290,
            (DestructorChain *)lbl_27_bss_F2C
        );
        lbl_27_bss_1358[0] = 1;
    }
    return lbl_27_bss_1360;
}
