#pragma force_active on
extern "C" bool fn_101_D364(void* table, unsigned int mask, unsigned int index)
{
    unsigned int* entries = *reinterpret_cast<unsigned int**>(static_cast<unsigned char*>(table) + 0x1C);
    unsigned int bits = entries[index];
    return (mask & bits) != 0;
}
