#pragma force_active on
#pragma fp_contract on
extern float lbl_80532A10[16];
extern float lbl_805A4200;
extern "C" void fn_802D96F4(float* a, void*, void*, float* b, void*, float* c) {
    float s;
    float t = a[3];
    s = lbl_805A4200;
    s -= t;
    b[0] = s * lbl_80532A10[0] + t * b[0];
    b[1] = s * lbl_80532A10[1] + t * b[1];
    b[2] = s * lbl_80532A10[2] + t * b[2];
    b[3] = s * lbl_80532A10[3] + t * b[3];
    b[4] = s * lbl_80532A10[4] + t * b[4];
    b[5] = s * lbl_80532A10[5] + t * b[5];
    b[6] = s * lbl_80532A10[6] + t * b[6];
    b[7] = s * lbl_80532A10[7] + t * b[7];
    c[0] = s * lbl_80532A10[8] + t * c[0];
    c[1] = s * lbl_80532A10[9] + t * c[1];
    c[2] = s * lbl_80532A10[10] + t * c[2];
    c[3] = s * lbl_80532A10[11] + t * c[3];
    c[4] = s * lbl_80532A10[12] + t * c[4];
    c[5] = s * lbl_80532A10[13] + t * c[5];
    c[6] = s * lbl_80532A10[14] + t * c[6];
    c[7] = s * lbl_80532A10[15] + t * c[7];
}