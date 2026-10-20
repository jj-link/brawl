#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Fn27Obj {
    char pad[0x1d4];
    s32 m_1d4;
    s32 m_1d8;
    u8* m_1dc;
    u8 m_1e0;
};

extern "C" s32 fn_27_24CBD8(Fn27Obj* self, u8* out1, u8* out2) {
    if (self->m_1d4 < self->m_1d8) {
        if (self->m_1dc[4] == 0) {
            *out1 = self->m_1dc[10];
            *out2 = (self->m_1dc + self->m_1d4)[0x24];
        } else {
            *out1 = (self->m_1dc + self->m_1d4 * 0x14)[0x24];
            *out2 = (self->m_1dc + self->m_1d4 * 0x14)[0x25];
        }
        return 1;
    }
    self->m_1e0 = 0;
    return 0;
}
