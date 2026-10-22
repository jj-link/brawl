#include <types.h>
#pragma force_active on

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;

struct Manager {
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

extern "C" void fn_80063EEC(Entry*, int, void*, void*, int);

extern "C" void fn_8006097C(Manager* self, u32 key, int arg2, void* arg3, void* arg4, int arg5) {
    Entry* entry = self->find(key);
    if (entry) {
        fn_80063EEC(entry, arg2, arg3, arg4, arg5);
    }
}
