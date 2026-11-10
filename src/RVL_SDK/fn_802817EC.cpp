#include <types.h>
#pragma force_active on

class Class_804864A0 {
public:
    virtual void fn_802814B8();
    virtual void fn_80080A64();
    virtual void fn_80281744();
    virtual void fn_80281640();
    virtual void fn_802816FC();
    virtual void fn_802817A4();
    virtual s32 fn_802817EC(s32, s32);
};

struct Obj {
    u8 pad[8];
    Class_804864A0* sub;
    u8 padC[4];
    s32 pos;
    s32 size;
};

extern "C" s32 fn_802815A0(void*);

extern "C" s32 fn_802817EC(Obj* self, s32 offset, s32 origin) {
    if (self->sub != 0) {
        fn_802815A0(self);
        return self->sub->fn_802817EC(offset, origin);
    }
    s32 pos = -1;
    switch (origin) {
    case 0:
        pos = offset;
        break;
    case 1:
        pos = self->pos + offset;
        break;
    case 2:
        pos = self->pos - offset;
        break;
    }
    s32 result = 0;
    if (pos < 0) {
        pos = 0;
        result = 1;
    } else if (pos > self->size) {
        pos = self->size;
        result = 1;
    }
    self->pos = pos;
    return result;
}