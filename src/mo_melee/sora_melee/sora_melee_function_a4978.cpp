#include <types.h>
#pragma force_active on

struct Elem {
    s32 id;
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual Elem* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct Outer {
    u8 pad[0x34];
    Class_18ED8* inner;
};

extern "C" s32 fn_27_A4978(Outer* self, s32 id)
{
    if (id == -1) {
        return self->inner->slot3();
    }
    s32 matches = 0;
    s32 count = self->inner->slot3();
    for (s32 i = 0; i < count; i++) {
        Elem* e = self->inner->slot1(i);
        if (id == e->id) {
            matches++;
        }
    }
    return matches;
}
