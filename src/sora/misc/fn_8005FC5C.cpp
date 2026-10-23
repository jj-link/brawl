#include <types.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ScnMdl; } }

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80062A98(Entry*, nw4r::g3d::ScnMdl*, const char*, bool);

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

extern "C" void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(
    EcMgr* self, u32 key, nw4r::g3d::ScnMdl* model,
    const char* name, bool flag)
{
    Entry* entry = self->find(key);
    if (entry) {
        fn_80062A98(entry, model, name, flag);
    }
}
