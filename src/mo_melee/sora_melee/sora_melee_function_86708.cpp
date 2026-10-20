#pragma force_active on
extern "C" void fn_27_9FB70(void*);
extern "C" void fn_27_9FB88(void*, int);
extern "C" void __register_global_object(void*, void*, void*);

typedef struct {
    int unk0;
    int unk4;
    int unk8;
} FnState;

extern char lbl_27_bss_1AD0;
extern FnState lbl_27_bss_1AD4;
extern FnState lbl_27_bss_1070;

extern "C" void* fn_27_86708() {
    if (!lbl_27_bss_1AD0) {
        fn_27_9FB70(&lbl_27_bss_1AD4);
        __register_global_object(&lbl_27_bss_1AD4, &fn_27_9FB88, &lbl_27_bss_1070);
        lbl_27_bss_1AD0 = 1;
    }
    return &lbl_27_bss_1AD4;
}
