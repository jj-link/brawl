#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 fn_1_6424(u8* arg)
{
    u32* p1 = *reinterpret_cast<u32**>(arg + 0x35c);
    u32* p2 = *reinterpret_cast<u32**>(p1);
    return *reinterpret_cast<u32*>(reinterpret_cast<u8*>(p2) + 0x48);
}
