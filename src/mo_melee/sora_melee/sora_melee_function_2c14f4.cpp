#pragma force_active on

typedef unsigned int u32;
typedef int s32;

struct Entry { u32 kind; };

struct EntryList {
    virtual void reserved0();
    virtual void reserved1();
    virtual Entry*& at(int index);
    virtual int size();
};

struct Object {
    char pad0[4];
    s32 enabled;
    EntryList entries;
};

struct Manager {
    char pad[0x50];
    s32 mode;
};

extern "C" Manager* getInstance__9itManagerFv();

static inline Entry* findEntry(Object* object, u32 kind) {
    if (object->enabled == 0) {
        return 0;
    }
    for (s32 i = 0; i < object->entries.size(); i++) {
        Entry* entry = object->entries.at(i);
        if (entry != 0 && kind == entry->kind) {
            return entry;
        }
    }
    return 0;
}

extern "C" bool fn_27_2C14F4(Object* object, u32 kind) {
    switch (getInstance__9itManagerFv()->mode) {
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
            kind = (u32)-0x10;
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
            kind = (u32)-0xF;
        }
        break;
    }
    }

    return findEntry(object, kind);
}
