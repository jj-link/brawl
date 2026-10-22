#pragma force_active on
extern int fn_8037442C(void *, void *, int);

int fn_80377B88(char *a, int *b) {
    unsigned char *base;
    unsigned int h;
    int off;
    h = *(unsigned short *)(a + 0x66);
    base = *(unsigned char **)(a + 0x50);
    off = b[0] + *(int *)(*(char **)(a + 8) + 0x44) + 5;
    base[off++] = h >> 8;
    base[off] = h;
    if (fn_8037442C(a, *(char **)(a + 0x50) + b[0], b[1]) == 0) {
        return 0;
    }
    b[3] = *(int *)(a + 0x88);
    if ((*(signed char **)(a + 0x50))[b[0] + *(int *)(*(char **)(a + 8) + 0x44) + 2] == 2) {
        *(int *)(a + 0x8c) = *(int *)(a + 0x88);
    }
    return 1;
}
