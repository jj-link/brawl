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
extern "C" void fn_801AAFF0(void*, int);
extern "C" void fn_801AB014(void*, int);

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

extern "C" void fn_800606F4(EcMgr* self, u32 key, int arg) {
    Entry* entry = self->find(key);
    if (entry) {
        int model = entry->model;
        if (model) {
            fn_801AAFF0((void*)model, arg);
            fn_801AB014((void*)model, arg);
        }
    }
}
