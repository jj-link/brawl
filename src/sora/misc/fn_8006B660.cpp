#pragma force_active on
extern "C" void fn_8006B660(void *self, int index, int value)
{
    void **table = *(void ***)((char *)self + 0x1D8);
    *(int *)((char *)table[index] + 0x34) = value;
}
