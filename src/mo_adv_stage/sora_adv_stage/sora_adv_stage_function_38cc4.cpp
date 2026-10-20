#pragma force_active on
extern "C" void *fn_40_38CC4(void *self, unsigned int idx)
{
    void **table = *(void ***)((char *)self + 0x44);
    return table[idx];
}
