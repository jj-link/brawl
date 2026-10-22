#pragma force_active on
extern int lbl_80491E68[10];
extern int lbl_80491E90[10];

int fn_8039DAF8(int arg0) {
    int *p = lbl_80491E90;
    int idx;
    int i;
    for (i = 0, idx = 0; i < 10; i++) {
        if (arg0 == *p) {
            return lbl_80491E68[idx];
        }
        p++;
        idx++;
    }
    return 0;
}
