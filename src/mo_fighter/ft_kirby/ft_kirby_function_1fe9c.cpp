#pragma force_active on
struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_27_3312B0(void*);
void fn_27_3312C0(void*, int);
void* __register_global_object(void*, void*, DestructorChain*);

extern signed char lbl_96_bss_FF0;
extern void* lbl_96_bss_FF4;
extern DestructorChain lbl_96_bss_E74;
}

extern "C" void* fn_96_1FE9C() {
    if (lbl_96_bss_FF0 == 0) {
        fn_27_3312B0(&lbl_96_bss_FF4);
        __register_global_object(&lbl_96_bss_FF4, (void*)fn_27_3312C0, &lbl_96_bss_E74);
        lbl_96_bss_FF0 = 1;
    }
    return &lbl_96_bss_FF4;
}
