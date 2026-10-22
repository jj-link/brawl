#pragma force_active on
extern "C" void fn_801A7970(void **arg0, void *arg1)
{
    if (arg1 == 0) {
        return;
    }
    char *p = (char *)*arg0;
    if (p == 0) {
        return;
    }
    int flags = *(int *)(p + 0x70);
    if (flags & 1) {
        *(int *)arg1 = 0;
        *(float *)((char *)arg1 + 0x4) = *(float *)(p + 0x80);
        *(float *)((char *)arg1 + 0x8) = *(float *)(p + 0x84);
        *(float *)((char *)arg1 + 0xC) = *(float *)(p + 0x88);
        *(float *)((char *)arg1 + 0x10) = *(float *)(p + 0x8C);
        *(float *)((char *)arg1 + 0x14) = *(float *)(p + 0x90);
        *(float *)((char *)arg1 + 0x18) = *(float *)(p + 0x94);
        return;
    }
    if (flags & 2) {
        *(int *)arg1 = 1;
        *(float *)((char *)arg1 + 0x1C) = *(float *)(p + 0x98);
        *(float *)((char *)arg1 + 0x20) = *(float *)(p + 0x9C);
        *(float *)((char *)arg1 + 0x24) = *(float *)(p + 0xA0);
        return;
    }
    *(int *)arg1 = 2;
    *(float *)((char *)arg1 + 0x10) = *(float *)(p + 0x8C);
    *(float *)((char *)arg1 + 0x14) = *(float *)(p + 0x90);
    *(float *)((char *)arg1 + 0x18) = *(float *)(p + 0x94);
    *(float *)((char *)arg1 + 0x28) = *(float *)(p + 0xA4);
}
