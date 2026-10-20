#pragma force_active on
extern "C" int fn_54_5BC8(void* obj)
{
    unsigned int val = *(unsigned int*)((char*)obj + 8);
    return (int)((val >> 25) & 1);
}
