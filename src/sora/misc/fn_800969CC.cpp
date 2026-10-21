#pragma force_active on
extern "C" void fn_800969CC(void *self, unsigned int idx, unsigned char val)
{
    void **table = *(void ***)((char *)self + 0x8);
    ((unsigned char *)table[idx])[1] = val;
}
