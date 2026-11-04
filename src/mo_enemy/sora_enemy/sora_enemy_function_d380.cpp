#pragma force_active on
#include <em/em_info.h>
#include <snd/snd_system.h>

struct Entry {
    char pad0[4];
    EnemyKind kind;
    char pad8[8];
    int group;
    void* resource;
};

extern "C" Entry* fn_41_D5C4(void*, unsigned int);
extern "C" int fn_41_DA00(void*);
extern "C" int fn_80073D08(sndSystem*, unsigned int);

extern "C" bool fn_41_D380(void* self, unsigned int key) {
    Entry* entry = fn_41_D5C4(self, key);
    if (entry == 0) return false;
    if (entry->resource == 0) return false;
    if (fn_41_DA00(entry->resource) == 0) return false;
    if (entry->group >= 0) {
        unsigned int id = emInfo::getInstance()->getSEId(entry->kind);
        if (id != 0xffffffff && fn_80073D08(g_sndSystem, id) == 0) return false;
    }
    return true;
}
