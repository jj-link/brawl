#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_10EC2C(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    return (s32)((x & 0x003F0000) << 10) >> 27;
}
}
