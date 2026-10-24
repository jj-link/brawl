#pragma force_active on
extern "C" {
int fn_800418D0(float* arg0);
}

extern "C" int fn_80011A64(char* arg0) {
    int local[6];
    int* a = (int*)arg0;
    float* af = (float*)arg0;
    if (fn_800418D0((float*)(arg0 + 0x2c)) != 0) {
        local[0] = a[18];
        local[1] = a[19];
        local[2] = a[20];
        local[3] = a[21];
        local[4] = a[22];
        local[5] = a[23];
        *(float*)&local[0] += af[8];
        *(float*)&local[1] += af[9];
        *(float*)&local[2] += af[8];
        *(float*)&local[3] += af[9];
        *(float*)&local[4] += af[8];
        *(float*)&local[5] += af[9];
    }
    return 0;
}
