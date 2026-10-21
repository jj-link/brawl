#pragma force_active on

extern "C" int fn_8005BDA8(void *arg0) {
    void *ptr = *(void **)((char *)arg0 + 0x30);
    if (ptr == 0) {
        return 0;
    }
    unsigned short val1 = *(unsigned short *)((char *)ptr + 0x18);
    unsigned short val2 = *(unsigned short *)((char *)ptr + 0xc);
    return val1 + val2;
}
