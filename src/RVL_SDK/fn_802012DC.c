#pragma force_active on
void fn_802012DC(int *arg0, int *arg1, short *arg2) {
    int q;

    q = *arg0 / 18;
    if (q != 0) {
        if (q > 20) {
            q = 20;
        }
        if (q < -20) {
            q = -20;
        }
        *arg1 = *arg0;
        *arg0 -= q * 18;
        *arg2 = -q;
        return;
    }
    *arg0 = 0;
    *arg1 = 0;
    *arg2 = 0;
}