#pragma force_active on
extern "C" char lbl_25_data_278[];
extern "C" const float lbl_25_rodata_20;

struct SunsetTitleState {
    float v[4];
    char* ptr;
};

extern "C" void fn_25_C30(SunsetTitleState* dst) {
    dst->ptr = lbl_25_data_278;
    float zero = lbl_25_rodata_20;
    dst->v[0] = zero;
    dst->v[1] = zero;
    dst->v[2] = zero;
    dst->v[3] = zero;
}
