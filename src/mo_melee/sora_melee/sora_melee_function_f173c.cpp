#include <types.h>
#pragma force_active on

struct Item {
    s32 unk0;
    s32 id;
};

class Inner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Item* slot2(s32 index);
};

struct Object_vptr_10_base { char pad[0x10]; };
class Object_vptr_10 : public Object_vptr_10_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Item* slot2(s32 index);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u8 pad[0xC];
    Inner inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;
        s32 count = slot4();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == inner.slot2(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_F173C(Object_vptr_0* self, s32 value) {
    return self->find(value);
}