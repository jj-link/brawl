#include <types.h>
#pragma force_active on

extern "C" void fn_800900AC(void* p);

struct Inner {
    u8 m_pad[0x5b];
    u8 m_val;
};

struct Outer {
    void* m_first;
    Inner* m_second;
};

struct Self {
    u8 m_pad[0x2c];
    Outer* m_outer;
};

extern "C" {
void fn_27_122AC(Self* self, void* a, void* b, u8 val) {
    Outer* outer = self->m_outer;
    fn_800900AC(outer->m_first);
    Inner* inner = outer->m_second;
    if (inner != 0) {
        inner->m_val = val;
    }
}
}
