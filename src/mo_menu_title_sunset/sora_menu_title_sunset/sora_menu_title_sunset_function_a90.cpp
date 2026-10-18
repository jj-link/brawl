#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D7B8(void*);
void fn_8019733C(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);

struct ScnMdlEntry {
    char _00[0xc];
    void* m_model; // 0x0c
};

struct Obj {
    char _00[0x60];
    ScnMdlEntry** m_entries; // 0x60
    char _64[4];
    void* _68;               // 0x68
    char _6c[8];
    int m_count;             // 0x74
    char _78[4];
    unsigned char m_flag;    // 0x7c
    int m_state;             // 0x80
};

void fn_25_A90(void* obj) {
    Obj* o = (Obj*)obj;
    if (o->m_flag) {
        fn_8000D7B8(g_gfSceneRoot);
        fn_8019733C(&o->_68);
        int i = 0;
        int off = 0;
        for (; i < o->m_count; i++) {
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
                g_gfSceneRoot, (*(ScnMdlEntry**)((char*)o->m_entries + off))->m_model);
            off += 4;
        }
        o->m_flag = 0;
    }
    o->m_state = 4;
}
}
