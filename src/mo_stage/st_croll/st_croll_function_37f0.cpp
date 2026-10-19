#include <types.h>
#pragma force_active on

class grMadein {
public:
    void startEntity();
};

struct StCrollObj {
    grMadein* m_madein;
    u32 m_flags;
    u8 m_pad[0x14];
    float m_value;
};

extern "C" const float lbl_90_rodata_0;

extern "C" void fn_90_37F0(StCrollObj* self) {
    if ((self->m_flags & 1) == 0) {
        grMadein* madein = self->m_madein;
        self->m_flags |= 1;
        if (madein != 0) {
            madein->startEntity();
        }
        self->m_value = lbl_90_rodata_0;
    }
}
