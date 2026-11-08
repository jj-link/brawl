#include <math.h>
#pragma force_active on
extern const float lbl_805A1D5C;
extern const float lbl_805A1D48;
extern "C" void fn_80099734(float* output, const float* input) {
    output[12] = cosf(lbl_805A1D5C * input[0]);
    output[13] = cosf(lbl_805A1D5C * input[1]);
    output[14] = lbl_805A1D48;
    output[15] = lbl_805A1D48;
    output[26] = input[4];
    output[27] = input[5];
    output[24] = lbl_805A1D5C * input[6];
    output[25] = lbl_805A1D5C * input[7];
}