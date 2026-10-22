#include <types.h>
#pragma force_active on

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80062B44(char* self, void* p, short v, int flag);

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

extern "C" void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlUlb(EcMgr* self, u32 parent, void* p, short v, int flag) {
    Entry* entry = self->find(parent);
    if (entry) {
        fn_80062B44((char*)entry, p, v, flag);
    }
}
