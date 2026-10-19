#include <cstring>
#pragma force_active on

struct Obj {
    int m_0;
    int f[15];
    char pad[0x30];
    char buf[0xf0];
};

extern "C" Obj* fn_10_1C874(Obj* self) {
    self->f[0] = 0;
    self->f[1] = 0;
    self->f[2] = 0;
    self->f[3] = 0;
    self->f[4] = 0;
    self->f[5] = 0;
    self->f[6] = 0;
    self->f[7] = 0;
    self->f[8] = 0;
    self->f[9] = 0;
    self->f[10] = 0;
    self->f[11] = 0;
    self->f[12] = 0;
    self->f[13] = 0;
    self->f[14] = 0;
    std::memset(self->buf, 0, 0xf0);
    return self;
}
