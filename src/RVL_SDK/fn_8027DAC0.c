#pragma force_active on
extern void fn_80281D64(int a, int b, int c);

void fn_8027DAC0(void *arg0) {
    int *p = (int *)arg0;
    fn_80281D64(p[0], 0, (p[2] + 1) * 0x10);
    p[1] &= 0x80000000;
}
