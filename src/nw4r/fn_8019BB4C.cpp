#pragma force_active on
extern "C" unsigned int fn_8019BB4C(const void *obj, unsigned int idx)
{
    const unsigned short *tbl = *(const unsigned short *const *)((const char *)obj + 0x14);
    return (tbl[idx] & 0xC000) == 0;
}
