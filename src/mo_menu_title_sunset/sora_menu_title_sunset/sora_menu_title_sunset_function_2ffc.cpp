#include <gf/gf_3d_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_8019733C(void*);
}

struct ScnMdlEntry {
    char _00[0xc];
    nw4r::g3d::ScnMdl* m_model; // 0x0c
};

struct Obj {
    char _000[0x4c];
    ScnMdlEntry* m_4c;          // 0x4c
    ScnMdlEntry* m_50;          // 0x50
    ScnMdlEntry* m_54;          // 0x54
    ScnMdlEntry* m_58[0x23];    // 0x58
    ScnMdlEntry* m_e4;          // 0xe4
    ScnMdlEntry* m_e8;          // 0xe8
    ScnMdlEntry* m_ec;          // 0xec
    ScnMdlEntry* m_f0;          // 0xf0
    ScnMdlEntry* m_f4[0x23];    // 0xf4
    char _180[0x144d - 0x180];
    unsigned char m_144d;       // 0x144d
    unsigned char m_144e;       // 0x144e
    char _144f[1];
    char m_1450[4];             // 0x1450
    int m_1454;                 // 0x1454
};

extern "C" void fn_25_2FFC(Obj* self) {
    int i;

    if (self->m_144d) {
        g_gfSceneRoot->removeResAnmScn();
        fn_8019733C(self->m_1450);
        void** cur = (void**)self;
        for (i = 0; i < 0x23; i++) {
            g_gfSceneRoot->remove(((ScnMdlEntry*)cur[22])->m_model);
            cur++;
        }
        g_gfSceneRoot->remove(self->m_4c->m_model);
        g_gfSceneRoot->remove(self->m_50->m_model);
        g_gfSceneRoot->remove(self->m_54->m_model);
        self->m_144d = 0;
    }
    if (self->m_144e) {
        g_gfSceneRoot->removeResAnmScn();
        fn_8019733C(self->m_1450);
        void** cur = (void**)self;
        for (i = 0; i < 0x23; i++) {
            g_gfSceneRoot->remove(((ScnMdlEntry*)cur[61])->m_model);
            cur++;
        }
        g_gfSceneRoot->remove(self->m_e4->m_model);
        g_gfSceneRoot->remove(self->m_e8->m_model);
        g_gfSceneRoot->remove(self->m_ec->m_model);
        g_gfSceneRoot->remove(self->m_f0->m_model);
        self->m_144e = 0;
    }
    self->m_1454 = 0xb;
}
