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
    char _00[0x4c];
    ScnMdlEntry* m_e1; // 0x4c
    ScnMdlEntry* m_e2; // 0x50
    ScnMdlEntry* m_e3; // 0x54
    ScnMdlEntry* m_arr[0x23]; // 0x58
    char _pad[0x144d - 0x58 - 0x23*4];
    unsigned char m_flag; // 0x144d
};

void fn_25_315C(void* arg) {
    Obj* o = (Obj*)arg;
    if (o->m_flag) {
        removeResAnmScn__11gfSceneRootFv(g_gfSceneRoot);
        fn_8019733C((char*)arg + 0x1450);
        for (int i = 0; i < 0x23; i++) {
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_arr[i]->m_model);
        }
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e1->m_model);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e2->m_model);
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, o->m_e3->m_model);
        o->m_flag = 0;
    }
}
}
