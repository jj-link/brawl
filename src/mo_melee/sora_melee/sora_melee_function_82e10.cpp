#pragma force_active on
extern "C" {

typedef struct {
    void *next;
    void *destructor;
    void *object;
} DestructorChain;

extern char lbl_27_bss_10D0;
extern void __register_global_object(void *, void *, DestructorChain *);
extern void *fn_27_840D8(void *, int);

}

struct GlobalObj {
    short a;
    short b;
    int c;
    short d;
    short e;
};

extern "C" GlobalObj lbl_27_bss_10D4;
extern "C" DestructorChain lbl_27_bss_E00;

extern "C" void *fn_27_82E10(void) {
    if (!lbl_27_bss_10D0) {
        lbl_27_bss_10D4.c = -1;
        lbl_27_bss_10D4.d = 0;
        lbl_27_bss_10D4.e = -1;
        __register_global_object(&lbl_27_bss_10D4, fn_27_840D8, &lbl_27_bss_E00);
        lbl_27_bss_10D0 = 1;
    }
    return &lbl_27_bss_10D4;
}
