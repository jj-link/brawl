#include <math.h>
#pragma force_active on

extern "C" {
void fn_80171AA0(int, void*, int, int, int, void*, int, int, float, float, float, float, float, float, float, float);
double fn_80400B3C(float, double);
}

extern const float lbl_805A2E98;
extern const float lbl_805A2EA4;
extern const float lbl_805A2EA8;
extern const float lbl_805A2EC0;
extern const float lbl_805A2EC4;
extern const double lbl_805A2EC8;
extern const float lbl_805A2ED0;
extern const float lbl_805A2ED4;
extern const float lbl_805A2ED8;

extern "C" void fn_80171F0C(int arg0, void* arg1, int arg2, int arg3, int arg4, void* arg5, int arg6, int arg7, float farg0)
{
    float* p = (float*)arg5;
    float v31, v30, v29, v28, v27, v8;

    if (arg3 >= 1) {
        v31 = p[0];
        v31 = (float)fabs(v31) > lbl_805A2EC0 ? v31 : lbl_805A2EC0;
        v30 = p[4];
        v30 = (float)fabs(v30) > lbl_805A2EC0 ? v30 : lbl_805A2EC0;
        if (arg4 & 0x02000000) {
            v29 = v31;
        } else {
            v29 = p[5];
            v29 = (float)fabs(v29) > lbl_805A2EC0 ? v29 : lbl_805A2EC0;
        }
        v28 = lbl_805A2EA4;
        if (arg4 & 0x40000) {
            v27 = p[2];
        } else {
            unsigned int* seedp = (unsigned int*)((char*)arg1 + 0xEC);
            unsigned int seed = *seedp * 0x343FD + 0x269EC3;
            *seedp = seed;
            v27 = lbl_805A2EA8 * (lbl_805A2EC4 * ((float)(seed >> 16) / lbl_805A2E98));
        }
        if (arg4 & 0x20000) {
            float v22;
            float t = (float)fn_80400B3C(p[3] - p[2], lbl_805A2EC8);
            if (t < lbl_805A2ED0 || t > lbl_805A2ED4) {
                v22 = (p[3] - p[2]) / (float)*(unsigned short*)((char*)arg1 + 0x32);
            } else {
                v22 = (p[3] - p[2]) / (float)(*(unsigned short*)((char*)arg1 + 0x32) - 1);
            }
            int i;
            for (i = 0; i < arg3; i++) {
                if (arg3 <= 1) {
                    v8 = lbl_805A2EA4;
                } else {
                    v8 = (lbl_805A2EA8) * (v30 * (((float)i / (float)(arg3 - 1)) - (lbl_805A2ED8)));
                }
                fn_80171AA0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, farg0, v31, v30, v29, v28, v22, v27, v8);
            }
            return;
        }
        fn_80171AA0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, farg0, v31, v30, v29, v28, v28, v27, lbl_805A2EA4);
    }
}
