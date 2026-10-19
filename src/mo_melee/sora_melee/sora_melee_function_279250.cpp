#include <types.h>
#pragma force_active on

class grMadein {
public:
    void startEntity();
    u8 pad[0x1a0];
    void* m_unk1A0;
};

extern "C" void fn_27_279250(grMadein* self, void* arg) {
    self->startEntity();
    self->m_unk1A0 = arg;
}
