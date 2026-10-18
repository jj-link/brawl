#pragma force_active on
extern "C" void fn_63_2224(void* self, unsigned int value)
{
    if (value >= 4)
        return;

    unsigned char* field = (unsigned char*)self + 0x1E0;
    if (*field != value)
        *field = value;
}
