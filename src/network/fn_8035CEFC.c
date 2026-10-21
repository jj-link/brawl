#pragma force_active on
extern int fn_8035C660(int, int*, int, int);

int CanReceiveOnSocket(int p1) {
    int sp8;
    sp8 = 0;
    if (fn_8035C660(p1, &sp8, 0, 0) == 1) {
        return sp8;
    }
    return 0;
}
