#pragma force_active on

typedef unsigned long u32;

struct SomeObj {
    char pad[0x10];
    u32 field;
};

struct Entry {
    char pad[0x30];
    SomeObj* obj;
    char pad34[0x48];
    u32 key;
    u32 tail;
};

class EcMgr {
public:
    char pad[0x60];
    Entry* entries;
    char pad64[8];
    int active;
    u32 first;
    u32 last;
};

extern "C" int fn_80060FC4(EcMgr* self, u32 key) {
    if (self->active != 0) {
        u32 last = self->last;
        u32 first = self->first;
        Entry* entry = &self->entries[first];
        for (u32 i = first; i <= last; ++i, ++entry) {
            if (entry->key != 0) {
                if (entry->obj->field == key) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
