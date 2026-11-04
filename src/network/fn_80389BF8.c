#pragma force_active on
typedef struct Context { char pad[0x6A0]; int order; } Context;
extern Context *lbl_805A1134;
extern const double lbl_805A49B8;
extern float lbl_805A49C0;
double fn_803888B8(void *, void *, double);
int fn_803899CC(void *, void *);
int fn_80389BF8(const void *arg0, const void *arg1)
{
    void *a = *(void *const *)arg0;
    void *b = *(void *const *)arg1;
    void *p = (char *)lbl_805A1134 + 0x498;
    double diff = fn_803888B8(b, p, lbl_805A49B8);
    float fd;
    diff = fn_803888B8(a, p, lbl_805A49B8) - diff;
    if (!((float)diff > lbl_805A49C0) && !((float)diff < lbl_805A49C0))
        return fn_803899CC(a, b);
    if (lbl_805A1134->order == 0)
        diff = -diff;
    fd = (float)diff;
    if (fd > lbl_805A49C0)
        return 1;
    return -(fd < lbl_805A49C0);
}