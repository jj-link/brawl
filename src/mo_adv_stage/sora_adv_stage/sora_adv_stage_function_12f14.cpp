#include <gm/gm_global.h>
#include <em/em_create.h>
#include <em/em_manager.h>
#include <ut/ut_relocate.h>
#include <so/so_archive_db.h>
#pragma force_active on

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_1E5E0();
    virtual void fn_40_1E2A0();
    virtual void fn_40_1DE6C();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC(int*);
    char pad[0x184];
    int capacity;
    int count;
};
class Class_6C68 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_24BA4();
    virtual void fn_40_1E2A0();
    virtual void fn_40_24864();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC(int*);
};
class Class_83C8 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual void fn_40_28908();
    virtual void fn_40_28604();
    virtual void fn_40_281E8();
    virtual void fn_40_28D54();
    virtual void fn_40_28E10();
    virtual void fn_40_295B0();
    virtual void fn_40_28A38();
    virtual void fn_40_282E8(int*);
};
class Class_CEC8 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_30C08();
    virtual void fn_40_1E2A0();
    virtual void fn_40_30890();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC(int*);
};
class Class_D270 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual void fn_40_30D68();
    virtual void fn_40_28604();
    virtual void fn_40_30990();
    virtual void fn_40_28D54();
    virtual void fn_40_28E10();
    virtual void fn_40_295B0();
    virtual void fn_40_28A38();
    virtual void fn_40_282E8(int*);
};

struct AdvStageDataView {
    u8 pad0[0x5FD];
    u8 current;
    u8 pad1[0x4916 - 0x5FE];
    u8 previous;
};
struct EnemyParams {
    char pad0[0xC];
    u16 trigger;
    char padE[0xE];
    u16 kind;
    char pad1E[2];
    u32 status;
    char pad24[4];
    Vec3f pos;
    float value;
    Rect2D range;
    char pad48[0x1C];
    u8 level;
    char pad65[2];
    u8 facing;
    u8 respawn;
    char pad69[0xB];
    u8 limit;
};
struct EnemySlot {
    u8 active;
    u8 flag1;
    u8 flag2;
    u8 pad3;
    Enemy* enemy;
    int id;
    int state;
    float timer;
    char pad14[8];
};
struct Self {
    char pad0[0x90];
    EnemyParams* params;
    EnemySlot* slots;
    grGimmickMotionPath* motionPath;
    char pad9C[4];
    u8* archive0;
    u8* archive1;
    char padA8[4];
    int remaining;
    char padB0[2];
    u8 spawned;
    char padB3;
    int lastSlot;
};
struct Override {
    int team;
    Vec3f pos;
    float lr;
    u32 status;
    u8 level;
    int parent;
};
struct ArchiveEntry {
    u32 first;
    u32 unused;
    u32 second;
};
extern emManager* lbl_41_bss_30;
extern Class_5648* lbl_27_bss_5B98;
extern float lbl_40_rodata_1B0[];
extern char lbl_40_data_29A8[];
extern char lbl_40_data_2DD8[];

extern "C" {
    ArchiveEntry* fn_41_D770(emManager*, int);
    void fn_8004689C(utArchiveManager*, u8*, u32, u32, int, int);
    void fn_40_B48(const char*, ...);
    void* fn_40_16DD8();
    void* fn_40_17398(void*);
    void fn_40_15DA0(void*, int);
}

extern "C" int fn_40_12F14(Self* self, int slot, Override* over)
{
    float* constants = lbl_40_rodata_1B0;
    if (!lbl_41_bss_30 || !emManager::getInstance()->isCompArchiveAll())
        return -1;
    emCreate create;
    create.m_teamNo = 10000;
    AdvStageDataView* data = (AdvStageDataView*)g_GameGlobal->m_advData;
    u8 current = data->current;
    u8 previous = data->previous;
    int value = current - previous;
    int lower = current - 5;
    if (value < lower) value = lower;
    if (value < 0) value = 0;
    if (value > 14) value = 14;
    create.m_difficulty = value;
    create.m_enemyKind = (EnemyKind)self->params->kind;
    create.m_startStatusKind = self->params->status;
    create.m_startPos = self->params->pos;
    if (self->params->facing == 0)
        create.m_startLr = constants[7];
    else
        create.m_startLr = constants[8];
    create.m_level = self->params->level;
    create.m_36 = self->params->value;
    create.m_territoryRange = self->params->range;
    create.m_connectedTriggerId = self->params->trigger;
    if (over) {
        create.m_teamNo = over->team;
        create.m_startStatusKind = over->status;
        create.m_startPos = over->pos;
        create.m_startLr = over->lr;
        create.m_level = over->level;
        create.m_parentCreateId = over->parent;
    }
    create.m_motionPath = self->motionPath;
    if (self->archive0) {
        utRelocate relocate(self->archive0, *(u32*)self->archive0);
        create.m_epbm = *(void**)relocate.getPublicAddress(lbl_40_data_29A8);
    }
    u32 first;
    u8* archive = self->archive1;
    if (archive) {
        u32 size = *(u32*)archive;
        ArchiveEntry* entry = fn_41_D770(emManager::getInstance(), create.m_enemyKind);
        if (entry) {
            first = entry->first;
            if (first != 0xFFFF)
                fn_8004689C(soArchiveDb::getManager(1), archive, size, first, 0, 0);
            entry = (ArchiveEntry*)entry->second;
            if ((u32)entry != 0xFFFF)
                fn_8004689C(soArchiveDb::getManager(1), archive, size, (u32)entry, 0, 0);
        }
        utRelocate relocate(archive, size);
        create.m_epsp = *(UnkParamAccesser**)relocate.getPublicAddress(lbl_40_data_29A8);
    }
    int offset;
    int id = -1;
    if (lbl_41_bss_30) {
        id = emManager::getInstance()->createEnemy(&create);
        if (id < 0) {
            self->slots[slot].active = 0;
            if ((self->params->limit == 0 || self->params->limit > self->spawned) &&
                self->params->respawn != 0) {
                self->remaining--;
                self->spawned++;
            }
            return -1;
        }
        offset = slot * 0x1C;
        ((EnemySlot*)((u8*)self->slots + offset))->id = id;
        Enemy* enemy = emManager::getInstance()->getEnemyPtrFromId(((EnemySlot*)((u8*)self->slots + offset))->id);
        float zero = constants[0];
        ((EnemySlot*)((u8*)self->slots + offset))->enemy = enemy;
        ((EnemySlot*)((u8*)self->slots + offset))->active = 1;
        ((EnemySlot*)((u8*)self->slots + offset))->timer = zero;
        ((EnemySlot*)((u8*)self->slots + offset))->state = 4;
        ((EnemySlot*)((u8*)self->slots + offset))->flag1 = 0;
        ((EnemySlot*)((u8*)self->slots + offset))->flag2 = 1;
        Class_5648* list = lbl_27_bss_5B98;
        if (list) {
            int storedId = id;
            if (list->count >= list->capacity)
                fn_40_B48(lbl_40_data_2DD8);
            else {
                list->fn_40_1DFBC(&storedId);
                list->count++;
            }
        }
        fn_40_15DA0(fn_40_17398(fn_40_16DD8()), ((EnemySlot*)((u8*)self->slots + offset))->id);
        self->lastSlot = slot;
    }
    return id;
}
