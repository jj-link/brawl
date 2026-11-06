#pragma force_active on

extern unsigned int fn_80399AC8(void);

int fn_8039B4C8(void *arg0);

int fn_8039B4C8(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    unsigned int flags = *(unsigned int *)(p + 4);
    unsigned int v;
    unsigned int a;

    if (!(flags & 0x00200000)) {
        return 0;
    }
    if (flags & 0xFE000000) {
        return 0;
    }
    if (*(unsigned int *)(p + 0x18) & 0xFFF80000) {
        return 0;
    }
    if (flags & 2) {
        if (*(int *)(p + 0xC) == 0) {
            return 1;
        }
        v = fn_80399AC8() & 0xFFFFFF00;
        a = *(unsigned int *)(p + 0xC) & 0xFFFFFF00;
        return a == v;
    }
    if ((unsigned int)(fn_80399AC8() + 0xB7BF0000) == 0x4541) {
        return 1;
    }
    if (*(unsigned int *)(p + 4) & 4) {
        return 1;
    }
    v = fn_80399AC8() & 0xFFFFFF00;
    a = *(unsigned int *)(p + 0xC) & 0xFFFFFF00;
    return a == v;
}
