#pragma force_active on
extern "C" {
void fn_49_422C(void *arg) {
    unsigned char *base = (unsigned char *)arg;
    unsigned char idx = base[0x188];
    void *ptr = *(void **)(base + 0x254);
    unsigned char *dest = (unsigned char *)ptr + idx * 0x34;
    dest[0x2e] = 3;
}
}
