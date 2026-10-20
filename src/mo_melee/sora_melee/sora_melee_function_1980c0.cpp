#pragma force_active on
extern "C" void fn_27_1980C0(void *ptr)
{
    unsigned int value = *reinterpret_cast<unsigned int *>(static_cast<char *>(ptr) + 8);
    value |= 0x00400000;
    *reinterpret_cast<unsigned int *>(static_cast<char *>(ptr) + 8) = value;
}
