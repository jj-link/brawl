#pragma force_active on
extern "C" char lbl_118_bss_23C;
extern "C" void fn_27_39A924(void*);
extern "C" void* fn_27_39A934(void*, int);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char lbl_118_bss_228[12];
extern "C" char lbl_118_bss_240[8];

extern "C" void* fn_118_8E00() {
    if (lbl_118_bss_23C == 0) {
        fn_27_39A924(&lbl_118_bss_240);
        __register_global_object(&lbl_118_bss_240, fn_27_39A934, &lbl_118_bss_228);
        lbl_118_bss_23C = 1;
    }
    return &lbl_118_bss_240;
}
