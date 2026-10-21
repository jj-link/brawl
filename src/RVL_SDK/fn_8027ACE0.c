#pragma force_active on
extern unsigned char lbl_805A0E90[8];

int fn_8027ACE0(int* arg0) {
    int idx = *arg0;
    if (idx >= 4)
        return 0;
    return lbl_805A0E90[idx];
}
