#pragma force_active on
extern float lbl_805A3D50;

void fn_80285CCC(float* dst, const float* a, const float* b) {
    float b3;
    float b2;
    float b1;
    float b0;
    float k;
    float a2;
    float a1;
    float a0;

    k = lbl_805A3D50;
    a0 = a[0];
    a1 = a[1];
    a2 = a[2];
    b0 = b[0];
    b1 = b[1];
    b2 = b[2];
    b3 = b[3];

    dst[0] = a0;
    dst[1] = a1;
    dst[2] = a2;
    dst[3] = k;
    dst[4] = a0;
    dst[5] = a1;
    dst[6] = a2;
    dst[7] = k;
    dst[8] = b0;
    dst[9] = b1;
    dst[10] = b2;
    dst[11] = b3;
    dst[12] = b0;
    dst[13] = b1;
    dst[14] = b2;
    dst[15] = b3;
    dst[19] = k;
    dst[18] = k;
    dst[17] = k;
    dst[16] = k;
}
