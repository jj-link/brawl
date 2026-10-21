#include <types.h>
#pragma force_active on

struct Owner;
struct Inner;
struct CastResult;

struct Item {
    u8 pad[0xE8];
    u32 value;
};

struct Table {
    u32 value;
    Item** items;
};

struct First {
    u32 pad[2];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void apply(s32, s32);
};

struct Inner {
    u32 pad[2];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get();
};

struct Owner : First {
    Inner inner;
    u8 padding[0x14];
    Table* table;
    u32 value;
    Item* item;
    u32 result;
};

struct CastResult {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual s32 get();
};

extern "C" {
extern char lbl_27_data_7A048[];
extern char lbl_27_data_CBA0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
s32 fn_27_2BCDD8(CastResult*);
Table* fn_27_2B25BC(s32, s32, s32);

void fn_27_2BC7D0(Owner* self, s32 arg1, s32 arg2) {
    self->apply(arg2, 0xFF);
    s32 value;
    CastResult* obj = (CastResult*)__dynamic_cast(
        self->inner.get(), 0, lbl_27_data_7A048, lbl_27_data_CBA0, 1);
    value = obj->get();
    self->table = fn_27_2B25BC(arg1, fn_27_2BCDD8(obj), value);
    self->value = self->table->value;
    self->item = 0;
    s32 index = fn_27_2BCDD8(obj);
    if (self->table) {
        self->item = self->table->items[index];
    }
    if (self->item) {
        self->result = self->item->value;
    }
}
}
