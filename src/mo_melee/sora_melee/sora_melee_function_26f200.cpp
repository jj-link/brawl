#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_43D0[4];

void fn_27_60CDC(void *, void *, void *, float, float, float, float, float, float, float, float);

void fn_27_26F200(void *p0, void *p1, void *p2, void *p3,
                  float f1, float f2, float f3)
{
    const float *p = lbl_27_rodata_43D0 + 1;
    fn_27_60CDC(p1, p2, p3, f1, f2, f3,
                p[-1], p[0], p[0], p[1], p[2]);
}
}
