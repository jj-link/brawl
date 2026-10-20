#pragma force_active on
// st_metalgear: fn_71_A1C4 -- set bit 24 of the u32 field at +0x8 of the
// object referenced by the argument (arg is a pointer to a 0x10-byte block
// whose flag word lives at +0x8).
extern "C" void fn_71_A1C4(void* self)
{
    unsigned char* p = static_cast<unsigned char*>(self);
    unsigned int& field = *reinterpret_cast<unsigned int*>(p + 8);
    field = field | 0x00080000u;
}
