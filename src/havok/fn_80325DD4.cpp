#pragma force_active on
extern "C" void fn_80325DD4(void *src, void *dst) {
    float *s = (float *)((char *)src + 0x20);
    float *d = (float *)dst;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
    d[6] = s[6];
    d[7] = s[7];
    d[8] = s[8];
    d[9] = s[9];
    d[10] = s[10];
    d[11] = s[11];
}
