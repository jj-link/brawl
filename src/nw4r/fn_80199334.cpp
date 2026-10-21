#pragma force_active on
extern "C" unsigned int fn_80199334(const char *obj, int idx)
{
    const unsigned short *tbl = *(const unsigned short *const *)(obj + 0x14);
    return (tbl[idx] & 0xC000) == 0;
}
