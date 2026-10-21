#pragma force_active on
void fn_8026927C(void *arg0, int arg1, int arg2) {
    ((int *)arg0)[0] = arg1;
    ((int *)arg0)[1] = arg1;
    ((int *)arg0)[2] = 8;
    ((int *)arg0)[4] = arg2;
    ((int *)arg0)[5] = 0;
    *(char *)((char *)arg0 + 0xC) = 0;
}
