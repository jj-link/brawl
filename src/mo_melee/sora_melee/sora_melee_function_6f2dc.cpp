#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void fn_27_6F2DC(void* p, u32 mask)
{
    u16* f = (u16*)((char*)p + 0x3c);
    *f = *f & ~mask;
}
