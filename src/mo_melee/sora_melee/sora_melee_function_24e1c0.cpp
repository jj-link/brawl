#pragma force_active on
struct FnSelf {
    char pad[0x40];
    unsigned char m_40;
};

extern "C" bool fn_27_24E1C0(FnSelf* self)
{
    return self->m_40 == 5;
}
