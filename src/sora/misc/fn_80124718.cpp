#include <types.h>
#pragma force_active on

struct Item { char pad[0xe]; u16 flags; u8 state; };
struct Part4 { char pad[0x54]; u8 flags; };
struct Part8 { char pad[0x2c]; u8 flags; };
struct Entry { Item* item; Part4* part4; Part8* part8; u32 pad; };
struct List { char pad[0x1a]; u16 count; Entry* entries; };
struct Owner { char pad[0x164]; Item* item; };

struct Class_8045DA20_base {
    char pad0[8]; float value; char padc[3]; u8 flags;
    char pad10[8]; Owner* owner; List* list;
    char pad20[0x30c];
};
class Class_8045DA20 : public Class_8045DA20_base {
public:
    virtual void fn_80125930();
    virtual void fn_80125E1C(float);
    virtual void fn_80125E30();
    virtual void fn_80126B48();
    virtual void fn_80126F40();
    virtual void fn_8012C32C();
    virtual void fn_8012C6A8(Entry*);
};
extern float lbl_805A295C;
extern float lbl_805A2960;
extern float lbl_805A2994;
extern float lbl_805A29B8;
extern "C" void fn_80124080(Class_8045DA20*);
extern "C" int fn_80124718(Class_8045DA20* self) {
    u8 flags = self->flags;
    Owner* owner = self->owner;
    u16 mask;
    u32 offset;
    int result = 0;
    self->value = lbl_805A295C;
    mask = 0;
    if (flags & 1) mask |= 2;
    if (flags & 8) mask |= 1;
    if (flags & 2) mask |= 4;
    if (flags & 4) mask |= 8;
    u32 i = 0;
    offset = 0;
    for (; i < self->list->count; offset += 0x10, i++) {
        Entry* entry = (Entry*)((char*)self->list->entries + offset);
        int valid2 = 0;
        int valid1 = 0;
        Item* item = entry->item;
        int ok;
        if (item != NULL && entry->part4 != NULL) valid1 = 1;
        if (valid1 && entry->part8 != NULL) valid2 = 1;
        if (valid2 && ((entry->part4->flags >> 4) & 1) && ((entry->part8->flags >> 7) & 1)) ok = 1;
        else ok = 0;
        if (ok && (item->flags & mask)) {
            if (item->state & 1) {
                int same = 0;
                if (item == owner->item) same = 1;
                if (same) continue;
            }
            self->fn_8012C6A8(entry);
            result++;
        }
    }
    int ret = 0;
    if (result != 0) {
        if (self->value < lbl_805A2994) self->value = lbl_805A2960;
        if (self->value > lbl_805A2960) self->fn_80125E1C(lbl_805A29B8 * self->value);
        fn_80124080(self);
        if (self->value < lbl_805A295C) ret = 1;
    }
    return ret;
}