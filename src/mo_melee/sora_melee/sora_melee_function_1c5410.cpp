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

class Class_3E658 {
public:
    virtual void fn_27_1BA390();
    virtual void fn_27_1B9D34();
    virtual void fn_27_1B9D44();
    virtual void fn_27_1A411C();
    virtual s32 fn_27_86BA0();

    u8 pad[0xC];
    Class_18ED8 m_inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = fn_27_86BA0();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.slot2(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1C5410(Class_3E658* self, s32 value) {
    return self->find(value);
}