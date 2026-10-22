#include <types.h>
#pragma force_active on

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void call(s32* out);
};

struct Owner {
    u8 pad[0x10];
    void* items;
    s32 count;
};

struct Out {
    s32 sum;
    u8 flag;
};

extern "C" void fn_802AF010(Owner* owner, Out* out) {
    s32 sum;
    s32 off;
    s32 i;
    out->sum = 0;
    out->flag = 1;
    off = 0;
    i = 0;
    for (; i < owner->count; i++) {
        Item* it = *(Item**)((char*)owner->items + off);
        it->call(&sum);
        out->sum += sum;
        off += 8;
    }
}
