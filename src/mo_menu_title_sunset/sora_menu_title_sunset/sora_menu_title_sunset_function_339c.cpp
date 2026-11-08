#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfSceneRoot;
void removeResAnmScn__11gfSceneRootFv(void*);
void fn_8019733C(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);

struct ScnMdlEntry {
    char _00[0xc];
    void* m_model;
};

struct Obj {
    char _00[0xe4];
    ScnMdlEntry* m_e[4];      // 0xe4..0xf0
    ScnMdlEntry* m_arr[0x23]; // 0xf4
    char _pad[0x144e - 0xf4 - 0x23 * 4];
    unsigned char m_flag;     // 0x144e
};

void fn_25_339C(void* arg) {
    Obj* o = (Obj*)arg;
    if (o->m_flag) {
        removeResAnmScn__11gfSceneRootFv(g_gfSceneRoot);
        fn_8019733C((char*)arg + 0x1450);
        for (int i = 0; i < 0x23; i++) {
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_arr[i]->m_model);
        }
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e[0]->m_model);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e[1]->m_model);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e[2]->m_model);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e[3]->m_model);
        o->m_flag = 0;
    }
}
}
