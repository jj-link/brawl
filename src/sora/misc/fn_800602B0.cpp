#pragma force_active on

typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80063084(Entry*, Vec3f*);

class ecMgr {
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

    void setPos(unsigned long key, Vec3f* v);
};

void ecMgr::setPos(unsigned long key, Vec3f* v) {
    Entry* entry = find(key);
    if (entry) {
        fn_80063084(entry, v);
    }
}
