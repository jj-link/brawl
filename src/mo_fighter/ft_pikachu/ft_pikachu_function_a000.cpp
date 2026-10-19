#pragma force_active on
extern "C" bool fn_98_A000(void* object, unsigned int mask, int index)
{
    unsigned int* values = *reinterpret_cast<unsigned int**>(
        static_cast<char*>(object) + 0x1C);
    return (values[index] & mask) != 0;
}
