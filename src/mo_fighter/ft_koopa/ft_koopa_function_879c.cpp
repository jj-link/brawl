#pragma force_active on
extern "C" {
extern signed char lbl_102_bss_214;
extern char lbl_102_bss_218[];
extern char lbl_102_bss_200[];
void fn_27_32E298(void* p);
void* fn_27_32E2A8(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* dso);
void* fn_27_32E680(void* a, void* b, void* c);
}

extern "C" void* fn_102_879C(void* a, void* b) {
    if (lbl_102_bss_214 == 0) {
        fn_27_32E298(&lbl_102_bss_218);
        __register_global_object(&lbl_102_bss_218, (void*)fn_27_32E2A8, &lbl_102_bss_200);
        lbl_102_bss_214 = 1;
    }
    return fn_27_32E680(&lbl_102_bss_218, a, b);
}
