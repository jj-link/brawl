#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_41_DB84(void*);

extern "C" u32 fn_41_AA74(void* self, unsigned short id)
{
    if (id == 0xFFFF)
        return 0x0000FFFF;

    self = (void*)*(u32*)((char*)self + 0x91C);
    if (self != 0)
        return fn_41_DB84(self);

    return 0x0000FFFF;
}
