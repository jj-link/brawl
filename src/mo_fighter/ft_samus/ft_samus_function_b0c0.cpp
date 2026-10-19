#pragma force_active on
extern "C" void* fn_94_B0C0(void* self, unsigned int index)
{
    void** table = *(void***)((char*)self + 0xc);
    return table[index];
}
