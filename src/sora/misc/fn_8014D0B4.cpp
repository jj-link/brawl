#pragma force_active on
extern "C" {
void* fn_8014D0B4(void* self, unsigned int idx)
{
    if (idx >= *(unsigned int*)((char*)self + 0x10)) {
        return 0;
    }
    return *(char**)((char*)self + 0xC) + idx * 0x28;
}
}
