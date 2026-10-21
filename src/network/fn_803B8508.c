#pragma force_active on
extern char lbl_804169B0[];

int fn_803B8508(char *arg0) {
    return *(int *)(lbl_804169B0 + *(int *)(arg0 + 0x1c) * 0x14 + 8);
}
