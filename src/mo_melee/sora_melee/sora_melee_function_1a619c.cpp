#pragma force_active on
extern "C" {
int fn_27_1A619C(void* p)
{
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return ((int)((x << 20) & 0xFFE00000u)) >> 22;
}
}
