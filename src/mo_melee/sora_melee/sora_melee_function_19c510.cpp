#pragma force_active on
extern "C" void fn_27_19C510(void* self)
{
    unsigned int value = *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8);
    value |= 0x00080000;
    *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8) = value;
}
