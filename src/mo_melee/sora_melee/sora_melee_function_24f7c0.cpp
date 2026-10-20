#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0x40];
    u8 m_state;
};

extern "C" bool fn_27_24F7C0(Obj* self)
{
    return self->m_state == 3;
}
