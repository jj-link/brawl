#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_8004E844(void* self)
{
    char* inner = *(char**)((char*)self + 0x24);
    u32* field = (u32*)(inner + 0x268);
    *field |= 0x8;
}
