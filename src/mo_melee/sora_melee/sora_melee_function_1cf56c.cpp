#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_27_1CF56C(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    return (int)((x << 3) & 0xF0000000u) >> 29;
}
}
