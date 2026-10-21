#pragma force_active on

extern "C" void* fn_802DAD64(void* self, int index)
{
    char* base = *(char**)self;
    return base + index * 0x50;
}
