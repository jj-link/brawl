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

struct Item {
    s32 value;
};

struct List {
    virtual void slot0();
    virtual Item* get(s32);
    virtual void slot2();
    virtual s32 count();
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
    u8 padF4[0x140 - 0xF4];
    List* list;
};

extern "C" void fn_27_1BA08(Big*, Item*);
extern "C" void fn_27_777D8(Big*, const Big*);
extern "C" void fn_27_77668(Params*, const Big*);

extern "C" void fn_27_1BA80(Owner* self) {
    for (s32 i = 0; i < self->list->count(); ++i) {
        Big a;
        Big b;
        Params params;
        params.zero = 0;
        params.flags |= 0x80;
        params.invalid = -1;
        fn_27_1BA08(&a, self->list->get(i));
        fn_27_777D8(&b, &a);
        fn_27_77668(&params, &b);
        s16 id = -1;
        self->manager->set(0, &params, self->list->get(i)->value, -1, &id);
    }
}
