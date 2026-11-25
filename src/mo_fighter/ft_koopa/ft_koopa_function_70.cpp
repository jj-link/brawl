#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>

#pragma force_active on

inline void* operator new[](size_t, void* storage) { return storage; }

extern "C" {
void fn_27_1257EC(void*, int, int, int, void*);
void fn_27_14B5F8(void*, void*);
void fn_102_6504(void*, int, int, u8, void*);
void* fn_102_656C(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_102_65F4(void*, void*, int);
void fn_102_67C8(void*, void*, void*);
void fn_102_6838(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_102_60E4(void*, int, void*);
void fn_102_689C(void*, void*, int, int, void*);
void fn_102_6960(void*, void*, int, int, void*);
void fn_102_6A24(void*, void*, int, int);
void fn_102_6AF8(void*, void*, int, int);
void fn_102_6BCC(void*, void*, int, int, void*);
void fn_102_6C64(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_102_6CD0(void*, void*, int);
void fn_102_6D2C(void*, void*, int, void*);
void fn_102_6DBC(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_102_6E10(void*, void*, short);
void fn_102_6E80(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_102_6EEC(void*, short);
void fn_102_6F30(void*, void*, int, int);
void fn_102_73E8(void*, void*);
void fn_102_77B8(void*);
void fn_102_7818(void*, void*);
void fn_102_79F4(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_102_7AC0(void*, void*, u8, void*);
void fn_102_7B58(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_102_7BB8(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A63C4(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_102_7DE0();
void fn_102_7C34(void*, void*, void*, void*);
void fn_102_7C50(void*, short, void*, int, int, float, signed char*);
void fn_102_7E50(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_102_7ECC(void*, int);
void fn_102_7F08(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_102_60D0(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_102_61B0(void*);

extern float lbl_102_rodata_0, lbl_102_rodata_4;
extern char lbl_102_data_5E0[], lbl_102_data_FC[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[], lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_102_data_1344[], lbl_102_data_13EC[];
extern char lbl_102_data_11BC[], lbl_102_data_123C[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_7D74[];
extern char lbl_102_bss_22C[], lbl_102_bss_23C[], lbl_102_bss_24C[];
extern char lbl_102_bss_25C[], lbl_102_bss_26C[], lbl_102_bss_27C[];
extern char lbl_102_bss_28C[], lbl_102_bss_29C[], lbl_102_bss_2AC[];
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
    u32 buildData[0x30 / sizeof(u32)];
    void* finalData[17];
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
        fn_102_7C34(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[i] = 0; \
        int value = VALUE(); \
        fn_102_7C50(target + 0xDC, (short)value, target + 0x14, i, 1, \
            lbl_102_rodata_4, &local.flags[i]); \
        PAIR(i, target + 0xDC, target + 0xC0, kind); \
    }

template<char* table>
class KoopaActionLeaf {
public:
    KoopaActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) KoopaActionLeaf<label>(storage);

extern "C" void* fn_102_70(char* self, int entryId, s32 heap1, s32 heap2, s32 heap3) {
    char* part;
    void* accesser;
    Locals local;
    fn_27_1257EC(self, entryId, 11, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_102_data_5E0)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)11, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap2, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0x1415C, self + 0x14164);
    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* scripts;
    char* storage = self + 0x194;
    fn_102_61B0(storage);

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
        storage + 0x3A90,
        storage + 0x3AF4,
        reinterpret_cast<soStopModule*>(storage + 0x3B28),
        storage + 0x3B4C,
        storage + 0x3C00,
        reinterpret_cast<soSoundModule*>(storage + 0x3C30),
        reinterpret_cast<soLinkModule*>(storage + 0x3DD0),
        reinterpret_cast<soVisibilityModule*>(storage + 0x3E24),
        reinterpret_cast<soControllerModule*>(storage + 0x440C),
        reinterpret_cast<soCameraModule*>(storage + 0x45C8),
        reinterpret_cast<soWorkManageModule*>(storage + 0x45EC),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x4620),
        reinterpret_cast<soStatusModule*>(storage + 0x54F0),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x55A0),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0x1184C,
        reinterpret_cast<soEffectModule*>(storage + 0x118F4),
        storage + 0x11A2C,
        reinterpret_cast<soAreaModule*>(storage + 0x11A6C),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        storage + 0x11E4C,
        storage + 0x11E94,
        reinterpret_cast<soShadowModule*>(storage + 0x11F14),
        reinterpret_cast<soItemManageModule*>(storage + 0x12000),
        reinterpret_cast<soColorBlendModule*>(storage + 0x1206C),
        storage + 0x121C0,
        storage + 0x1220C,
        reinterpret_cast<soSlowModule*>(storage + 0x12274),
        lbl_27_bss_69C,
        storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0x122B0);

    heap2 = ((HeapBuildView*)local.buildData)->getHeapSlotNo();
    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    char* command = (char*)((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, heap2);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_102_6504(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_102_656C(storage + 0x1180, (soModuleAccesser*)(storage + 0x9D0), modelScale,
        motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_102_65F4(storage + 0x1440, storage + 0x9D0, motionValue);
    fn_102_67C8(storage + 0x17D4, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_102_6838(storage + 0x1888, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x1930, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_102_60E4(storage + 0x196C, collisionValue, storage + 0x9D0);
    fn_102_689C(storage + 0x19E0, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_102_6960(storage + 0x209C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_102_6A24(storage + 0x29F8, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_102_6AF8(storage + 0x2C10, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_102_6BCC(storage + 0x367C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_102_6C64(storage + 0x38E0, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x3A90, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x3AF4, storage + 0x9D0);
    fn_27_154088(storage + 0x3B28, storage + 0x9D0);
    fn_27_693F4(storage + 0x3B4C, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_102_6CD0(storage + 0x3B84, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_102_6D2C(storage + 0x3C1C, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_102_6DBC(storage + 0x3C8C, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x3E24, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_102_6E10(storage + 0x3E54, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_102_6E80(storage + 0x4578, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x45EC, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_102_6EEC(storage + 0x4620, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_102_6F30(storage + 0x4714, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_102_73E8(storage + 0x55A0, storage + 0x9D0);
    fn_102_77B8(storage + 0x58A8);
    fn_102_7818(storage + 0x5A8C, storage + 0x9D0);

    entryId = BUILD->v38();
    heap2 = BUILD->v34();
    motionCommand = (char*)BUILD->v30();
    int animValue1 = BUILD->v2c();
    fn_102_79F4(storage + 0x11888, storage + 0x9D0, animValue1, (int)motionCommand,
        heap2, entryId, lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0x11A2C, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_102_7AC0(storage + 0x11A5C, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_102_7B58(storage + 0x11DD0, storage + 0x9D0, kineticValue);
    new (storage + 0x11E94) SlopeStorage(storage + 0x9D0, 0, 1, BUILD->v88());
    new (storage + 0x11F14) ShadowStorage(storage + 0x9D0, 0, &lbl_102_rodata_0);
    int effectValue = BUILD->v64();
    fn_102_7BB8(storage + 0x11F5C, storage + 0x9D0, effectValue);
    new (storage + 0x1206C) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0x121C0) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0x1220C, storage + 0x9D0);
    fn_27_5BED0(storage + 0x12274, storage + 0x9D0);
    fn_27_14CCEC(storage + 0x122B0, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x5A68))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x5A68);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0x12430, PTR(fighterData, 0x18), 0x11);
    scripts = storage + 0x12440;
    fn_27_1A63C4(scripts, 0);
    fn_27_1A63C4(scripts + 0x498, 0);
    fn_27_D22D0(scripts + 0x934, 0);
    void* defaultScript = fn_102_7DE0();
    fn_102_7C34(scripts + 0x9E0, scripts, scripts + 0x498, defaultScript);
    local.flags[0] = 0;
    int scriptValue = VALUE();
    fn_102_7C50(scripts + 0x9FC, (short)scriptValue, scripts + 0x934, 0, 1,
        lbl_102_rodata_4, &local.flags[0]);
    fn_102_7E50(scripts, 0, 0x123);
    fn_102_7E50(scripts + 0x498, 0, 0x123);
    fn_102_7E50(fn_102_7DE0(), 0, 0);
    PAIR(0, scripts + 0x9FC, scripts + 0x9E0, 1);

    SETUP_SCRIPT(1, 0xA4C, 0x1E3, 0x2, char*, command)
    SETUP_SCRIPT(2, 0xB78, 0x1E3, 0x40, , command)
    SETUP_SCRIPT(3, 0xCA4, 0x1E3, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xDD0, 0x1E3, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xEFC, 0x1E3, 0x20, char*, command)
    SETUP_SCRIPT(6, 0x1028, 0x1E3, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x1154, 0x1E3, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1280, 0x1E3, 0x20, , motionCommand)
    {
        extraCommand = scripts + 0x13AC;
        char* command = extraCommand;
        local.flags[9] = 1;
        int value = VALUE();
        fn_102_7C50(command, (short)value, command + 0x50, 9, 1,
            lbl_102_rodata_4, &local.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x14D0, 0x29, 0x10, , finalCommand)

    main0 = BUILD->v90(0, 0);
    fn_102_7E50(fn_102_7ECC(scripts, 0), main0, 0x112);
    main1 = BUILD->v90(0, 1);
    fn_102_7E50(fn_102_7ECC(scripts, 1), main1, 0x112);
    fn_102_7E50(fn_102_7ECC(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 0x11);
    fn_102_7E50(fn_102_7ECC(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 0x11);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_102_7F08(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_102_7F08(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0x12430);
    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_102_data_1344, lbl_102_data_13EC, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0x13BD0, PTR(self, 0x60));
    {
        part = self + 0x13C0C;
        fn_102_60D0(part, 0);
        PTR(part, 0) = lbl_102_data_11BC;
    }
    storage = (char*)PTR(self, 0x60);
    listeners = self + 0x140C4;
    fn_102_60D0(listeners, 0);
    PTR(listeners, 0) = lbl_102_data_123C;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(self, 0x1415C) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0x14160) = 1;
    PTR(self, 0x14164) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0x14168) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0x13BD0))->v0c(PTR(self, 0x60));
    SET_FIGHTER_TABLE(lbl_102_data_FC)

    fn_27_C749C(self + 0x1416C);
    PTR(self, 0x1417C) = g_ftCommonDataAccesser.getData((ftKind)11);
    typedef void* StatusPointer;
    new (local.finalData) StatusPointer[17]();
    local.finalData[0] = lbl_27_bss_7D74;
    local.finalData[5] = lbl_102_bss_22C;
    local.finalData[6] = lbl_102_bss_23C;
    local.finalData[7] = lbl_102_bss_25C;
    local.finalData[8] = lbl_102_bss_24C;
    local.finalData[10] = lbl_102_bss_26C;
    local.finalData[11] = lbl_102_bss_26C;
    local.finalData[12] = lbl_102_bss_27C;
    local.finalData[13] = lbl_102_bss_28C;
    local.finalData[14] = lbl_102_bss_29C;
    local.finalData[15] = lbl_102_bss_2AC;
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v78(local.finalData, 17);
    return self;
}
