#pragma force_active on
extern "C" void *fn_41_3DBB8(char *base, int idx)
{
    if (idx == 2) {
        return base + 0x6c;
    }
    if (idx == 1) {
        return base + 0x40;
    }
    if (idx == 0) {
        return base + 0x14;
    }
    return 0;
}
