#pragma force_active on
struct Obj {
    int a;
    int b;
    short c;
    short d;
};

struct DestructorChain {
    DestructorChain* next;
    void* dtor;
    void* obj;
};

extern "C" {
    extern signed char lbl_27_bss_1208;
    extern Obj lbl_27_bss_120C;
    extern DestructorChain lbl_27_bss_E9C;
    void* __register_global_object(void* object, void* destructor, void* chain);
    void* fn_27_843D8(void* slot, int destroy);

    void* fn_27_8393C() {
        if (lbl_27_bss_1208 == 0) {
            lbl_27_bss_120C.b = -1;
            lbl_27_bss_120C.c = 0;
            lbl_27_bss_120C.d = -1;
            __register_global_object(&lbl_27_bss_120C, (void*)fn_27_843D8, &lbl_27_bss_E9C);
            lbl_27_bss_1208 = 1;
        }
        return &lbl_27_bss_120C;
    }
}
