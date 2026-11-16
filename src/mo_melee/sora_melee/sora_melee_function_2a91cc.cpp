#include <types.h>
#pragma force_active on

struct Id {
    s32 kind;
    u32 index;
};

union IdValue {
    Id id;
    u64 value;
};

struct Entry {
    s32 unk0;
    Id id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry*& at(s32);
    virtual s32 size();
};

struct Object {
    u8 pad0[0x50];
    s32 state;
    u8 pad1[0x1170 - 0x54];
    Array array;
    u8 pad2[0x14B0 - 0x1174];
    s32 extra;
};

struct Frame {
    Id search;
    Id second;
    Id first;
    IdValue value;
    Id copy;
};

inline Entry* findEntry(Object* self, Frame& frame) {
    frame.search = frame.copy;
    u32 index = frame.search.index;
    Entry* entry;
    for (s32 i = 0; i < self->array.size(); ++i) {
        entry = self->array.at(i);
        s32 kindMatch;
        s32 match;
        match = 0;
        kindMatch = 0;
        if (entry) {
            frame.first = entry->id;
            if (frame.search.kind == frame.first.kind)
                kindMatch = 1;
        }
        if (kindMatch) {
            frame.second = entry->id;
            if (index == frame.second.index)
                match = 1;
        }
        if (match)
            return entry;
    }
    return 0;
}

struct ResultEntry {
    s32 key;
    s32 unk4;
    f32 value;
    s32 unkC;
};

struct Result {
    u8 pad[12];
    ResultEntry* entries;
    u32 count;
};

extern "C" u64 fn_27_2A904C(Object*);
extern "C" Result* fn_27_2B2BA4(Entry*, s32, s32);
extern "C" f32 fn_27_2AB504(void*, s32, f32);
extern "C" s32 fn_803F86E4(void*, const char*, ...);
extern "C" void fn_803FC984(void);

extern char __files[];
extern const char lbl_27_data_7908C[];
extern const f32 lbl_27_rodata_5D5C;

extern "C" f32 fn_27_2A91CC(Object* arg0, s32 arg1, u32* arg2) {
    Frame frame;
    frame.value.value = fn_27_2A904C(arg0);
    frame.copy = frame.value.id;
    Entry* found = findEntry(arg0, frame);

    Result* sel;
    if (found == 0) {
        sel = 0;
    } else {
        s32 extra = arg0->extra;
        if (arg0->state != 2)
            extra = 0;
        Result* result = fn_27_2B2BA4(found, 10000, extra);
        if (result == 0) {
            result = fn_27_2B2BA4(found, 10000, 0);
            if (result == 0) {
                sel = 0;
                goto selected;
            }
        }
        sel = result;
selected:;
    }
    if (sel == 0)
        return lbl_27_rodata_5D5C;

    u32 offset;
    u32 count = sel->count;
    u32 i;
    i = 0;
    offset = 0;
    for (; i < count; ++i) {
        ResultEntry* entry = (ResultEntry*)((u8*)sel->entries + offset);
        s32 id = entry->key;
        if (id == -1)
            break;
        if (id == 0x7d1)
            id = 0x40;
        if (id == arg1) {
            s32 valid = 0;
            if (id >= 0 && id < 0xb2)
                valid = 1;
            if (valid) {
                if ((u32)id >= 0xb2) {
                    fn_803F86E4(__files + 0xa0, lbl_27_data_7908C);
                    fn_803FC984();
                }
                if (!(arg2[(u32)id >> 5] & (1 << (id & 31))))
                    goto next;
            }
            return fn_27_2AB504(arg0, id, entry->value);
        }
next:
        offset += 0x10;
    }
    return lbl_27_rodata_5D5C;
}