#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern char lbl_8045E7E8[];

extern "C" int fn_8014615C(char *base, int idx, char *data, int len) {
    char *s = base + idx * 0x18;
    char *msg = lbl_8045E7E8;
    unsigned int size;
    unsigned int write;

    if (*(int *)(s + 0x4810) != 1) {
        netReport__FPCce(msg + 0x878);
        return 0;
    }

    unsigned int buf = *(unsigned int *)(s + 0x4820);
    if (buf != 0) {
        netReport__FPCce(msg + 0x8A8);
        return 0;
    }

    write = *(unsigned int *)(s + 0x481C);
    size = *(unsigned int *)(s + 0x4814);

    if ((int)(size - write) < len) {
        netReport__FPCce(msg + 0x8D0, idx, size, write + len);
        *(s + 0x480C) = 0;
        *(int *)(s + 0x4810) = 0;
        return 0;
    }

    memcpy((void *)(buf + write), data + 0x20, len);
    *(unsigned int *)(s + 0x481C) += len;

    if ((int)*(unsigned int *)(s + 0x4814) == (int)*(unsigned int *)(s + 0x481C)) {
        *(s + 0x480C) = 0;
        *(int *)(s + 0x4810) = 0;
        netReport__FPCce(msg + 0x918, idx, *(unsigned int *)(s + 0x481C));
    }
    return 1;
}
