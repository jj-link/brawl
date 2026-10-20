#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad[0xc];
    u16 m_value;
};

extern "C" {
bool fn_27_239FD8(Fn27Obj* p) {
    return p->m_value != 0;
}
}
