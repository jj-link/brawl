#pragma force_active on
extern "C" int fn_8005C048(void *arg0) {
    void *ptr = *(void **)((char *)arg0 + 0x18);
    if (ptr == 0) {
        return 0;
    }
    unsigned short a = *(unsigned short *)((char *)ptr + 0x18);
    unsigned short b = *(unsigned short *)((char *)ptr + 0xC);
    return a + b;
}
