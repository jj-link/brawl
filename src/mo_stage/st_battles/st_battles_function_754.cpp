#pragma force_active on
extern "C" void fn_42_754(unsigned char* p)
{
    p[0x6C] = (unsigned char)(p[0x6C] & ~(1u << 3));
}
