#pragma force_active on
extern int lbl_80491E90[10];
extern int lbl_80491EB8[10];

int fn_8039DB40(int arg0) {
    int *p = lbl_80491E90;
    int idx;
    int i;
    for (i = 0, idx = 0; i < 10; i++) {
        if (arg0 == *p) {
            return lbl_80491EB8[idx];
        }
        p++;
        idx++;
    }
    return 0;
}
