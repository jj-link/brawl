#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#include <sr/sr_common.h>
#include <types.h>
#include <internal/printf.h>

#pragma force_active on

struct gfTask_base {
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

struct Sub18 {
    char pad[0x1D];
    u8 unk1D;
};

struct MapEnt {
    char pad[0x20];
    int v;
    char pad24[4];
};

struct Header {
    u8 count;
    u8 divisor;
    u8 pad2[2];
    u8 unk4;
    char pad5[3];
    MapEnt elems[32];
    u8 unk508;
};

struct Entry {
    int a;
    char name[0x18];
    int b;
    u8 c;
    char pad[3];
    int d;
    int e;
};

struct Self {
    char pad0[8];
    gfTask* unk8;
    void* unkC;
    int unk10;
    int unk14;
    union {
        int grid[5][16][4];
        int fill[5 * 16 * 4];
    };
    u8 unk518;
    char pad519[3];
    int unk51C;
    int unk520[31];
    int unk59C;
};

extern "C" const char* lbl_1_data_2428[];
extern "C" u8 lbl_1_data_24A8[];

extern "C" void* fn_3_0(void*, int, int);
extern "C" gfTask* fn_3_A72C(
    gfTask*, int, int, int, int, int, int, void*, void*, void*);
extern "C" int fn_1_A438(void*, void*, int, int);
extern "C" unsigned int fn_1_A5C0(void*, int*, int*);

inline void startTournament(Self* self, Entry* entries, int count, int zero) {
    gfTask* task;
    void* resources = self->unkC;
    task = (gfTask*)operator new(0x380, Heaps::MenuInstance);
    if (task != 0) {
        task = fn_3_A72C(task, zero, zero, zero, zero, count, zero,
                         resources, entries, (void*)zero);
    }
    task->init();
    self->unk8 = task;
}

inline void clearGrid(Self* self, u32& m) {
    for (m = 0; m < 5; m++) {
        for (u32 k = 0; k < 64; k++) {
            self->fill[k] = -1;
        }
        self = (Self*)((char*)self + 0x100);
    }
}

inline void copyRow(Self* row, int* values, u32 base, u32 d, u32& k) {
    for (k = 0; k < d; k++) {
        row->fill[k] = values[base + k];
    }
}

inline void fillRows(
    int* values, u32 n, u32 d, u32& i, u32& k, Self* self)
{
    for (i = 0; i < n / d; i++) {
        copyRow((Self*)((char*)self + i * 0x10), values, i * d, d, k);
    }
}

extern "C" void fn_1_9598(Self* arg0) {
    int nextMatch2;
    void* resources2;
    Header* hdr = (Header*)g_GameGlobal->m_tournamentData;
    u32 n = hdr->count;
    u32 d = hdr->divisor;
    Entry sp148[4];
    int sp18[32];
    char sp98[0xB0];
    int sp14;
    int sp10;
    Entry* ent = sp148;
    const char** fmt = lbl_1_data_2428;
    int count2;
    gfTask* task2;
    u32 idx = 0;
    int r24;
    u32 k;
    u32 i;
    u32 m;

    do {
        ent->a = 0;
        sprintf(ent->name, *fmt);
        ent->b = 0;
        fmt++;
        ent->c = 0;
        ent->d = (int)idx;
        idx++;
        ent++;
    } while (idx < 4);

    void* p = operator new(0x10EC, (Heaps::HeapType)0x2B);
    if (p != 0) {
        p = fn_3_0(p, 0, 0x13);
    }

    arg0->unkC = p;
    arg0->unk518 = 0;
    arg0->unk51C = gfSceneManager::getInstance()->m_memoryLayout;
    if (hdr->unk508 != 0) {
        arg0->unk51C = 2;
    }

    switch (arg0->unk51C) {
    case 0: {
        clearGrid(arg0, m);

        for (i = 0; i < n; i++) {
            sp18[hdr->elems[i].v] = (int)i;
        }

        fillRows(sp18, n, d, i, k, arg0);

        int zero = 0;
        arg0->unk10 = zero;
        arg0->unk14 = zero;
        arg0->unk59C = zero;
        for (k = 0; k < 31; k++) {
            arg0->unk520[k] = -1;
        }

        int r24 = fn_1_A438(arg0, sp148, arg0->unk10, arg0->unk14);
        startTournament(arg0, sp148, r24, zero);

        char* pp = (char*)g_GameGlobal->m_tournamentData;
        for (k = 0; k < 32; k++) {
            char* q = pp + 0x28 * k;
            q[9] = q[8];
        }
        break;
    }

    case 1: {
        u32 t = ((Sub18*)g_GameGlobal->m_resultInfo)->unk1D;
        if (t >= 4) {
            t = 0;
        }

        Header* current = (Header*)g_GameGlobal->m_tournamentData;
        int size = current->divisor - 2;
        int format = current->unk4;
        int round = arg0->unk10;
        int match = arg0->unk14;

        int roundOffset = round * 0x30;
        int sizeOffset = size * 0x6C0;
        int formatOffset = format * 0xC0;
        int matchOffset = match * 3;

        arg0->grid[(lbl_1_data_24A8 + sizeOffset + formatOffset + roundOffset + matchOffset)[0]]
                  [(lbl_1_data_24A8 + sizeOffset + formatOffset + roundOffset + matchOffset)[1]]
                  [(lbl_1_data_24A8 + sizeOffset + formatOffset + roundOffset + matchOffset)[2]] =
            arg0->grid[round][match][t];
        arg0->unk520[arg0->unk59C] =
            arg0->grid[arg0->unk10][arg0->unk14][t];
        arg0->unk59C = arg0->unk59C + 1;

        int r25 = fn_1_A438(arg0, sp148, arg0->unk10, arg0->unk14);
        sp14 = arg0->unk10;
        sp10 = arg0->unk14;
        gfTask* obj;
        int nextMatch;
        void* v30;
        unsigned int r23;
        r23 = fn_1_A5C0(arg0, &sp14, &sp10);
        r24 = fn_1_A438(arg0, sp98, sp14, sp10);
        v30 = arg0->unkC;
        nextMatch = sp10;
        idx = sp14;

        obj = (gfTask*)operator new(0x380, (Heaps::HeapType)0x2A);
        if (obj != 0) {
            obj = fn_3_A72C(
                obj, 1, (int)idx, nextMatch, (int)r23,
                r25, r24, v30, sp148, sp98);
        }
        obj->init();
        arg0->unk8 = obj;

        if (r23 == 0xB) {
            hdr->unk508 = 1;
        } else {
            hdr->unk508 = 0;
        }
        break;
    }

    case 2: {
        u32 t = ((Sub18*)g_GameGlobal->m_resultInfo)->unk1D;
        if (t >= 4) {
            t = 0;
        }

        arg0->unk520[arg0->unk59C] =
            arg0->grid[arg0->unk10][arg0->unk14][t];
        arg0->unk59C = arg0->unk59C + 1;

        count2 = fn_1_A438(arg0, sp148, arg0->unk10, arg0->unk14);
        resources2 = arg0->unkC;
        nextMatch2 = arg0->unk14;
        idx = arg0->unk10;

        task2 = (gfTask*)operator new(0x380, (Heaps::HeapType)0x2A);
        if (task2 != 0) {
            task2 = fn_3_A72C(task2, 2, (int)idx, nextMatch2, 0xB, count2, 0, resources2, sp148, 0);
        }
        task2->init();
        arg0->unk8 = task2;
        hdr->unk508 = 0;
        break;
    }
    }
}
