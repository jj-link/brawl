#pragma force_active on
struct FtKoopaObj {
    int m;
};

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_27_197E44(void* self);
void fn_27_197E54(void* self, short flags);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern signed char lbl_102_bss_20C;
extern FtKoopaObj lbl_102_bss_210;
extern DestructorChain lbl_102_bss_1F4;

void* fn_102_7DE0() {
    if (lbl_102_bss_20C == 0) {
        fn_27_197E44(&lbl_102_bss_210);
        __register_global_object(&lbl_102_bss_210, (void*)fn_27_197E54, &lbl_102_bss_1F4);
        lbl_102_bss_20C = 1;
    }
    return &lbl_102_bss_210;
}
}
