#pragma force_active on

typedef struct Context {
    char pad[0x69C];
    int mode;
    int order;
} Context;

extern Context *lbl_805A1134;
extern int lbl_8059FBC8;
extern double lbl_805A49B8;
extern float lbl_805A49C0;

int fn_80388794(void *, void *, int);
double fn_803888B8(void *, void *, double);
const char *fn_80388738(void *, void *, void *);
int fn_803FCAA8(const char *, const char *);
int strcmp(const char *, const char *);

int fn_803899CC(void *arg0, void *arg1)
{
    void *p;
    int result;
    double diff;
    float fd;
    const char *s0;

    p = (char *)lbl_805A1134 + 0x59C;
    switch (lbl_805A1134->mode) {
    case 0:
        result = fn_80388794(arg0, p, 0) - fn_80388794(arg1, p, 0);
        break;
    case 1:
        diff = fn_803888B8(arg1, p, lbl_805A49B8);
        diff = fn_803888B8(arg0, p, lbl_805A49B8) - diff;
        if (lbl_805A1134->order == 0)
            diff = -diff;
        fd = (float)diff;
        if (fd > lbl_805A49C0)
            return 1;
        return -(fd < lbl_805A49C0);
    case 2:
        s0 = fn_80388738(arg1, p, &lbl_8059FBC8);
        result = strcmp(fn_80388738(arg0, p, &lbl_8059FBC8), s0);
        break;
    case 3:
        s0 = fn_80388738(arg1, p, &lbl_8059FBC8);
        result = fn_803FCAA8(fn_80388738(arg0, p, &lbl_8059FBC8), s0);
        break;
    default:
        return 0;
    }
    if (lbl_805A1134->order == 0)
        result = -result;
    return result;
}
