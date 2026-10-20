#pragma force_active on
typedef struct FnState {
    int unk0;
    int unk4;
    int unk8;
} FnState;

extern "C" {
extern signed char lbl_27_bss_1AE0;
extern FnState lbl_27_bss_1AE4;
extern char lbl_27_bss_107C[];
void fn_27_9FB70(FnState* p);
void* fn_27_9FB88(void* ptr, int size);
void __register_global_object(void* obj, void* dtor, void* regmem);

FnState* fn_27_86778() {
    if (!lbl_27_bss_1AE0) {
        fn_27_9FB70(&lbl_27_bss_1AE4);
        __register_global_object(&lbl_27_bss_1AE4, (void*)fn_27_9FB88, lbl_27_bss_107C);
        lbl_27_bss_1AE0 = 1;
    }
    return &lbl_27_bss_1AE4;
}
}
