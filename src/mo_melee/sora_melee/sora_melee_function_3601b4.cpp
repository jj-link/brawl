#pragma force_active on
extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void fn_27_360230(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" char lbl_27_data_90570[];

struct SoObj {
    char* a;
    int b;
    char* c;
};

extern "C" SoObj lbl_27_bss_8188;
extern "C" char lbl_27_bss_817C[0xC];

extern "C" {
    void fn_27_3601B4() {
        fn_27_1E82E8(&lbl_27_bss_8188, 0);
        lbl_27_bss_8188.c = lbl_27_data_90570;
        lbl_27_bss_8188.a = lbl_27_data_90570 + 8;
        fn_27_1E847C(&lbl_27_bss_8188, 0x5b, &lbl_27_bss_8188);
        __register_global_object(&lbl_27_bss_8188, fn_27_360230, lbl_27_bss_817C);
    }
}

__declspec(section ".ctors") extern void* const fn_27_3601B4_ctor = (void*)fn_27_3601B4;
