#pragma force_active on
extern "C" int fn_49_6C90(void *p)
{
    unsigned v = *(unsigned *)((char *)p + 8);
    return (int)((v << 4) & 0xE0000000u) >> 30;
}
