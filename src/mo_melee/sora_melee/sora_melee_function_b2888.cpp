#include <types.h>
#pragma force_active on

class Arr {
public:
    virtual void v0();
    virtual void* at(s32 i);
    virtual void v2();
    virtual s32 count();
};

struct Elem {
    u8 pad[0x3C];
    u8 top : 1;
    u8 rest : 7;
};

struct Owner {
    u8 pad[0x18];
    Arr* arr;
};

extern "C" void fn_27_B2888(Owner* self, s32 flag, s32 idx) {
    if (idx == -1) {
        s32 n = self->arr->count();
        for (s32 i = 0; i < n; i++) {
            Elem* e = (Elem*)self->arr->at(i);
            e->top = flag;
        }
    } else {
        Elem* e = (Elem*)self->arr->at(idx);
        e->top = flag;
    }
}
