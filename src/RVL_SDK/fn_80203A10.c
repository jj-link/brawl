#pragma force_active on
typedef struct {
    int *src0;      /* 0x00 */
    int *src1;      /* 0x04 */
    int *src2;      /* 0x08 */
    int idx0;       /* 0x0C */
    int idx1;       /* 0x10 */
    int idx2;       /* 0x14 */
    int len0;       /* 0x18 */
    int len1;       /* 0x1C */
    int len2;       /* 0x20 */
    int g0;         /* 0x24 */
    int g1;         /* 0x28 */
    int g2;         /* 0x2C */
    int g3;         /* 0x30 */
    int g4;         /* 0x34 */
    int g5;         /* 0x38 */
    int flag;       /* 0x3C */
} Work;

void fn_80203A10(int **arg0, Work *arg1) {
    int *var_r5;
    int *var_r6;
    int *var_r3;
    int var_ctr;

    if (arg1->flag != 0) {
        arg1->flag = arg1->flag & 0xFFFFFFFD;
        return;
    }
    var_r5 = arg0[0];
    var_r6 = arg0[1];
    var_r3 = arg0[2];
    for (var_ctr = 0; var_ctr < 0x60; var_ctr++) {
        int temp_r28 = (int)arg1->src0;
        int temp_r29 = arg1->idx0 * 4;
        int temp_r0 = *(int *)(temp_r28 + temp_r29);
        int temp_r7 = arg1->src1[arg1->idx1];
        int temp_r8 = arg1->src2[arg1->idx2];
        *(int *)(temp_r28 + temp_r29) = *var_r5 + ((temp_r0 * arg1->g0) >> 7);
        arg1->src1[arg1->idx1] = *var_r6 + ((temp_r7 * arg1->g1) >> 7);
        arg1->src2[arg1->idx2] = *var_r3 + ((temp_r8 * arg1->g2) >> 7);
        arg1->idx0 = arg1->idx0 + 1;
        if ((unsigned)arg1->idx0 >= (unsigned)arg1->len0) {
            arg1->idx0 = 0;
        }
        arg1->idx1 = arg1->idx1 + 1;
        if ((unsigned)arg1->idx1 >= (unsigned)arg1->len1) {
            arg1->idx1 = 0;
        }
        arg1->idx2 = arg1->idx2 + 1;
        if ((unsigned)arg1->idx2 >= (unsigned)arg1->len2) {
            arg1->idx2 = 0;
        }
        *var_r5 = (temp_r0 * arg1->g3) >> 7;
        var_r5 = var_r5 + 1;
        *var_r6 = (temp_r7 * arg1->g4) >> 7;
        var_r6 = var_r6 + 1;
        *var_r3 = (temp_r8 * arg1->g5) >> 7;
        var_r3 = var_r3 + 1;
    }
}
