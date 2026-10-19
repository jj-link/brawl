#pragma force_active on
extern "C" {
extern signed char lbl_97_bss_1C4;
extern unsigned char lbl_97_bss_1C8[8];
extern unsigned char lbl_97_bss_1B0[12];
void fn_27_31E7BC(void* obj);
void fn_27_31E7CC(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_97_A3D0() {
    if (!lbl_97_bss_1C4) {
        fn_27_31E7BC(lbl_97_bss_1C8);
        __register_global_object(lbl_97_bss_1C8, (void*)fn_27_31E7CC, lbl_97_bss_1B0);
        lbl_97_bss_1C4 = 1;
    }
    return lbl_97_bss_1C8;
}
