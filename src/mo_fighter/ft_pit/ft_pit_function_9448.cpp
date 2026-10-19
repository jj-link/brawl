#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
extern unsigned char lbl_112_bss_18C;
extern unsigned char lbl_112_bss_190[];
extern DestructorChain lbl_112_bss_174;

void fn_27_197E44(void *);
void fn_27_197E54(void *, int);
void *__register_global_object(void *, void *, DestructorChain *);

void *fn_112_9448() {
    if (!*(signed char *)&lbl_112_bss_18C) {
        fn_27_197E44(lbl_112_bss_190);
        __register_global_object(lbl_112_bss_190, (void *)fn_27_197E54, &lbl_112_bss_174);
        lbl_112_bss_18C = 1;
    }
    return lbl_112_bss_190;
}
}
