#pragma force_active on
#include <ft/ft_common_data_accesser.h>

extern "C" int fn_27_149BD8(int, int*);
extern const float lbl_27_rodata_F10;

struct Vec3 {
    float x, y, z;
};

struct ParamFloats {
    char pad[0x1f8];
    float a;
    float b;
    float c;
    float d;
    float e;
};

extern "C" void fn_27_10ABD8(int unused, int idx, const Vec3* src, float* outB, Vec3* outA, float cond, float scale) {
    int kinds[4];
    fn_27_149BD8(idx, kinds);
    ParamFloats* p = (ParamFloats*)g_ftCommonDataAccesser.getParam((ftKind)kinds[0]);

    float z = src->z;
    float x = src->x;
    float y = src->y + p->a * scale;
    outA->x = x;
    outA->y = y;
    outA->z = z;

    if (lbl_27_rodata_F10 == cond) {
        float c, b, d, e;
        e = p->e;
        d = p->d;
        b = p->b;
        c = p->c;
        outB[0] = c;
        outB[1] = b;
        outB[2] = d;
        outB[3] = e;
    } else {
        float c = -p->c;
        float d;
        float e = p->e;
        float b = -p->b;
        d = p->d;
        outB[1] = c;
        outB[0] = b;
        outB[2] = d;
        outB[3] = e;
    }

    outB[0] = outB[0] * scale;
    outB[1] = outB[1] * scale;
    outB[2] = outB[2] * scale;
    outB[3] = outB[3] * scale;
}
