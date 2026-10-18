#pragma force_active on
typedef unsigned int u32;

extern "C" {
bool fn_2_28AD4(void* self)
{
    u32 v = *(u32*)((char*)self + 0x670);
    return v > 1;
}
}
