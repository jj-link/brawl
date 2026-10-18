#include <math.h>
#pragma force_active on

extern "C" {

typedef struct Vec_ {
    float x, y, z;
} Vec;

extern const Vec lbl_102_data_6300[];

void fn_102_F474(const Vec **r3) {
    *r3 = lbl_102_data_6300;
}

} // extern "C"
