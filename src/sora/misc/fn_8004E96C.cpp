#pragma force_active on
extern "C" int fn_8004E96C(void* p)
{
    unsigned char* n = *(unsigned char**)p;
    return (n[0x8] - 1 - n[0xA]) == 0;
}
