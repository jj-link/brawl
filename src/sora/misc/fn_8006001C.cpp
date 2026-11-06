#pragma force_active on
#include <so/ground/so_ground_module_impl.h>

typedef unsigned long u32;

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80062D08(Entry*, void*);
extern "C" char* fn_80134524(char* base, int idx);

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

    void setGroundAttach(u32 key, soGroundModule* groundModule);
};

void ecMgr::setGroundAttach(u32 key, soGroundModule* groundModule) {
    Entry* entry = find(key);
    if (entry) {
        char* ret = (char*)groundModule->getCollStatus(0);
        fn_80062D08(entry, fn_80134524(ret, 3));
    }
}
