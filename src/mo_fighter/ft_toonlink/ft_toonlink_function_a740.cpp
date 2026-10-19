#pragma force_active on

typedef signed char s8;
typedef int s32;

struct Obj {
    s32 v0;
    s32 v1;
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

extern s8 lbl_121_bss_134;
extern Obj lbl_121_bss_138;
extern DestructorChain lbl_121_bss_120;
}

extern "C" void* fn_121_A740() {
    if (!lbl_121_bss_134) {
        fn_27_3A59F0(&lbl_121_bss_138);
        __register_global_object(&lbl_121_bss_138, (void*)fn_27_3A5A00, &lbl_121_bss_120);
        lbl_121_bss_134 = 1;
    }
    return &lbl_121_bss_138;
}
