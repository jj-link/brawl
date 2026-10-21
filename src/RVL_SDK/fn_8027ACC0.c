#pragma force_active on
extern unsigned char lbl_805A0E90[8];

void fn_8027ACC0(int param0, int param1) {
    if (param1 == 0 && param0 < 4) {
        lbl_805A0E90[param0] = 1;
    }
}
