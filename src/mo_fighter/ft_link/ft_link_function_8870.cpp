#pragma force_active on
extern "C" {
extern char lbl_93_data_35E8[];

void fn_93_8870(void *r3, int r4, int r5, int r6) {
    int *ptr = (int *)r3;
    ptr[0] = (int)lbl_93_data_35E8;
    ptr[4] = r4;
    ptr[5] = r5;
    ptr[6] = r6;
}
}
