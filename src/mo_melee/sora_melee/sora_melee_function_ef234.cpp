#include <types.h>
#pragma force_active on

struct Item {
    char pad[0xA];
    s16 value;
};

class Sub {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Item* get(s32);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void set(s32, void*);
    virtual void slot12();
    virtual void slot13();
    virtual unsigned int full();

    char storage[0x14];
};

class Outer {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 count();
    virtual void slot5();
    virtual unsigned int check(s32);

    char pad[0xC];
    Sub sub;
    u8 flag;

    s32 find(s16 limit) {
        if (limit <= -1)
            return count();

        s32 n = count();
        for (s32 i = 0; i < n; i++) {
            s16 value = sub.get(i)->value;
            if (value <= -1)
                return i;
            if (value > limit)
                return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_EFA3C(void*);
extern "C" void fn_27_FDF94(s32*, int*, int, const short*, short);

extern "C" s32 fn_27_EF234(Outer* self, int* arg1, s32 arg2, s16* arg3, s16 arg4)
{
    s32 property[5];
    s16 half;

    if (self->sub.full() == 1U)
        return -1;

    if ((self->flag == 0 || arg2 > -1) && self->check(arg2) == 1U)
        return -1;

    if (self->flag == 0 && arg2 <= -1) {
        arg2 = fn_27_EFA3C(self);
        if (arg2 <= -1)
            return -1;
    }

    s32 index = self->find(arg4);

    if (index < 0)
        return -1;

    half = *arg3;
    fn_27_FDF94(property, arg1, arg2, &half, arg4);
    self->sub.set(index, property);
    return arg2;
}
