#include <types.h>
#pragma force_active on
#pragma fp_contract on

extern "C" {
extern float lbl_8059EF50;
extern float lbl_8059EF54;
extern const float lbl_805A3E10;
extern const float lbl_805A3E3C;

struct Work {
    char pad0[0x4];
    float unk4;
    char pad8[0x8];
    float unk10;
};

inline float minf(float a, float b) { return a < b ? a : b; }

float fn_80294804(int arg0, Work* arg1, float farg0, float farg1) {
    float var_f2;
    float var_f3;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f1;
    float var_f1;

    temp_f5 = arg1->unk10;
    temp_f1 = farg0 - temp_f5;
    temp_f4 = -arg1->unk4;
    temp_f4 -= temp_f1;
    temp_f6 = farg1 * lbl_8059EF50;
    var_f2 = temp_f5 * -lbl_8059EF54;
    var_f2 = minf(var_f2, temp_f6);
    var_f3 = temp_f5 + var_f2;
    var_f1 = temp_f1 - var_f2;
    if (temp_f4 > (lbl_805A3E3C * var_f2 + temp_f6)) {
        var_f3 -= temp_f4;
        var_f1 += temp_f4;
    }
    var_f3 = minf(var_f3, lbl_805A3E10);
    arg1->unk10 = var_f3;
    return var_f1;
}
}