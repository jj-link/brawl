#pragma force_active on
extern "C" void fn_27_1A2EA0(void* self)
{
    unsigned int value = *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8);
    value |= 0x00010000;
    *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8) = value;
}
