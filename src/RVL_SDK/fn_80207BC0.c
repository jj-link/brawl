#pragma force_active on
extern int lbl_805A0B60;

void fn_80207BC0(int *arg0) {
    int idx = arg0[6];
    *(int *)(lbl_805A0B60 + idx * 0x70) = 0;
}
