#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_320;

class Array {
public:
    virtual void f0();
    virtual void* at(int index);
    virtual void f4();
    virtual int size();
};

struct Elem {
    char pad[0x34];
    float m_f;
};

class Owner {
public:
    char pad[0x34];
    Array* m_arr;
    u32 m_val;
};

extern "C" {
void fn_27_10584(Owner* self, u32 val) {
    self->m_val = val;
    for (int i = 0; i < self->m_arr->size(); i++) {
        Elem* e = (Elem*)self->m_arr->at(i);
        e->m_f = lbl_27_rodata_320;
    }
}
}
