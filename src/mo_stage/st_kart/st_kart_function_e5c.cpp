#pragma force_active on
#include <nw4r/math/math_arithmetic.h>

extern "C" const float lbl_49_rodata_0[];

inline float ClampRange(float value, float lower, float upper) {
    lower = nw4r::math::FSelect(value - lower, value, lower);
    return nw4r::math::FSelect(lower - upper, upper, lower);
}

extern "C" int fn_49_E5C(int, const float* arg) {
    const float* tbl = lbl_49_rodata_0;
    if (arg == 0) {
        return 0x14;
    }
    float x = arg[0];
    float y = arg[1];
    if (y < tbl[4]) {
        return 0x14;
    }
    if (x < tbl[7]) {
        return 0x14;
    }
    if (x > tbl[8] && x < tbl[9]) {
        return 0x14;
    }
    if (x > tbl[10] && x < tbl[11]) {
        return 0x14;
    }
    if (x > tbl[12]) {
        return 0x14;
    }
    if (x >= tbl[7]) {
        if (x <= tbl[13]) {
            if (y <= tbl[14]) {
                return 0x15;
            }
        }
    }
    if (x >= tbl[13]) {
        if (x <= tbl[8]) {
            if (y <= tbl[14]) {
                return 0x15;
            } else {
                float t = (x - tbl[13]) / tbl[15];
                if (y <= tbl[14] + tbl[17] * ClampRange(t, tbl[4], tbl[16])) {
                    return 0x15;
                }
            }
        }
    }
    if (x >= tbl[9]) {
        if (x <= tbl[10]) {
            if (y <= tbl[18]) {
                return 0x15;
            }
        }
    }
    if (x >= tbl[11]) {
        if (x <= tbl[19]) {
            if (y <= tbl[14]) {
                return 0x15;
            } else {
                float t = tbl[16] - (x - tbl[11]) / tbl[15];
                if (y <= tbl[14] + tbl[17] * ClampRange(t, tbl[4], tbl[16])) {
                    return 0x15;
                }
            }
        }
    }
    if (x >= tbl[19]) {
        if (x <= tbl[12]) {
            if (y <= tbl[14]) {
                return 0x15;
            }
        }
    }
    return 0x14;
}
