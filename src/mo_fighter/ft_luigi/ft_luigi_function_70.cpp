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
void fn_99_64D4(void*, int, int, u8, void*);
void* fn_99_653C(void*, void*, float, void*, void*);
void fn_99_65C4(void*, void*, int);
void fn_99_6798(void*, void*, void*);
void fn_99_6808(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_99_60B4(void*, int, void*);
void fn_99_686C(void*, void*, int, int, void*);
void fn_99_6930(void*, void*, int, int, void*);
void fn_99_69F4(void*, void*, int, int);
void fn_99_6AC8(void*, void*, int, int);
void fn_99_6B9C(void*, void*, int, int, void*);
void fn_99_6C34(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_99_6CA0(void*, void*, int);
void fn_99_6CFC(void*, void*, int, void*);
void fn_99_6D8C(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_99_6DE0(void*, void*, short);
void fn_99_6E50(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_99_6EBC(void*, short);
void fn_99_6F00(void*, void*, int, int);
void fn_99_73B8(void*, void*);
void fn_99_7788(void*);
void fn_99_77E8(void*, void*);
void fn_99_79C8(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_99_7A94(void*, void*, u8, void*);
void fn_99_7B2C(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_99_7B8C(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A5DAC(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_99_7DB4();
void fn_99_7C08(void*, void*, void*, void*);
void fn_99_7C24(void*, short, void*, int, int, float, signed char*);
void fn_99_7E24(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_99_7EA0(void*, int);
void fn_99_7EDC(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_99_60A0(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void __ct__17LuigiEventStorageFv(void*);

extern float lbl_99_rodata_0, lbl_99_rodata_4;
extern char lbl_99_data_5E0[], lbl_99_data_FC[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[], lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_99_data_156C[], lbl_99_data_1614[];
extern char lbl_99_data_13E4[], lbl_99_data_1464[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_734C[];
extern char lbl_99_bss_1CC[], lbl_99_bss_1DC[], lbl_99_bss_1EC[];
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
    void* finalData[11];
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
        fn_99_7C08(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[i] = 0; \
        int value = VALUE(); \
        fn_99_7C24(target + 0xDC, (short)value, target + 0x14, i, 1, \
            lbl_99_rodata_4, &local.flags[i]); \
        PAIR(i, target + 0xDC, target + 0xC0, kind); \
    }

template<char* table>
class LuigiActionLeaf {
public:
    LuigiActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) LuigiActionLeaf<label>(storage);

extern "C" void* fn_99_70(char* self, int entryId, s32 heap1, s32 heap2, s32 heap3) {
    char* part;
    void* accesser;
    Locals local;
    fn_27_1257EC(self, entryId, 8, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_99_data_5E0)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)8, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap2, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0xE1E4, self + 0xE1EC);
    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* scripts;
    char* storage = self + 0x194;
    __ct__17LuigiEventStorageFv(storage);

    new (storage + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(storage + 0x1168),
        reinterpret_cast<soModelModule*>(storage + 0x1410),
        reinterpret_cast<soMotionModule*>(storage + 0x1700),
        reinterpret_cast<soPostureModule*>(storage + 0x18AC),
        reinterpret_cast<soGroundModule*>(storage + 0x1974),
        reinterpret_cast<soSituationModule*>(storage + 0x19CC),
        storage + 0x1A38,
        reinterpret_cast<soCollisionAttackModule*>(storage + 0x2098),
        reinterpret_cast<soCollisionHitModule*>(storage + 0x2A2C),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x2C58),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x34F0),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        storage + 0x36C4,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(storage + 0x3858),
        storage + 0x395C,
        storage + 0x39C0,
        reinterpret_cast<soStopModule*>(storage + 0x39F4),
        storage + 0x3A18,
        storage + 0x3ACC,
        reinterpret_cast<soSoundModule*>(storage + 0x3AFC),
        reinterpret_cast<soLinkModule*>(storage + 0x3C9C),
        reinterpret_cast<soVisibilityModule*>(storage + 0x3CF0),
        reinterpret_cast<soControllerModule*>(storage + 0x42D8),
        reinterpret_cast<soCameraModule*>(storage + 0x4494),
        reinterpret_cast<soWorkManageModule*>(storage + 0x44B8),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x44EC),
        reinterpret_cast<soStatusModule*>(storage + 0x53A4),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x5454),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0xB904,
        reinterpret_cast<soEffectModule*>(storage + 0xB9AC),
        storage + 0xBAE4,
        reinterpret_cast<soAreaModule*>(storage + 0xBB24),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        storage + 0xBF04,
        storage + 0xBF4C,
        reinterpret_cast<soShadowModule*>(storage + 0xBFCC),
        reinterpret_cast<soItemManageModule*>(storage + 0xC0B8),
        reinterpret_cast<soColorBlendModule*>(storage + 0xC124),
        storage + 0xC278,
        storage + 0xC2C4,
        reinterpret_cast<soSlowModule*>(storage + 0xC32C),
        lbl_27_bss_69C,
        storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0xC368);

    heap2 = ((HeapBuildView*)local.buildData)->getHeapSlotNo();
    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    char* command = (char*)((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, heap2);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_99_64D4(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_99_653C(storage + 0x1180, storage + 0x9D0, modelScale,
        motionCommand, lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_99_65C4(storage + 0x14DC, storage + 0x9D0, motionValue);
    fn_99_6798(storage + 0x1870, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_99_6808(storage + 0x1924, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x19CC, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_99_60B4(storage + 0x1A08, collisionValue, storage + 0x9D0);
    fn_99_686C(storage + 0x1A7C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_99_6930(storage + 0x2138, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_99_69F4(storage + 0x2A94, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_99_6AC8(storage + 0x2CAC, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_99_6B9C(storage + 0x3548, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_99_6C34(storage + 0x37AC, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x395C, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x39C0, storage + 0x9D0);
    fn_27_154088(storage + 0x39F4, storage + 0x9D0);
    fn_27_693F4(storage + 0x3A18, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_99_6CA0(storage + 0x3A50, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_99_6CFC(storage + 0x3AE8, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_99_6D8C(storage + 0x3B58, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x3CF0, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_99_6DE0(storage + 0x3D20, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_99_6E50(storage + 0x4444, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x44B8, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_99_6EBC(storage + 0x44EC, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_99_6F00(storage + 0x45E0, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_99_73B8(storage + 0x5454, storage + 0x9D0);
    fn_99_7788(storage + 0x575C);
    fn_99_77E8(storage + 0x5940, storage + 0x9D0);

    entryId = BUILD->v38();
    heap2 = BUILD->v34();
    motionCommand = (char*)BUILD->v30();
    int animValue1 = BUILD->v2c();
    fn_99_79C8(storage + 0xB940, storage + 0x9D0, animValue1, (int)motionCommand,
        heap2, entryId, lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0xBAE4, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_99_7A94(storage + 0xBB14, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_99_7B2C(storage + 0xBE88, storage + 0x9D0, kineticValue);
    new (storage + 0xBF4C) SlopeStorage(storage + 0x9D0, 0, 1, BUILD->v88());
    new (storage + 0xBFCC) ShadowStorage(storage + 0x9D0, 0, &lbl_99_rodata_0);
    int effectValue = BUILD->v64();
    fn_99_7B8C(storage + 0xC014, storage + 0x9D0, effectValue);
    new (storage + 0xC124) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0xC278) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0xC2C4, storage + 0x9D0);
    fn_27_5BED0(storage + 0xC32C, storage + 0x9D0);
    fn_27_14CCEC(storage + 0xC368, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x591C))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x591C);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0xC4E8, PTR(fighterData, 0x18), 11);
    scripts = storage + 0xC4F8;
    fn_27_1A5DAC(scripts, 0);
    fn_27_1A5DAC(scripts + 0x480, 0);
    fn_27_D22D0(scripts + 0x904, 0);
    void* defaultScript = fn_99_7DB4();
    fn_99_7C08(scripts + 0x9B0, scripts, scripts + 0x480, defaultScript);
    local.flags[0] = 0;
    int scriptValue = VALUE();
    fn_99_7C24(scripts + 0x9CC, (short)scriptValue, scripts + 0x904, 0, 1,
        lbl_99_rodata_4, &local.flags[0]);
    fn_99_7E24(scripts, 0, 0x11D);
    fn_99_7E24(scripts + 0x480, 0, 0x11D);
    fn_99_7E24(fn_99_7DB4(), 0, 0);
    PAIR(0, scripts + 0x9CC, scripts + 0x9B0, 1);

    SETUP_SCRIPT(1, 0xA1C, 0x1E2, 0x2, char*, command)
    SETUP_SCRIPT(2, 0xB48, 0x1E2, 0x40, , command)
    SETUP_SCRIPT(3, 0xC74, 0x1E2, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xDA0, 0x1E2, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xECC, 0x1E2, 0x20, char*, command)
    SETUP_SCRIPT(6, 0xFF8, 0x1E2, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x1124, 0x1E2, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1250, 0x1E2, 0x20, , motionCommand)
    {
        extraCommand = scripts + 0x137C;
        char* command = extraCommand;
        local.flags[9] = 1;
        int value = VALUE();
        fn_99_7C24(command, (short)value, command + 0x50, 9, 1,
            lbl_99_rodata_4, &local.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x14A0, 0x29, 0x10, , finalCommand)

    main0 = BUILD->v90(0, 0);
    fn_99_7E24(fn_99_7EA0(scripts, 0), main0, 0x112);
    main1 = BUILD->v90(0, 1);
    fn_99_7E24(fn_99_7EA0(scripts, 1), main1, 0x112);
    fn_99_7E24(fn_99_7EA0(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 11);
    fn_99_7E24(fn_99_7EA0(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 11);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_99_7EDC(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_99_7EDC(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0xC4E8);
    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_99_data_156C, lbl_99_data_1614, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0xDC58, PTR(self, 0x60));
    {
        part = self + 0xDC94;
        fn_99_60A0(part, 0);
        PTR(part, 0) = lbl_99_data_13E4;
    }
    storage = (char*)PTR(self, 0x60);
    listeners = self + 0xE14C;
    fn_99_60A0(listeners, 0);
    PTR(listeners, 0) = lbl_99_data_1464;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(self, 0xE1E4) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0xE1E8) = 1;
    PTR(self, 0xE1EC) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0xE1F0) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0xDC58))->v0c(PTR(self, 0x60));
    SET_FIGHTER_TABLE(lbl_99_data_FC)

    fn_27_C749C(self + 0xE1F4);
    PTR(self, 0xE204) = g_ftCommonDataAccesser.getData((ftKind)8);
    typedef void* StatusPointer;
    new (local.finalData) StatusPointer[11]();
    local.finalData[2] = lbl_27_bss_734C;
    local.finalData[3] = lbl_99_bss_1CC;
    local.finalData[6] = lbl_99_bss_1DC;
    local.finalData[8] = lbl_99_bss_1EC;
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v78(local.finalData, 11);
    return self;
}
