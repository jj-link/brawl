#include <types.h>
#pragma force_active on

class Elem {
public:
    virtual void v0();
    virtual void v1(u32 a, s32 b, void* c);
};

struct Owner {
    u8 pad[0xDC];
    Elem** m_elems;
    u32 _pad;
    u32 m_count;
};

extern "C" {

Elem* fn_801ABFFC(Owner* self, u32 index) {
    if (index < self->m_count) {
        Elem* elem = self->m_elems[index];
        elem->v1(0x10003, 0, self);
        for (u32 i = index; i < self->m_count - 1; i++) {
            self->m_elems[i] = self->m_elems[i + 1];
        }
        self->m_count--;
        return elem;
    }
    return 0;
}

}
