#pragma force_active on
extern "C" void fn_48_BDE0(void* self)
{
    unsigned int* field = reinterpret_cast<unsigned int*>(
        reinterpret_cast<unsigned char*>(self) + 8);
    *field |= 0x2000;
}
