#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_C58[16];

extern "C" int checkDeadArea__12soGroundUtilFP5Vec3fff(void* pos, float radius, float ratio);
extern "C" float fn_27_30FC8(void* self);

extern "C" float fn_27_9A1F4(void* unused_this, void* arg1, unsigned char* out, float farg0) {
    const float* rd = lbl_27_rodata_C58;
    int dead = checkDeadArea__12soGroundUtilFP5Vec3fff(arg1, rd[1], rd[1]);
    float res = fn_27_30FC8(arg1);
    float ret = rd[1];
    switch (dead) {
        case 2:
            if (res > (rd[0] - farg0)) {
                *out = 1;
                ret = rd[9];
            } else if (res < farg0) {
                *out = 1;
                ret = rd[10];
            } else {
                *out = 0;
                ret = rd[11];
            }
            break;
        case 3:
            if (res > (rd[0] - farg0)) {
                *out = 1;
                ret = rd[12];
            } else if (res < farg0) {
                *out = 1;
                ret = rd[13];
            } else {
                *out = 0;
                ret = rd[4];
            }
            break;
        case 0:
            *out = 0;
            ret = rd[0];
            break;
        case 1:
            if (res < farg0) {
                *out = 1;
                ret = rd[14];
            } else if (res > (rd[0] - farg0)) {
                *out = 1;
                ret = rd[15];
            } else {
                *out = 0;
            }
            break;
    }
    return ret;
}
