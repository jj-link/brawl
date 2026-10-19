#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" {
extern signed char lbl_112_bss_194;
extern unsigned char lbl_112_bss_198[8];
extern DestructorChain lbl_112_bss_180;
void fn_27_35A264(void*);
void* fn_27_35A274(void*, int);
void* __register_global_object(void*, void*, DestructorChain*);
}

extern "C" void* fn_112_A0A4() {
    if (lbl_112_bss_194 == 0) {
        fn_27_35A264(lbl_112_bss_198);
        __register_global_object(lbl_112_bss_198, (void*)fn_27_35A274, &lbl_112_bss_180);
        lbl_112_bss_194 = 1;
    }
    return lbl_112_bss_198;
}
