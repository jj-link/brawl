#pragma force_active on
extern "C" void fn_27_1A1AC8(void* self)
{
    unsigned int flags = *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8);
    *reinterpret_cast<unsigned int*>(static_cast<char*>(self) + 8) = flags | 0x2000;
}
