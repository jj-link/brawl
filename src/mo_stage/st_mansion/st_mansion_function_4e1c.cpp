#pragma force_active on
extern "C" int fn_47_4E1C(void* p)
{
    unsigned int v = *(unsigned int*)((char*)p + 8);
    return ((int)((v << 4) & 0xE0000000u)) >> 30;
}
