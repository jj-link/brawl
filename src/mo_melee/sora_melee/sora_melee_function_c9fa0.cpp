#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_C9FA0(void* p)
{
    u32* field = (u32*)((char*)p + 8);
    *field &= 0xFFBFFFFFu;
}
