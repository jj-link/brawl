#pragma force_active on
extern "C" void fn_27_122B68(void* object)
{
    unsigned int* field = reinterpret_cast<unsigned int*>(
        reinterpret_cast<unsigned char*>(object) + 8);
    *field |= 0x2000;
}
