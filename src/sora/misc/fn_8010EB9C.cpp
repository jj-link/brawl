#include <types.h>
#pragma force_active on

struct Inner;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, Inner*);
    virtual void slot12();
    virtual void slot13(Inner*, Inner*);

    u8 pad[0xE4 - sizeof(void*)];
    void* unkE4;
};

struct Inner {
    u8 pad[4];
    Object_vptr_0* value;
};

struct Middle {
    u8 pad[0x10];
    Inner* inner;
};

struct Entry {
    u8 pad[0xAC];
    Middle* middle;
};

struct Owner {
    u8 pad0[4];
    Object_vptr_0* obj;
    u8 pad8[0x400];
    u8 flags;
};

extern "C" void fn_8010EB9C(Owner* arg0, s32 arg1) {
    Entry* entry = (Entry*)arg0;
    s32 i = 0;

    do {
        u32 flag = 0;
        if (i < arg1 && ((arg0->flags >> 6) & 1))
            flag = 1;

        Object_vptr_0* obj = arg0->obj;
        Middle* middle = entry->middle;
        Inner* inner = middle->inner;

        if (flag != (u32)(inner->value == obj)) {
            if (flag != 0)
                obj->slot11(obj->unkE4, inner);
            else
                obj->slot13(inner, inner);
        }

        ++i;
        entry = (Entry*)((char*)entry + 4);
    } while ((u32)i < 2);
}
