#pragma force_active on
extern "C" void fn_98_A048(char* self, unsigned int mask, unsigned int index)
{
    unsigned int* table = *(unsigned int**)(self + 0x1c);
    table[index] |= mask;
}
