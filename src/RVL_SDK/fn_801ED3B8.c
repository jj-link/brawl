#include <revolution/MTX/quat.h>
#include <internal/fdlibm_public.h>
#pragma force_active on

extern double fn_80400B30(double);
extern const float lbl_805A37A0;
extern const float lbl_805A37A4;
extern const float lbl_805A37AC;

void fn_801ED3B8(const Quaternion* a, const Quaternion* b, Quaternion* out, float t)
{
    float dot;
    float coeffa, coeffb;
    float theta, sintheta;

    dot = a->w * b->w + (a->z * b->z + (a->x * b->x + a->y * b->y));
    coeffb = lbl_805A37A0;

    if (dot < lbl_805A37A4) {
        dot = -dot;
        coeffb = -coeffb;
    }
    if (dot <= lbl_805A37AC) {
        theta = (float)fn_80400B30(dot);
        sintheta = (float)sin(theta);
        {
            float omt = lbl_805A37A0 - t;
            coeffa = (float)sin(omt * theta) / sintheta;
        }
        coeffb *= (float)sin(t * theta) / sintheta;
    } else {
        coeffa = lbl_805A37A0 - t;
        coeffb *= t;
    }
    out->x = coeffa * a->x + coeffb * b->x;
    out->y = coeffa * a->y + coeffb * b->y;
    out->z = coeffa * a->z + coeffb * b->z;
    out->w = coeffa * a->w + coeffb * b->w;
}
