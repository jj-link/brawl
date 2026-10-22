#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
extern void *memcpy(void *dst, const void *src, unsigned long n);

void fn_80234CB4(const void *src, int arg1, int arg2) {
    unsigned char *p;

    p = (unsigned char *)fn_8022EE58(0x1C);
    if (p != 0) {
        *(short *)p = 0x200;
        memcpy(p + 8, src, 10);
        *(int *)(p + 0x14) = arg1;
        *(int *)(p + 0x18) = arg2;
        fn_802324E0(p);
    }
}
