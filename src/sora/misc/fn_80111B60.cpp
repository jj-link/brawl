#pragma force_active on
extern "C" void* fn_80111B60(void* self, int idx)
{
    char* base = *(char**)((char*)self + 0x14);
    return base + idx * 0x12;
}
