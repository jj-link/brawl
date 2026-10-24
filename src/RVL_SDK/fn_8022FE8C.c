#pragma force_active on
struct Data {
    unsigned char pad[0x28838];
    int begin;
    int end;
    unsigned char gap[0x20];
    int limits0[8];
    int repeats0[8];
    int limits1[8];
    int repeats1[8];
};

extern struct Data lbl_804FD448;
extern int fn_80230500(void);
extern void fn_8023052C(void);
extern int fn_80230508(void);

void fn_8022FE8C(int arg0, int arg1, int arg2)
{
    int repeat;
    int done;
    int idx;
    int limit;
    int avail;

    idx = fn_80230500();
    done = 0;
    if (arg1 <= 0) arg1 = 1;
    repeat = arg1 & ((-arg2 | arg2) >> 31);
    fn_8023052C();
    avail = lbl_804FD448.end - lbl_804FD448.begin;
    if (0x7FFFFFFF - avail > arg1) limit = arg1 + avail;
    else limit = 0x7FFFFFFF;
    switch (arg0) {
    case 0:
        lbl_804FD448.repeats0[(unsigned char)idx] = repeat;
        lbl_804FD448.limits0[(unsigned char)idx] = limit;
        break;
    case 1:
        lbl_804FD448.repeats1[(unsigned char)idx] = repeat;
        lbl_804FD448.limits1[(unsigned char)idx] = limit;
        break;
    default:
        done = 1;
        break;
    }
    if (done == 0 && arg1 > 0) {
        if (lbl_804FD448.end == 0 ||
            (arg1 < lbl_804FD448.begin && lbl_804FD448.begin > 0)) {
            avail = lbl_804FD448.end - lbl_804FD448.begin;
            lbl_804FD448.end = arg1 + avail;
            lbl_804FD448.begin = arg1;
        }
    }
    fn_80230508();
}
