#include <types.h>
#pragma force_active on

struct Target {
    u8 pad[0x34];
    float m_f;
};

struct Source {
    virtual void v0();
    virtual Target* get();
};

struct Owner {
    u8 pad[0x34];
    Source* m_src;
};

extern const float lbl_27_rodata_320;

extern "C" bool fn_27_10EA0(Owner* self) {
    return self->m_src->get()->m_f > lbl_27_rodata_320;
}
