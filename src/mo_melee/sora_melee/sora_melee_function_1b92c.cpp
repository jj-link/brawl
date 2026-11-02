#include <types.h>
#pragma force_active on

struct Big {
    float x, y, z, w;
};

struct Params {
    u8 flags;
    u8 pad;
    s16 zero;
    s16 invalid;
    u8 rest[6];
};

struct Elem {
    s32 value;
    u8 rest[0x14 - 4];
};

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void set(s32, Params*, s32, s32, s16*);
};

struct Owner {
    u8 pad0[0xF0];
    Manager* manager;
};

extern "C" void fn_27_1BA08(Big*, Elem*);
extern "C" void fn_27_777D8(Big*, const Big*);
extern "C" void fn_27_77668(Params*, const Big*);

extern "C" void fn_27_1B92C(Owner* self, Elem* arr, s32 count, s32 x) {
    if (arr == 0 || count <= 0) {
        return;
    }
    Elem* cur = arr;
    Elem* val = arr;
    for (s32 i = 0; i < count; i++) {
        Big a;
        Big b;
        Params params;
        s16 id;
        params.zero = 0;
        params.flags |= 0x80;
        params.invalid = -1;
        fn_27_1BA08(&a, cur);
        fn_27_777D8(&b, &a);
        fn_27_77668(&params, &b);
        id = -1;
        self->manager->set(x, &params, val->value, -1, &id);
        cur++;
        val++;
    }
}
