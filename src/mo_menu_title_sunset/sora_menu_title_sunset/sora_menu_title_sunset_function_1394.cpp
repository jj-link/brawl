#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfSceneRoot;
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);

struct Entry {
    char _00[0xc];
    void* m_model;
};

struct Obj {
    char _00[0x48];
    Entry* m_entry;
};

void fn_25_1394(Obj* o) {
    remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_entry->m_model);
}
}
