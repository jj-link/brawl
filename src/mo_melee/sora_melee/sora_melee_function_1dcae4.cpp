#pragma force_active on
typedef int s32;

extern "C" float fn_27_8C02C(void* p1, void* p2, s32 p3);

extern "C" const float lbl_27_rodata_27F0;

extern "C" float fn_27_1DCAE4(void* p1, void* p2, s32 p3) {
    if (p3 <= 0xbb7) {
        return fn_27_8C02C(p1, p2, p3);
    }
    return lbl_27_rodata_27F0;
}
