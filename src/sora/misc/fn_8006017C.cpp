#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;

extern "C" void fn_80062F60(Entry*, bool);

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

    void setVisible(unsigned long key, bool flag);
};

void ecMgr::setVisible(unsigned long key, bool flag) {
    Entry* entry = find(key);
    if (entry) {
        fn_80062F60(entry, flag);
    }
}
