#pragma force_active on
extern float lbl_80532A10[16];

extern "C" {
void fn_802D9668(int a, int b, int c, float *arg3, int d, float *arg5) {
    float *p = lbl_80532A10;
    p[0] = arg3[0];
    p[1] = arg3[1];
    p[2] = arg3[2];
    p[3] = arg3[3];
    p[4] = arg3[4];
    p[5] = arg3[5];
    p[6] = arg3[6];
    p[7] = arg3[7];
    p[8] = arg5[0];
    p[9] = arg5[1];
    p[10] = arg5[2];
    p[11] = arg5[3];
    p[12] = arg5[4];
    p[13] = arg5[5];
    p[14] = arg5[6];
    p[15] = arg5[7];
}
}
