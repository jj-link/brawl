#pragma force_active on
extern "C" {
    extern void *__register_global_object(void *object, void *destructor, void *chain);
    extern void *fn_74_57A0(void *p, int n);
}

typedef struct {
    void *next;
    void *destructor;
    void *object;
} DestructorChain;

typedef struct {
    char active;
    char pad[3];
    void *data;
} PlanktonObj;

extern "C" char lbl_74_bss_30;
extern "C" PlanktonObj lbl_74_bss_38;
extern "C" DestructorChain lbl_74_bss_18;
extern "C" char lbl_74_data_13E8[];
extern "C" char lbl_74_data_1390[];

extern "C" void *fn_74_56DC() {
    if (!lbl_74_bss_30) {
        lbl_74_bss_38.data = (void *)lbl_74_data_13E8;
        lbl_74_bss_38.active = 1;
        lbl_74_bss_38.data = (void *)lbl_74_data_1390;
        __register_global_object(&lbl_74_bss_38, fn_74_57A0, &lbl_74_bss_18);
        lbl_74_bss_30 = 1;
    }
    return &lbl_74_bss_38;
}
