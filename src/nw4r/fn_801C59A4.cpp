#pragma force_active on
extern "C" char* fn_801C59A4(char* base, int idx)
{
    if (idx < 0x10) {
        return base + idx * 2 + 0x98;
    }
    return 0;
}
