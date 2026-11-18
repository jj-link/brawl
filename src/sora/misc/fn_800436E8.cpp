#pragma force_active on

extern "C" int fn_800409D4(int*, void*);

extern "C" int fn_800436E8(const int* shape, void* arg1) {
    int result = 0;
    int a[4], b[4], c[4], d[4];
    int temp_r0, temp_r5, temp_r6, temp_r7;
    int temp_r8, temp_r9, temp_r10, temp_r11;

    temp_r11 = shape[2];
    temp_r10 = shape[3];
    temp_r9 = shape[8];
    temp_r8 = shape[9];
    temp_r7 = shape[4];
    temp_r6 = shape[5];
    temp_r5 = shape[6];
    temp_r0 = shape[7];

    a[0] = temp_r11;
    a[1] = temp_r10;
    a[2] = temp_r9;
    a[3] = temp_r8;
    b[0] = temp_r7;
    b[1] = temp_r6;
    b[2] = temp_r9;
    b[3] = temp_r8;
    c[0] = temp_r7;
    c[1] = temp_r6;
    c[2] = temp_r5;
    c[3] = temp_r0;
    d[0] = temp_r11;
    d[1] = temp_r10;
    d[2] = temp_r5;
    d[3] = temp_r0;

    if (fn_800409D4(a, arg1))
        result |= 1;
    if (fn_800409D4(b, arg1))
        result |= 2;
    if (fn_800409D4(c, arg1))
        result |= 4;
    if (fn_800409D4(d, arg1))
        result |= 8;

    return result;
}
