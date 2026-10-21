#pragma force_active on
extern void *lbl_8059F9A8;

void fn_80378E4C(void *arg0, int arg1) {
    char *p = (char *)arg0;
    if (p == 0) {
        p = (char *)lbl_8059F9A8;
    }
    *(int *)(p + 0xa8) = arg1;
}
