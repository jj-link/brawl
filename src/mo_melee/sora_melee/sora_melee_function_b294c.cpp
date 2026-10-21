#include <types.h>
#pragma force_active on

struct Elem {
    char _pad[0x3c];
    u8 _a : 1;
    u8 f : 1;
    u8 _b : 6;
};

class Arr {
public:
    virtual void v0();
    virtual Elem* at(s32 i);
    virtual void v2();
    virtual s32 size();
};

struct Owner {
    char _pad[0x18];
    Arr* m_arr;
};

extern "C" void fn_27_B294C(Owner* self, u32 flag, s32 idx) {
    if (idx == -1) {
        s32 n = self->m_arr->size();
        for (s32 i = 0; i < n; i++) {
            Elem* e = self->m_arr->at(i);
            e->f = flag;
        }
    } else {
        Elem* e = self->m_arr->at(idx);
        e->f = flag;
    }
}
