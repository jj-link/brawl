#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80062D08(Entry*, void*);

struct grCollisionLineWork;

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

    void setGroundAttach(unsigned long key, grCollisionLineWork* line);
};

void ecMgr::setGroundAttach(unsigned long key, grCollisionLineWork* line) {
    Entry* entry = find(key);
    if (entry)
        fn_80062D08(entry, line);
}
