#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_40_1E44C(void* self)
{
    u32* field = (u32*)((char*)self + 8);
    *field |= 0x2000;
}
