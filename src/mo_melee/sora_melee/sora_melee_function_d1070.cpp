#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_27_D1070(void* p)
{
    u32 w = *(u32*)((char*)p + 8);
    u32 r = (w >> 16) | (w << 16);
    return (int)(r & 0xFF800000) >> 24;
}
}
