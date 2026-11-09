#include <types.h>
#pragma force_active on
struct Id { s32 kind; u32 index; };
union IdValue { u64 value; Id id; };
struct Entry { s32 unk0; Id id; Id getId() const { return id; } };
struct EntryArray { virtual void v0(); virtual void v1(); virtual Entry*& at(s32); virtual s32 size(); };
struct Object { u8 pad0[0x50]; s32 state; u8 pad1[0x1170-0x54]; EntryArray array; u8 pad2[0x14B0-0x1174]; s32 extra; };
struct Item { s32 key; s32 value; u8 pad[8]; };
struct Result { u8 pad[0xC]; Item* items; u32 count; };
extern "C" u64 fn_27_2A904C(Object*);
extern "C" Result* fn_27_2B2BA4(Entry*, s32, s32);
struct Frame { Id search; Id second; Id first; IdValue value; Id copy; };
inline Entry* findEntry(Object* self, Frame& frame);
inline Result* findResult(Object* self) {
    Frame frame;
    frame.value.value = fn_27_2A904C(self);
    frame.copy = frame.value.id;
    Entry* entry = findEntry(self, frame);
    if (!entry) return 0;
    s32 extra = self->extra;
    if (self->state != 2) extra = 0;
    Result* result = fn_27_2B2BA4(entry, 10000, extra);
    if (!result) {
        result = fn_27_2B2BA4(entry, 10000, 0);
        if (!result) return 0;
    }
    return result;
}
inline Entry* findEntry(Object* self, Frame& frame) {
    frame.search = frame.copy;
    u32 index = frame.search.index;
    for (s32 i = 0; i < self->array.size(); ++i) {
        Entry* entry = self->array.at(i);
        s32 match = 0;
        s32 kindMatch = 0;
        if (entry) {
            frame.first = entry->id;
            if (frame.search.kind == frame.first.kind) kindMatch = 1;
        }
        if (kindMatch) {
            frame.second = entry->id;
            if (index == frame.second.index) match = 1;
        }
        if (match) return entry;
    }
    return 0;
}
extern "C" s32 fn_27_2A9404(Object* self, s32 key) {
    Result* result = findResult(self);
    if (!result) return 0;
    u32 offset = 0;
    for (u32 i = 0; i < result->count; ++i) {
        Item* item = (Item*)((char*)result->items + offset);
        s32 itemKey = item->key;
        if (itemKey == -1) break;
        if (itemKey == 0x7d1) itemKey = 0x40;
        if (itemKey == key) return item->value;
        offset += 16;
    }
    return 0;
}