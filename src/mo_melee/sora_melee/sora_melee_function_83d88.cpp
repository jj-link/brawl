#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct SoStaticObj {
    u8 pad[4];
    s32 f4;
    s16 f8;
    s16 fA;
};

extern "C" void* fn_27_84518(void* p, int n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" s8 lbl_27_bss_1280;
extern "C" SoStaticObj lbl_27_bss_1284;
extern "C" u8 lbl_27_bss_ED8[12];

extern "C" SoStaticObj* fn_27_83D88() {
    if (lbl_27_bss_1280 == 0) {
        lbl_27_bss_1284.f4 = -1;
        lbl_27_bss_1284.f8 = 0;
        lbl_27_bss_1284.fA = -1;
        __register_global_object(&lbl_27_bss_1284, (void*)fn_27_84518, lbl_27_bss_ED8);
        lbl_27_bss_1280 = 1;
    }
    return &lbl_27_bss_1284;
}
