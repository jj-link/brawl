#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_11C0;

struct Obj {
    int pad;
    int value;
    short a;
    short b;
};

extern Obj lbl_27_bss_11C4;
extern char lbl_27_bss_E78[];
extern void* fn_27_84318(void*, int);
extern void* __register_global_object(void*, void*, void*);

Obj* fn_27_836A8() {
    if (!lbl_27_bss_11C0) {
        lbl_27_bss_11C4.value = -1;
        lbl_27_bss_11C4.a = 0;
        lbl_27_bss_11C4.b = -1;
        __register_global_object(&lbl_27_bss_11C4, (void*)fn_27_84318, lbl_27_bss_E78);
        lbl_27_bss_11C0 = 1;
    }
    return &lbl_27_bss_11C4;
}
}
