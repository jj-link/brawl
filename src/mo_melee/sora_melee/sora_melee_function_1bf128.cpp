#include <types.h>
#pragma force_active on

struct Item {
    s32 unk0;
    s32 id;
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Item* slot2(s32 index);
    virtual void slot3();
    virtual void slot4();
};

class Class_3BC60 {
public:
    virtual void fn_27_1B64E8();
    virtual void fn_27_1B5CEC();
    virtual void fn_27_1B5CFC();
    virtual void fn_27_19AA3C();
    virtual s32 fn_27_86BD4();

    u8 pad[0xC];
    Class_18ED8 inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = fn_27_86BD4();
        for (s32 index = 0; index < count; index++) {
            if (value == inner.slot2(index)->id)
                return index;
        }
        return -1;
    }
};

extern "C" s32 fn_27_1BF128(Class_3BC60* self, s32 value) {
    return self->find(value);
}
