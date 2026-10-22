#pragma force_active on
void fn_8020B34C(int arg0, int *arg1, int *arg2, int *arg3) {
    *arg1 = 0;
    *arg2 = 0;
    *arg3 = 0;
    if (arg0 & 0x10) {
        *arg1 |= 1;
    }
    if (arg0 & 0x20) {
        *arg1 |= 2;
    }
    if (arg0 & 4) {
        *arg2 |= 1;
    }
    if (arg0 & 8) {
        *arg2 |= 2;
    }
    if (arg0 & 1) {
        *arg3 |= 1;
    }
    if (arg0 & 2) {
        *arg3 |= 2;
    }
}
