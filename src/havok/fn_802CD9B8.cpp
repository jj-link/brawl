#pragma force_active on
extern "C" void fn_802CD9B8(void *src, void *dst) {
    float *s = (float *)((char *)src + 0x10);
    float *d = (float *)dst;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
}
