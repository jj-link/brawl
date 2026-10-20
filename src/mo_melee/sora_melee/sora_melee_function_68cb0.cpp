#include <types.h>
#pragma force_active on

class Target {
public:
    u8 m_bit7 : 1;  // 0x00, mask 0x80
    u8 m_rest : 7;
    u8 m_pad[7];    // 0x01..0x07
    s32 m_timer;    // 0x08
    u8 m_b;         // 0x0C
};

class Source {
public:
    virtual void vf0();
    virtual Target* getTarget(); // slot 3, offset 0x0C
};

class Owner {
public:
    u8 m_pad[0x14];
    Source* m_source; // 0x14
    s32 m_id;         // 0x18
};

extern "C" {
void fn_27_68CB0(Owner* self, s32 id) {
    if (self->m_id == id) {
        Target* t = self->m_source->getTarget();
        t->m_timer = 0;
        t->m_b = 0;
        t->m_bit7 = 0;
    }
}
}
