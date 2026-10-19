#pragma force_active on
extern "C" {
struct DestructorChain;
void fn_27_33C514(void*);
void* fn_27_33C524(void*, int);
void* __register_global_object(void*, void*, DestructorChain*);
extern signed char lbl_104_bss_4DC;
extern unsigned char lbl_104_bss_4E0[8];
extern unsigned char lbl_104_bss_4C8[20];
void* fn_104_1B37C();
}

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" void* fn_104_1B37C() {
    if (lbl_104_bss_4DC == 0) {
        fn_27_33C514(lbl_104_bss_4E0);
        __register_global_object(
            lbl_104_bss_4E0,
            (void*)fn_27_33C524,
            (DestructorChain*)lbl_104_bss_4C8
        );
        lbl_104_bss_4DC = 1;
    }
    return lbl_104_bss_4E0;
}
