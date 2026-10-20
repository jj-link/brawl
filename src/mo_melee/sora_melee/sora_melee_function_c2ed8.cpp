#include <types.h>
#pragma force_active on

class Fn27Obj {
public:
    u8 pad0[0xc];
    void* m_0c;
    u8 pad1[0x20 - 0x10];
    bool m_20;
};

extern "C" {
void fn_27_C2ED8(Fn27Obj* self, void* p) {
    self->m_0c = p;
    self->m_20 = true;
}
}
