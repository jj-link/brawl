#include <types.h>
#pragma force_active on

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Seg {
    Vec3 a;
    Vec3 b;
};

extern "C" void fn_800685A4(Seg* out, Seg* a, Seg* b, f32* tol);

extern "C" void fn_80067B24(Vec3* arg0, Seg* arg1, Seg* arg2, f32* arg3, s32 arg4) {
    Seg buf[15];

    if (arg4 != 0) {
        s32 idx = -1;
        switch (arg4) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            break;
        case 1:
            fn_800685A4(&buf[0], arg1, arg2, arg3);
            idx = 0;
            break;
        case 3:
            fn_800685A4(&buf[1], arg1, arg2, arg3);
            fn_800685A4(&buf[0], arg1, &buf[1], 0);
            fn_800685A4(&buf[2], &buf[1], arg2, 0);
            idx = 2;
            break;
        case 7:
            fn_800685A4(&buf[3], arg1, arg2, arg3);
            fn_800685A4(&buf[1], arg1, &buf[3], 0);
            fn_800685A4(&buf[0], arg1, &buf[1], 0);
            fn_800685A4(&buf[2], &buf[1], &buf[3], 0);
            fn_800685A4(&buf[5], &buf[3], arg2, 0);
            fn_800685A4(&buf[4], &buf[3], &buf[5], 0);
            fn_800685A4(&buf[6], &buf[5], arg2, 0);
            idx = 6;
            break;
        case 15:
            fn_800685A4(&buf[7], arg1, arg2, arg3);
            fn_800685A4(&buf[3], arg1, &buf[7], 0);
            fn_800685A4(&buf[11], &buf[7], arg2, 0);
            fn_800685A4(&buf[1], arg1, &buf[3], 0);
            fn_800685A4(&buf[0], arg1, &buf[1], 0);
            fn_800685A4(&buf[2], &buf[1], &buf[3], 0);
            fn_800685A4(&buf[5], &buf[3], &buf[7], 0);
            fn_800685A4(&buf[4], &buf[3], &buf[5], 0);
            fn_800685A4(&buf[6], &buf[5], &buf[7], 0);
            fn_800685A4(&buf[13], &buf[11], arg2, 0);
            fn_800685A4(&buf[14], &buf[13], arg2, 0);
            fn_800685A4(&buf[12], &buf[11], &buf[13], 0);
            fn_800685A4(&buf[9], &buf[7], &buf[11], 0);
            fn_800685A4(&buf[8], &buf[7], &buf[9], 0);
            fn_800685A4(&buf[10], &buf[9], &buf[11], 0);
            idx = 14;
            break;
        }

        {
            Seg* src = &buf[idx];
            Vec3* dst = &arg0[idx];
            for (u32 i = idx; (s32)i >= 0; i--) {
                dst->x = src->a.x;
                dst->y = src->a.y;
                dst->z = src->a.z;
                dst--;
                src--;
            }
        }
    }
}
