#pragma force_active on
typedef unsigned char u8;

struct SoGlobalObj {
    int a;
    int b;
    short c;
    short d;
};

extern "C" void* fn_27_84458(void* p, int n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" SoGlobalObj lbl_27_bss_123C;
extern "C" signed char lbl_27_bss_1238;
extern "C" SoGlobalObj lbl_27_bss_EB4;

extern "C" void* fn_27_83AF4() {
    if (lbl_27_bss_1238 == 0) {
        lbl_27_bss_123C.b = -1;
        lbl_27_bss_123C.c = 0;
        lbl_27_bss_123C.d = -1;
        __register_global_object(&lbl_27_bss_123C, (void*)fn_27_84458, &lbl_27_bss_EB4);
        lbl_27_bss_1238 = 1;
    }
    return &lbl_27_bss_123C;
}
