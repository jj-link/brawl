#pragma force_active on

typedef unsigned long u32;

struct Entry {
    char pad[0x44];
    int model;
    char pad48[0x34];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;

class EcMgr {
public:
    char pad[0x60];
    Entry* entries;
    char pad64[8];
    int active;
    u32 first;
    u32 last;

    Entry* find(u32 key) {
        if (key && active) {
            Entry* entry = lbl_805A0164;
            if (entry && entry->key == key)
                return entry;

            entry = &entries[first];
            for (u32 i = first; i <= last; ++i, ++entry) {
                if (entry->key == key) {
                    lbl_805A0164 = entry;
                    return entry;
                }
            }
        }
        return 0;
    }
};

extern "C" int fn_800607C8(EcMgr* self, u32 key) {
    Entry* entry = self->find(key);
    return !entry ? 0 : entry->model;
}
