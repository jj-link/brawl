#pragma force_active on
extern "C" {
extern const float lbl_805A4160;
float* fn_802D5FBC(float* src, float* dst) {
float zero = lbl_805A4160;
float value = src[3];
float local[4] __attribute__((aligned(16)));
local[0] = zero;
dst[0] = zero;
dst[1] = zero;
dst[2] = zero;
dst[3] = value;
local[1] = zero;
local[2] = zero;
local[3] = value;
return dst;
}
}