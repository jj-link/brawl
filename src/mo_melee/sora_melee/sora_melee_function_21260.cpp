#include <types.h>
#pragma force_active on

class soNext {
public:
    virtual void vf0();
    virtual void* vf1(s32 index);
};

class soBase {
public:
    virtual void dummy();
    soNext* m_next;
    void* m_data;
    s32 m_size;
};

extern "C" {
void* fn_27_21260(soBase* self, s32 index) {
    if (index >= self->m_size) {
        if (self->m_next != 0) {
            return self->m_next->vf1(index - self->m_size);
        }
    }
    return (char*)self->m_data + (index << 3);
}
}
