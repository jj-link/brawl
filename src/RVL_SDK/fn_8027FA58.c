#pragma force_active on
void fn_8027FA58(unsigned char *arg0, int *arg1, unsigned long arg2) {
    unsigned char *temp_r6;

    temp_r6 = arg0 + (arg2 * 4);
    *(int *)(arg0 + 0x28) = *(int *)(arg0 + 0x28) - *(int *)(temp_r6 + 0xa88);
    *(int *)(temp_r6 + 0xcf0) = *(int *)(temp_r6 + 0xcf0) - 1;
    *arg1 = *(int *)(temp_r6 + 0xa44);
    *(int **)(temp_r6 + 0xa44) = arg1;
}
