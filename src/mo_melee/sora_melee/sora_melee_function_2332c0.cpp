#include <types.h>
#pragma force_active on
struct Key { u16 kind; u16 value; };
struct Sub {
    u8 pad[0x7c];
    Key key;
    bool matches(Key other) const {
        if (key.kind == other.kind && *((const u8*)&key + 3) == *((u8*)&other + 3))
            return true;
        return false;
    }
};
struct Entry { u8 pad[0x90]; Sub* sub; };
struct Manager { u8 pad[0x4c]; Entry** entries; u32 size; };
extern "C" Entry* fn_27_2332C0(Manager* mgr, const Key* key) {
    Entry** list;
    u32 size = mgr->size;
    for (u32 i = 0; i < size; i++) {
        list = mgr->entries;
        if (list[i]->sub != 0) {
            if (list[i]->sub->matches(*key))
                return list[i];
        }
    }
    return 0;
}
