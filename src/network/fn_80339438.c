#pragma force_active on
#pragma global_optimizer off

extern int fn_80368990(int arg0, int arg1);
extern void *lbl_805A0F80;

int fn_80339438(int arg0)
{
    int *p;
    int ready;

    p = (int *)lbl_805A0F80;
    if (p != 0 && p[1] == 5) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        return 0;
    }
    return fn_80368990(p[0], arg0) == 0;
}
