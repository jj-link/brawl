#include <types.h>
#pragma force_active on

extern "C" {
extern const u8 lbl_27_data_71EB8[];
extern s32 lbl_27_data_71BF0[];
void* fn_27_2B26E8(const void*, s32, u32, u32);
}

struct Entry {
    u32 unused;
    u8 flag;
    u8 pad[3];
    s32 id;
    s32 group;
};

class EntryArray {
public:
    virtual void unused0();
    virtual void unused1();
    virtual Entry*& at(s32);
    virtual s32 size();
};

struct Context {
    u8 pad0[0xC8];
    EntryArray entries;
    u8 pad1[0x14A0 - 0xCC];
    u8 flag;
};

static inline s32 query(Context* self) {
    if (self->flag != 0) {
        if (lbl_27_data_71EB8[0x26] == 0)
            return -1;
        switch (lbl_27_data_71BF0[0x26]) {
        case 1:
        case 6:
        case 7:
            return 0x26;
        }
    }
    return -1;
}

static inline Entry* find(Context* self, s32 id) {
    for (s32 i = 0; i < self->entries.size(); ++i) {
        Entry* entry = self->entries.at(i);
        if (entry != 0 && id == entry->id && entry->group == 0)
            return entry;
    }
    return 0;
}

extern "C" void* fn_27_2AC0A4(Context* self, s32 mode) {
    switch (mode) {
    case 0:
    case 1: {
        s32 id = 0x26;
        if (query(self) >= 0)
            id = -3;
        Entry* entry = find(self, id);
        if (entry != 0 && entry->flag == 0)
            return fn_27_2B26E8(entry, 4, mode == 1, 0x28);
        break;
    }
    default:
        return 0;
    }
    return 0;
}
