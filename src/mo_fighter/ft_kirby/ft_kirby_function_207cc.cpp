#pragma force_active on
typedef signed char s8;
typedef int s32;

struct Obj {
    s32 v;
};

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_27_3A59F0(void* p);
void* fn_27_3A5A00(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
}

extern s8 lbl_96_bss_1098;
extern Obj lbl_96_bss_109C;
extern DestructorChain lbl_96_bss_F70;

extern "C" void* fn_96_207CC() {
    if (!lbl_96_bss_1098) {
        fn_27_3A59F0(&lbl_96_bss_109C);
        __register_global_object(&lbl_96_bss_109C, (void*)fn_27_3A5A00, &lbl_96_bss_F70);
        lbl_96_bss_1098 = 1;
    }
    return &lbl_96_bss_109C;
}
