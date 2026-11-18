#include <types.h>
#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <stl/internal/printf.h>
#pragma force_active on

class gfTask_base {
public:
    char pad[0x3c];
};

class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_1_8AE0();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
};

struct TaskEntry {
    u8 pad0[2];
    char name[0x15];
    u8 f17;
    u8 f18;
    u8 pad19;
    u8 f1A;
    u8 pad1B;
    u8 f1C;
    u8 pad1D[3];
    s32 f20;
    u8 pad24[4];
};

struct TaskCtrl {
    u8 state;
    u8 count;
    u8 flag;
    u8 limit;
    u8 pad4[4];
    TaskEntry entries[16];
};

struct TaskOut {
    s32 f00;
    char name[0x18];
    s32 f1C;
    s32 f20;
    u8 f24;
    u8 f25;
    u8 pad26[2];
};

extern "C" {
extern char lbl_1_data_3B84[];
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_4_3FF8(void*, TaskOut*, s32*, u8, u8);
int fn_8004D6C4(void*, s32, char*);
}

extern "C" void fn_1_AEC8(void* self) {
    TaskCtrl* td = (TaskCtrl*)g_GameGlobal->m_tournamentData;
    TaskEntry* e;
    TaskOut* o;
    s32 layout = gfSceneManager::getInstance()->m_memoryLayout;

    if (td->state > 0x10 || td->state == 0) {
        td->state = 0x10;
        td->count = 7;
    }

    s32 arr[8];
    TaskOut out[16];
    e = td->entries;
    o = out;

    for (u32 i = 0; i < 16; i++) {
        o->f1C = e->f20;
        o->f25 = e->f18;
        if (layout == 0) {
            e->f1A = 0x28;
            e->f18 = i + 1;
            o->f25 = i + 1;
        }
        if (layout != 0) {
            s32 idx = e->f20;
            if (idx < td->count && idx >= 0) {
                GameGlobal* g = g_GameGlobal;
                gmSelCharData* selData = g->m_selCharData;
                u8* sel = (u8*)selData;
                u8* colorRecord = sel + idx * 4;
                u8* playerRecord = sel + idx * 0x5C;
                e->f1A = colorRecord[0xA];
                e->f1C = playerRecord[0xBD];
                u8 c = playerRecord[0xD0];
                if (e->f17 != c && c != 0x78) {
                    e->f17 = c;
                    fn_8004D6C4(g_GameGlobal, c, e->name);
                }
            }
        }
        o->f00 = e->f17;
        sprintf(o->name, lbl_1_data_3B84, e->name);
        o->f20 = e->f1A;
        o->f24 = e->f1C;
        ++e;
        ++o;
    }

    switch (layout) {
    case 0:
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        arr[3] = 0;
        break;
    case 1: {
        u8 cnt = td->count;
        u32 r9 = td->limit;
        s32 diff = (s32)td->state - cnt;
        if ((u32)diff < r9) {
            r9 = diff;
        }

        u32 offset;
        u8 player = 0;
        goto check_player;
    copy_player:
        {
            u8* base = (u8*)g_GameGlobal->m_resultInfo;
            offset = player * 0x2AC;
            ++player;
            base[offset + 0x32] = base[offset + 0x33];
        }
    check_player:
        if (player < cnt) goto copy_player;

        if (td->flag == 0) {
            for (u32 player = 0; player < cnt; ++player) {
                u8 value = ((u8*)g_GameGlobal->m_resultInfo)[player * 0x2AC + 0x32];
                if ((s32)(cnt - r9) > (s32)value)
                    arr[player] = 1;
                else
                    arr[player] = 2;
            }
            for (u32 player = cnt; player < 4; ++player) {
                arr[player] = 0;
            }
        } else {
            for (u32 player = 0; player < cnt; ++player) {
                u8 value = ((u8*)g_GameGlobal->m_resultInfo)[player * 0x2AC + 0x32];
                if (r9 > value)
                    arr[player] = 2;
                else
                    arr[player] = 1;
            }
            for (u32 player = cnt; player < 4; ++player) {
                arr[player] = 0;
            }
        }
        break;
    }
    case 2:
    case 3:
    case 4:
    case 5:
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        u32 index = layout - 2;
        arr[index] = 3;
        break;
    }

    u8 state;
    u8 count;
    count = td->count;
    state = td->state;
    void* memory = __nw__FUlQ25Heaps8HeapType(0x13A4, 0x2A);
    gfTask* task = (gfTask*)memory;
    if (memory != 0) {
        task = (gfTask*)fn_4_3FF8(memory, out, arr, state, count);
    }
    task->init();
    *(void**)((char*)self + 8) = task;
}
