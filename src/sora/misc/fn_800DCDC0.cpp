#pragma force_active on

extern "C" unsigned int fn_800DCDC0(const void *obj)
{
    const char *inner = *(const char *const *)((const char *)obj + 0x74);
    return *(const unsigned char *)(inner + 0x115) == 0;
}
