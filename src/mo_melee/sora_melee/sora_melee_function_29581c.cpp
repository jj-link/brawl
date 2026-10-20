#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_27_29581C(void* p)
{
    u32 value = *reinterpret_cast<u32*>(static_cast<char*>(p) + 8);
    value = (value << 12) & 0xFE000000;
    return static_cast<int>(value) >> 26;
}
