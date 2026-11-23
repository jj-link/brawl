#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>

#pragma force_active on

extern "C" {
void fn_113_80FC(void*);
void fn_27_1257EC(void*, int, int, int, void*);
void fn_27_14B5F8(void*, void*);
void fn_113_8450(void*, int, int, u8, void*);
void* fn_113_84B8(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_113_8540(void*, void*, int);
void fn_113_8714(void*, void*, void*);
void fn_113_8784(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_113_7FC4(void*, int, void*);
void fn_113_87E8(void*, void*, int, int, void*);
void fn_113_88AC(void*, void*, int, int, void*);
void fn_113_8970(void*, void*, int, int);
void fn_113_8A44(void*, void*, int, int);
void fn_113_8B18(void*, void*, int, int, void*);
void fn_113_8BB0(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_113_8C1C(void*, void*, int);
void fn_113_8C78(void*, void*, int, void*);
void fn_113_8D08(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_113_8D5C(void*, void*, short);
void fn_113_8DCC(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_113_8E38(void*, short);
void fn_113_8E7C(void*, void*, int, int);
void fn_113_9334(void*, void*);
void fn_113_9704(void*);
void fn_113_9764(void*, void*);
void fn_113_9A44(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_113_9B10(void*, void*, u8, void*);
void fn_113_9BA8(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_113_9C08(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A5CA8(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_113_9E30();
void fn_113_9C84(void*, void*, void*, void*);
void fn_113_9CA0(void*, short, void*, int, int, float, signed char*);
void fn_113_9EA0(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_113_9F1C(void*, int);
void fn_113_9F58(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_113_7F94(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);

extern float lbl_113_rodata_0, lbl_113_rodata_4;
extern char lbl_113_data_624[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[], lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_113_data_1CE4[], lbl_113_data_1D8C[];
extern char lbl_113_data_1B5C[], lbl_113_data_1BDC[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
}

class SlopeStorage {
public:
    SlopeStorage(void* accesser, u8 initial, int count, float angle) {
        fn_27_ACAC4(this, accesser, initial, count, initial, angle);
    }
};

class ShadowStorage {
public:
    ShadowStorage(void* accesser, int mode, const float* opacity) {
        fn_27_B62E4(this, accesser, *opacity, mode);
    }
};

class ColorBlendStorage {
public:
    ColorBlendStorage(void* accesser, int count, int enabled) {
        fn_27_BEBB4(this, accesser, count, enabled);
    }
};

class JostleStorage {
public:
    JostleStorage(void* accesser, int id, int count, int data) {
        fn_27_C20D8(this, accesser, id, count, data);
    }
};

class HeapBuildView : public soModuleAccesserBuildData {
public:
    virtual s32 getHeapSlotNo() const = 0;
};

class BuildVirtuals {
public:
    virtual int v08(); virtual int v0c(); virtual int v10(); virtual int v14();
    virtual int v18(); virtual int v1c(); virtual int v20(); virtual int v24();
    virtual int v28(); virtual int v2c(); virtual int v30(); virtual int v34();
    virtual int v38(); virtual int v3c(); virtual int v40(); virtual int v44();
    virtual int v48(); virtual int v4c(); virtual float v50(); virtual int v54();
    virtual int v58(); virtual int v5c(); virtual int v60(); virtual int v64();
    virtual int v68(); virtual int v6c(); virtual int v70(); virtual int v74();
    virtual int v78(); virtual int v7c(); virtual int v80(); virtual int v84();
    virtual float v88(); virtual int v8c(); virtual void* v90(int, int);
};

class ValueVirtuals {
public:
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual int v24();
};

class CheckVirtual {
public:
    virtual int v08();
};

class RegisterVirtual {
public:
    virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(int, void*);
};

class PairRegister {
public:
    virtual void v08(); virtual void v0c(void**, short*);
};

class ModuleVirtuals {
public:
    virtual void v08(); virtual void v0c(void*);
    virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(void*);
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(void**, int);
    virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8c(void*);
};


struct Locals {
    signed char flags[11];
    char pad0;
    short kinds[11];
    char pad1[2];
    void* pairs[22];
    char buildData[0x30];
};

#define PTR(p, o) (*(void**)((char*)(p) + (o)))
#define INT(p, o) (*(int*)((char*)(p) + (o)))
#define VALUE() ((ValueVirtuals*)((char*)PTR(PTR(storage, 0xAA8), 0x80) + 8))->v24()
#define BUILD ((BuildVirtuals*)local.buildData)
#define PAIR(i, a, b, k) \
    local.kinds[i] = (k); \
    local.pairs[2 * (i)] = (a); \
    local.pairs[2 * (i) + 1] = (b); \
    ((PairRegister*)PTR(PTR(storage, 0xAA8), 0x6C))->v0c( \
        &local.pairs[2 * (i)], &local.kinds[i])

#define SET_FIGHTER_TABLE(label) \
    { \
        char* table = label; \
        PTR(self, 0x3C) = table; \
        PTR(self, 0x40) = table + 0x64; \
        PTR(self, 0x48) = table + 0x70; \
        PTR(self, 0x54) = table + 0x84; \
        PTR(self, 0x64) = table + 0xDC; \
        PTR(self, 0x70) = table + 0xEC; \
        PTR(self, 0x7C) = table + 0xFC; \
        PTR(self, 0x88) = table + 0x110; \
        PTR(self, 0x94) = table + 0x128; \
        PTR(self, 0xA0) = table + 0x140; \
        PTR(self, 0xAC) = table + 0x158; \
        PTR(self, 0xB8) = table + 0x16C; \
        PTR(self, 0xC4) = table + 0x180; \
        PTR(self, 0xD0) = table + 0x190; \
        PTR(self, 0xDC) = table + 0x1C4; \
        PTR(self, 0xE8) = table + 0x1D4; \
        PTR(self, 0xF4) = table + 0x1E8; \
        PTR(self, 0x100) = table + 0x254; \
    }

#define SETUP_SCRIPT(i, offset, count, kind, declaration, target) \
    BUILD->v90(i, 2); \
    BUILD->v90(i, 1); \
    void* scriptData##i = BUILD->v90(i, 0); \
    { \
        declaration target = scripts + offset; \
        fn_27_C7744(target, scriptData##i, count); \
        fn_27_D22D0(target + 0x14, 0); \
        fn_113_9C84(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[10 - (i)] = 0; \
        int value = VALUE(); \
        fn_113_9CA0(target + 0xDC, (short)value, target + 0x14, i, 1, \
            lbl_113_rodata_4, &local.flags[10 - (i)]); \
        PAIR(10 - (i), target + 0xDC, target + 0xC0, kind); \
    }

#define SETUP_LISTENER(offset, table) { \
    leaf = listeners + (offset); \
    fn_27_17437C(leaf, scripts); \
    PTR(leaf, 0) = (table); \
    PTR(leaf, 4) = (table) + 0x40; \
}

extern "C" void* fn_113_688C(char* self, int entryId, s32 heap1, s32 heap2, s32 heap3) {
    Locals local;
    fn_27_1257EC(self, entryId, 0x19, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_113_data_624)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)0x19, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap2, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0x1FCF4, self + 0x1FCFC);
    char* extraCommand;
    char* leaf;
    char* storage = self + 0x194;
    char* scripts;
    fn_113_80FC(storage);

    new (storage + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(storage + 0x1168),
        reinterpret_cast<soModelModule*>(storage + 0x1374),
        reinterpret_cast<soMotionModule*>(storage + 0x1664),
        reinterpret_cast<soPostureModule*>(storage + 0x1810),
        reinterpret_cast<soGroundModule*>(storage + 0x18D8),
        reinterpret_cast<soSituationModule*>(storage + 0x1930),
        storage + 0x199C,
        reinterpret_cast<soCollisionAttackModule*>(storage + 0x1FFC),
        reinterpret_cast<soCollisionHitModule*>(storage + 0x2990),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x2BBC),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x3624),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        storage + 0x37F8,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(storage + 0x398C),
        storage + 0x3A90, storage + 0x3AF4,
        reinterpret_cast<soStopModule*>(storage + 0x3B28),
        storage + 0x3B4C, storage + 0x3C00,
        reinterpret_cast<soSoundModule*>(storage + 0x3C30),
        reinterpret_cast<soLinkModule*>(storage + 0x3F3C),
        reinterpret_cast<soVisibilityModule*>(storage + 0x3F90),
        reinterpret_cast<soControllerModule*>(storage + 0x4578),
        reinterpret_cast<soCameraModule*>(storage + 0x4734),
        reinterpret_cast<soWorkManageModule*>(storage + 0x4758),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x478C),
        reinterpret_cast<soStatusModule*>(storage + 0x5644),
        lbl_27_bss_46C0, lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x56F4),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0x1D41C,
        reinterpret_cast<soEffectModule*>(storage + 0x1D4C4),
        storage + 0x1D5FC,
        reinterpret_cast<soAreaModule*>(storage + 0x1D63C),
        lbl_27_bss_5B0, lbl_27_bss_5D8,
        storage + 0x1DA1C, storage + 0x1DA64,
        reinterpret_cast<soShadowModule*>(storage + 0x1DAE4),
        reinterpret_cast<soItemManageModule*>(storage + 0x1DBD0),
        reinterpret_cast<soColorBlendModule*>(storage + 0x1DC3C),
        storage + 0x1DD90, storage + 0x1DDDC,
        reinterpret_cast<soSlowModule*>(storage + 0x1DE44),
        lbl_27_bss_69C, storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0x1DE80);

    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getHeapSlotNo();
    heap3 = ((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    heap1 = ((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    char* command;
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap3, (long)motionCommand);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_113_8450(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_113_84B8(storage + 0x1180, (soModuleAccesser*)(storage + 0x9D0), modelScale,
        motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_113_8540(storage + 0x1440, storage + 0x9D0, motionValue);
    fn_113_8714(storage + 0x17D4, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_113_8784(storage + 0x1888, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x1930, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_113_7FC4(storage + 0x196C, collisionValue, storage + 0x9D0);
    fn_113_87E8(storage + 0x19E0, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_113_88AC(storage + 0x209C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_113_8970(storage + 0x29F8, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_113_8A44(storage + 0x2C10, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_113_8B18(storage + 0x367C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_113_8BB0(storage + 0x38E0, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x3A90, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x3AF4, storage + 0x9D0);
    fn_27_154088(storage + 0x3B28, storage + 0x9D0);
    fn_27_693F4(storage + 0x3B4C, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_113_8C1C(storage + 0x3B84, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_113_8C78(storage + 0x3C1C, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_113_8D08(storage + 0x3C8C, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x3F90, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_113_8D5C(storage + 0x3FC0, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_113_8DCC(storage + 0x46E4, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x4758, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_113_8E38(storage + 0x478C, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_113_8E7C(storage + 0x4880, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_113_9334(storage + 0x56F4, storage + 0x9D0);
    fn_113_9704(storage + 0x59FC);
    fn_113_9764(storage + 0x5BE0, storage + 0x9D0);

    entryId = BUILD->v38();
    heap3 = BUILD->v34();
    motionCommand = (char*)BUILD->v30();
    int animValue1 = BUILD->v2c();
    fn_113_9A44(storage + 0x1D458, storage + 0x9D0, animValue1, (int)motionCommand,
        heap3, entryId, lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0x1D5FC, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_113_9B10(storage + 0x1D62C, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_113_9BA8(storage + 0x1D9A0, storage + 0x9D0, kineticValue);
    new (storage + 0x1DA64) SlopeStorage(storage + 0x9D0, 0, 1, BUILD->v88());
    new (storage + 0x1DAE4) ShadowStorage(storage + 0x9D0, 0, &lbl_113_rodata_0);
    int effectValue = BUILD->v64();
    fn_113_9C08(storage + 0x1DB2C, storage + 0x9D0, effectValue);
    new (storage + 0x1DC3C) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0x1DD90) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0x1DDDC, storage + 0x9D0);
    fn_27_5BED0(storage + 0x1DE44, storage + 0x9D0);
    fn_27_14CCEC(storage + 0x1DE80, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x5BBC))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x5BBC);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0x1E000, PTR(fighterData, 0x18), 0xA);
    scripts = storage + 0x1E010;
    fn_27_1A5CA8(scripts, 0);
    fn_27_1A5CA8(scripts + 0x47C, 0);
    fn_27_D22D0(scripts + 0x8FC, 0);
    void* defaultScript = fn_113_9E30();
    fn_113_9C84(scripts + 0x9A8, scripts, scripts + 0x47C, defaultScript);
    local.flags[10] = 0;
    int scriptValue = VALUE();
    fn_113_9CA0(scripts + 0x9C4, (short)scriptValue, scripts + 0x8FC, 0, 1,
        lbl_113_rodata_4, &local.flags[10]);
    fn_113_9EA0(scripts, 0, 0x11C);
    fn_113_9EA0(scripts + 0x47C, 0, 0x11C);
    fn_113_9EA0(fn_113_9E30(), 0, 0);
    PAIR(10, scripts + 0x9C4, scripts + 0x9A8, 1);

    SETUP_SCRIPT(1, 0xA14, 0x1E0, 0x2, , extraCommand)
    SETUP_SCRIPT(2, 0xB40, 0x1E0, 0x40, , command)
    SETUP_SCRIPT(3, 0xC6C, 0x1E0, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xD98, 0x1E0, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xEC4, 0x1E0, 0x20, char*, command)
    SETUP_SCRIPT(6, 0xFF0, 0x1E0, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x111C, 0x1E0, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1248, 0x1E0, 0x20, char*, command)
    {
        char* command = scripts + 0x1374;
        local.flags[1] = 1;
        int value = VALUE();
        fn_113_9CA0(command, (short)value, command + 0x50, 9, 1,
            lbl_113_rodata_4, &local.flags[1]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(1, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x1498, 0x29, 0x10, char*, command)

    {
        void* main0 = BUILD->v90(0, 0);
        fn_113_9EA0(fn_113_9F1C(scripts, 0), main0, 0x112);
    }
    {
        void* main1 = BUILD->v90(0, 1);
        fn_113_9EA0(fn_113_9F1C(scripts, 1), main1, 0x112);
    }
    fn_113_9EA0(fn_113_9F1C(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 0xA);
    fn_113_9EA0(fn_113_9F1C(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 0xA);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_113_9F58(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_113_9F58(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0x1E000);
    void* constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_113_data_1CE4, lbl_113_data_1D8C, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0x1F768, PTR(self, 0x60));
    {
        char* part = self + 0x1F7A4;
        fn_113_7F94(part, 0);
        PTR(part, 0) = lbl_113_data_1B5C;
    }
    scripts = (char*)PTR(self, 0x60);
    char* listeners = self + 0x1FC5C;
    fn_113_7F94(listeners, 0);
    PTR(listeners, 0) = lbl_113_data_1BDC;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    {
        char* leaf = listeners + 0x84;
        fn_27_17437C(leaf, scripts);
        PTR(leaf, 0) = lbl_27_data_2FDE8;
        PTR(leaf, 4) = lbl_27_data_2FDE8 + 0x40;
    }

    PTR(self, 0x1FCF4) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0x1FCF8) = 1;
    PTR(self, 0x1FCFC) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0x1FD00) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0x1F768))->v0c(PTR(self, 0x60));
    return self;
}
