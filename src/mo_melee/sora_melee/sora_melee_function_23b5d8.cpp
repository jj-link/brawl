#pragma force_active on
extern "C" void* fn_27_23B5D8(void* self)
{
    unsigned char* base = *reinterpret_cast<unsigned char**>(
        static_cast<unsigned char*>(self) + 0x40);
    int index = *reinterpret_cast<int*>(
        static_cast<unsigned char*>(self) + 0x48);

    return base + index * 0x5C + 0x98;
}
