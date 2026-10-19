#pragma force_active on
extern "C" {
extern int lbl_96_bss_D20[];

int fn_96_1D7E4(void *self)
{
    int idx = *(int *)((char *)self + 0xb60);
    if (idx <= -1) {
        return 0;
    }
    return lbl_96_bss_D20[idx];
}
}
