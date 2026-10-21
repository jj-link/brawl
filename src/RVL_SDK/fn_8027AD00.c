#pragma force_active on
extern unsigned char lbl_805A0E90[8];

void fn_8027AD00(int* param) {
    if (*param >= 4)
        return;
    lbl_805A0E90[*param] = 0;
}
