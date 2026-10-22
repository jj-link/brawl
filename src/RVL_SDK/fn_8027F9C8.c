extern void (*lbl_8059EF44)(void *);

#pragma force_active on
void fn_8027F9C8(void *self, int *out, int offset) {
    int idx;
    int scaled;
    int old_val;
    char *base;

    if (out == 0) return;

    if (offset <= 0x2000) {
        if (offset <= 0x200) {
            idx = *(signed char *)((char *)self + offset + 0xacc);
        } else {
            idx = *(int *)((char *)self + (((offset - 1) >> 10) << 2) + 0xcd0);
        }

        scaled = idx * 4;
        old_val = *(int *)((char *)self + 0x28);
        base = (char *)self + scaled;
        *(int *)((char *)self + 0x28) = old_val - *(int *)(base + 0xa88);
        *(int *)(base + 0xcf0) = *(int *)(base + 0xcf0) - 1;
        *out = *(int *)(base + 0xa44);
        *(int **)(base + 0xa44) = out;
    } else {
        *(int *)((char *)self + 0x14) = *(int *)((char *)self + 0x14) - offset;
        lbl_8059EF44(out);
    }
}
