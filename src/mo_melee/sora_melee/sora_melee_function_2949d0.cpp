#include <types.h>
#pragma force_active on

struct FooItem {
    s32 unk0;
    s32 id;
};

struct Object_vptr_10_base {
    char pad[0x10];
};

class Object_vptr_10 : public Object_vptr_10_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual FooItem* slot2(s32 index);
};

class FooInner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual FooItem* slot2(s32 index);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u8 pad[0xC];
    FooInner inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = slot4();
        for (s32 index = 0; index < count; index++) {
            if (value == inner.slot2(index)->id)
                return index;
        }
        return -1;
    }
};

extern "C" s32 fn_27_2949D0(Object_vptr_0* self, s32 value) {
    return self->find(value);
}
