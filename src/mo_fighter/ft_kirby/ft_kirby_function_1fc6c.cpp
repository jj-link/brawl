#pragma force_active on

extern "C" void fn_27_31E7BC(int* obj);
extern "C" void* fn_27_31E7CC(void* ptr, int size);

typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern char lbl_96_bss_FC8;
extern int lbl_96_bss_FCC;
extern DestructorChain lbl_96_bss_E38;

extern "C" int* fn_96_1FC6C() {
    if (!lbl_96_bss_FC8) {
        fn_27_31E7BC(&lbl_96_bss_FCC);
        __register_global_object(&lbl_96_bss_FCC, (void*)fn_27_31E7CC, &lbl_96_bss_E38);
        lbl_96_bss_FC8 = 1;
    }
    return &lbl_96_bss_FCC;
}
