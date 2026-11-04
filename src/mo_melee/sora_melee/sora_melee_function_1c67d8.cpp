#include <types.h>
#pragma force_active on

struct FooItem {
    s32 unk0;
    s32 id;
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual FooItem* slot2(s32 index);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u8 pad[0xC];
    Class_18ED8 m_inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = slot4();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.slot2(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1C67D8(soNullable* self, s32 value) {
    return self->find(value);
}