#pragma force_active on
typedef unsigned int u32;
struct Vec8 { float v[8]; };
extern "C" {
extern Vec8 lbl_80406D68;
extern float lbl_805A1890;
extern float lbl_805A18A0;
u32 fn_80051514(int idx, int val) {
    Vec8 s = lbl_80406D68;
    if (val < 1) val = 1;
    float value = s.v[idx];
    float factor = lbl_805A18A0 * (float)val;
    return (u32)(lbl_805A1890 * (value * factor));
}
}