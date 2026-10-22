#pragma force_active on
extern int lbl_804DE330[];
extern char lbl_804DE3F0[];
int fn_801E689C(int, int, int, int, int, int);

void fn_801E6D5C(void *arg0) {
    int *p = (int *)((char *)lbl_804DE330 + ((((int)((char *)arg0 - lbl_804DE3F0)) / 48) << 5));
    if (p[0] != -1) {
        if (fn_801E689C(p[0], p[1], p[2], p[3], p[4], p[5]) != 0) {
            p[0] = -1;
        }
    }
}
