#include <types.h>
#include <gm/gm_global.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on

extern f32 lbl_805A1330;

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4(float);
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
};

struct Entry {
    char pad[4];
    u8 flags;
    char pad2[2];
    u8 current, previous, count, value;
    char pad3;
};

struct Object {
    char pad[0x54];
    Class_8042B6D0* a;
    char pad2[4];
    Class_8042B6D0* b;
    Class_8042B6D0* c;
    char pad3[4];
    Entry entries[10];
};

extern "C" void fn_8000D8A8(Object* self) {
    if (!((*((u8*)g_gfSceneRoot + 0x464) >> 1) & 1)) {
        if (!((*((u8*)g_gfSceneRoot + 0x465) >> 3) & 1)) {
            Class_8042B6D0* p = self->c;
            if (!p) {
                p = self->a;
                if (p) {
                    float rate = lbl_805A1330 / (float)g_GameGlobal->getSlowRate();
                    float motionRatio = g_GameGlobal->m_stageData->m_motionRatio;
                    float speed = rate * motionRatio;
                    speed *= g_GameGlobal->m_stageData->m_motionSubRatio;
                    p->fn_801B26E4(speed);
                    p->fn_801AAFE8();
                }
            } else if (p) {
                float rate = lbl_805A1330 / (float)g_GameGlobal->getSlowRate();
                float motionRatio = g_GameGlobal->m_stageData->m_motionRatio;
                float speed = rate * motionRatio;
                speed *= g_GameGlobal->m_stageData->m_motionSubRatio;
                p->fn_801B26E4(speed);
                p->fn_801AAFE8();
            }
        }

        Class_8042B6D0* p = self->b;
        float f = lbl_805A1330;
        if (p) {
            float motionRatio = g_GameGlobal->m_stageData->m_motionRatio;
            float speed = f * motionRatio;
            speed *= g_GameGlobal->m_stageData->m_motionSubRatio;
            p->fn_801B26E4(speed);
            p->fn_801AAFE8();
        }
    }

    for (int i = 0; i < 10; i++) {
        Entry* e = &self->entries[i];
        if ((e->flags >> 7) & 1) {
            if (e->current != e->previous)
                e->count++;
            if (e->count > 3) {
                e->count = 0;
                e->previous = e->current;
            }
            if (e->current != e->previous) {
                if (e->current > e->previous)
                    e->value = e->count;
                else
                    e->value = 4 - e->count;
            } else {
                e->value = 0;
            }
        }
    }
}