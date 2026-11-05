#include <types.h>
#pragma force_active on

struct FooItem {
    s32 unk0;
    s32 id;
};

class Class_32FD8 {
public:
    virtual void fn_27_1B16F0();
    virtual void fn_27_1B16A8();
    virtual FooItem* fn_27_1B18C8(s32 index);
    virtual void fn_27_1B16C8();
    virtual void fn_27_1B16DC();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u8 pad[0xC];
    Class_32FD8 m_inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = slot4();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.fn_27_1B18C8(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1C4A2C(soNullable* self, s32 value) {
    return self->find(value);
}
