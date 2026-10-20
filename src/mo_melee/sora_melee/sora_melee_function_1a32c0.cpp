#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    u8 pad[8];
    u32 m_flags;
};

extern "C" {
void fn_27_1A32C0(Obj* self) {
    self->m_flags &= ~0x2;
}
}
