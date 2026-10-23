#pragma force_active on

extern void fn_803D8E00(void *self, int mode);

void fn_803D80B0(int *arg0) {
    *arg0 &= ~4;
    fn_803D8E00(arg0, 0);
}
