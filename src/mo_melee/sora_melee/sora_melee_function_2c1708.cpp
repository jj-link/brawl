#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Entry { u32 kind; };
struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual Entry*& fn_27_7AC28(int);
    virtual int fn_27_7AB50();
};
class EntryList {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual Entry*& fn_27_7AC28(int);
    virtual int fn_27_7AB50();
};
struct Object { char pad[4]; s32 enabled; EntryList entries; };
struct Manager { char pad[0x50]; s32 mode; };
extern "C" Manager* getInstance__9itManagerFv();
extern "C" bool fn_27_2C2BD0(Entry*);

static inline Entry* findEntry(Object* object, u32 kind) {
    if (object->enabled == 0) return 0;
    for (s32 i = 0; i < object->entries.fn_27_7AB50(); i++) {
        Entry* entry = object->entries.fn_27_7AC28(i);
        if (entry != 0 && kind == entry->kind) return entry;
    }
    return 0;
}

extern "C" bool fn_27_2C1708(Object* object, u32 kind) {
    switch (getInstance__9itManagerFv()->mode) {
    case 3: {
        s32 var;
        if (kind >= 1 && kind <= 0x5B && (kind & 1) == 1) {
            switch (kind - 0x33) {
            case 0x00: case 0x02: case 0x04: case 0x06: case 0x08:
            case 0x10: case 0x12: case 0x14: case 0x1E:
                var = 0;
                break;
            default:
                var = 1;
                break;
            }
        } else {
            var = 0;
        }
        if (var != 0) kind = (u32)-0x10;
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
        if (var != 0) kind = (u32)-0xF;
        break;
    }
    }
    Entry* entry = findEntry(object, kind);
    if (entry != 0) return fn_27_2C2BD0(entry);
    return 0;
}