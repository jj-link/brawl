#pragma force_active on
#include <types.h>
#include <it/it_manager.h>

struct Entry {
    u32 kind;
    s32 value;
    u8 flag;
};

class EntryList {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual Entry*& fn_27_7AC28(int index);
    virtual int fn_27_7AB50();
};

struct Object {
    char pad0[4];
    s32 enabled;
    EntryList entries;
};

extern "C" bool fn_27_2C2BD0(Entry* entry);
extern "C" void* fn_27_2C2C60(Entry* entry, u32 kind);

static inline Entry* findEntry(Object* object, u32 kind) {
    if (object->enabled == 0) {
        return 0;
    }
    for (s32 i = 0; i < object->entries.fn_27_7AB50(); i++) {
        Entry* entry = object->entries.fn_27_7AC28(i);
        if (entry != 0 && kind == entry->kind) {
            return entry;
        }
    }
    return 0;
}

static inline u32 remap(u32 kind) {
    u32 id;
    switch (*(s32*)((u8*)itManager::getInstance() + 0x50)) {
    case 3: {
        s32 var;
        if (kind >= 1 && kind <= 0x5B && (kind & 1) == 1) {
            switch (kind - 0x33) {
            case 0x00:
            case 0x02:
            case 0x04:
            case 0x06:
            case 0x08:
            case 0x10:
            case 0x12:
            case 0x14:
            case 0x1E:
                var = 0;
                break;
            default:
                var = 1;
                break;
            }
        } else {
            var = 0;
        }
        if (var != 0) {
            id = (u32)-0x10;
            goto have_id;
        }
        break;
    }
    case 2: {
        s32 var;
        if (kind >= 0x147 && kind <= 0x187) {
            if (kind == 0x155 || kind == 0x183) {
                var = 0;
            } else {
                var = 1;
            }
        } else {
            var = 0;
        }
        if (var != 0) {
            id = (u32)-0xF;
            goto have_id;
        }
        break;
    }
    }
    id = kind;
have_id:
    return id;
}

extern "C" void* fn_27_2C1A78(Object* object, u32 kind) {
    u32 id = remap(kind);
    u32 slot = 0;
    if (id + 0x10000 == 0xFFF0 || id + 0x10000 == 0xFFF1) {
        slot = kind;
    }

    Entry* entry = findEntry(object, id);
    if (entry == 0) {
        return 0;
    }
    if (!fn_27_2C2BD0(entry) || entry->flag != 0) {
        return 0;
    }
    return fn_27_2C2C60(entry, slot);
}