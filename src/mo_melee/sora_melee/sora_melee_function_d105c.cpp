#pragma force_active on
extern "C" unsigned int fn_27_D105C(void* p)
{
    unsigned int val = *(unsigned int*)((char*)p + 8);
    return (val >> 7) & 1;
}
