#pragma force_active on
extern "C" void* fn_41_23270(void* self, unsigned int index)
{
    unsigned int* data = *(unsigned int**)((char*)self + 0x54);
    if (data == 0)
        return 0;

    if (index >= *(unsigned int*)((char*)self + 0x58))
        return 0;

    return (char*)data + (index << 5);
}
