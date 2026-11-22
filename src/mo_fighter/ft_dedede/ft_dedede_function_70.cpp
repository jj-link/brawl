// CodeWarrior reported a 99.7% match with 62 differing lines.
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
void fn_117_6B30(void*, int, int, u8, void*);
void* fn_117_6B98(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_117_6C20(void*, void*, int);
void fn_117_6DF4(void*, void*, void*);
void fn_117_6E64(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_117_6710(void*, int, void*);
void fn_117_6EC8(void*, void*, int, int, void*);
void fn_117_6F8C(void*, void*, int, int, void*);
void fn_117_7050(void*, void*, int, int);
void fn_117_7124(void*, void*, int, int);
void fn_117_71F8(void*, void*, int, int, void*);
void fn_117_732C(void*, void*, void*);
void fn_117_7290(void*, void*, int, int);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_117_7398(void*, void*, int);
void fn_117_73F4(void*, void*, int, void*);
void fn_117_7484(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_117_74D8(void*, void*, short);
void fn_117_7548(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_117_75B4(void*, short);
void fn_117_75F8(void*, void*, int, int);
void fn_117_7AB0(void*, void*);
void fn_117_7E80(void*);
void fn_117_7EE0(void*, void*);
void fn_117_8550(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_117_861C(void*, void*, u8, void*);
void fn_117_86B4(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_117_8714(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A6CE8(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_117_893C();
void fn_117_8790(void*, void*, void*, void*);
void fn_117_87AC(void*, short, void*, int, int, float, signed char*);
void fn_117_89AC(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_117_8A28(void*, int);
void fn_117_8A64(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_117_66FC(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void __ct__18DededeEventStorageFv(void*);

extern float lbl_117_rodata_0, lbl_117_rodata_4;
extern char lbl_117_data_6A0[], lbl_117_data_1B8[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[], lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_117_data_34F8[], lbl_117_data_35A0[];
extern char lbl_117_data_3370[], lbl_117_data_33F0[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_88CC[], lbl_27_bss_891C[], lbl_27_bss_890C[], lbl_27_bss_88EC[], lbl_27_bss_88FC[];
extern char lbl_117_bss_2AC[], lbl_117_bss_23C[], lbl_117_bss_28C[], lbl_117_bss_2DC[], lbl_117_bss_2CC[], lbl_117_bss_24C[], lbl_117_bss_25C[], lbl_117_bss_26C[], lbl_117_bss_27C[];
extern char lbl_117_bss_194[], lbl_117_bss_1A4[], lbl_117_bss_1B4[];
extern char lbl_117_bss_1C4[], lbl_117_bss_1D4[], lbl_117_bss_1E4[], lbl_117_bss_1F4[];
extern char lbl_117_bss_204[], lbl_117_bss_214[], lbl_117_bss_224[], lbl_117_bss_234[], lbl_117_bss_244[];
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

struct CommonView { char pad[0x47778]; void* data; };

struct Locals {
    signed char flags[11];
    char pad0;
    short kinds[11];
    char pad1[2];
    void* pairs[22];
    char buildData[0x30];
    void* finalData[40];
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
        fn_117_8790(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[i] = 0; \
        int value = VALUE(); \
        fn_117_87AC(target + 0xDC, (short)value, target + 0x14, i, 1, \
            lbl_117_rodata_4, &local.flags[i]); \
        PAIR(i, target + 0xDC, target + 0xC0, kind); \
    }

template<char* table>
class DededeActionLeaf {
public:
    DededeActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) DededeActionLeaf<label>(storage);

extern "C" void* fn_117_70(char* self, int entryId, s32 heap1, s32 heap2, s32 heap3) {
    char* part;
    void* accesser;
    Locals local;
    fn_27_1257EC(self, entryId, 0x20, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_117_data_6A0)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)0x20, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap2, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0x47758, self + 0x47760);
    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* scripts;
    char* storage = self + 0x194;
    __ct__18DededeEventStorageFv(storage);

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
        reinterpret_cast<soCollisionSearchModule*>(storage + 0x39CC),
        reinterpret_cast<soDamageModule*>(storage + 0x3B80),
        storage + 0x3C84,
        storage + 0x3CE8,
        reinterpret_cast<soStopModule*>(storage + 0x3D1C),
        storage + 0x3D40,
        storage + 0x3DF4,
        reinterpret_cast<soSoundModule*>(storage + 0x3E24),
        reinterpret_cast<soLinkModule*>(storage + 0x3FF8),
        reinterpret_cast<soVisibilityModule*>(storage + 0x404C),
        reinterpret_cast<soControllerModule*>(storage + 0x4634),
        reinterpret_cast<soCameraModule*>(storage + 0x47F0),
        reinterpret_cast<soWorkManageModule*>(storage + 0x4814),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x4848),
        reinterpret_cast<soStatusModule*>(storage + 0x5798),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x5848),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0x44CF8,
        reinterpret_cast<soEffectModule*>(storage + 0x44DA0),
        storage + 0x44ED8,
        reinterpret_cast<soAreaModule*>(storage + 0x44F18),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        storage + 0x45340,
        storage + 0x45388,
        reinterpret_cast<soShadowModule*>(storage + 0x45408),
        reinterpret_cast<soItemManageModule*>(storage + 0x45544),
        reinterpret_cast<soColorBlendModule*>(storage + 0x455B0),
        storage + 0x45704,
        storage + 0x45750,
        reinterpret_cast<soSlowModule*>(storage + 0x457B8),
        lbl_27_bss_69C,
        storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0x457F4);

    heap2 = ((HeapBuildView*)local.buildData)->getHeapSlotNo();
    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    char* command = (char*)((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, heap2);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_117_6B30(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_117_6B98(storage + 0x1180, (soModuleAccesser*)(storage + 0x9D0), modelScale,
        motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_117_6C20(storage + 0x1440, storage + 0x9D0, motionValue);
    fn_117_6DF4(storage + 0x17D4, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_117_6E64(storage + 0x1888, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x1930, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_117_6710(storage + 0x196C, collisionValue, storage + 0x9D0);
    fn_117_6EC8(storage + 0x19E0, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_117_6F8C(storage + 0x209C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_117_7050(storage + 0x29F8, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_117_7124(storage + 0x2C10, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_117_71F8(storage + 0x367C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_117_7290(storage + 0x38DC, storage + 0x9D0, INT(self, 0x28), (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_117_732C(storage + 0x3AD4, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x3C84, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x3CE8, storage + 0x9D0);
    fn_27_154088(storage + 0x3D1C, storage + 0x9D0);
    fn_27_693F4(storage + 0x3D40, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_117_7398(storage + 0x3D78, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_117_73F4(storage + 0x3E10, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_117_7484(storage + 0x3E80, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x404C, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_117_74D8(storage + 0x407C, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_117_7548(storage + 0x47A0, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x4814, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_117_75B4(storage + 0x4848, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_117_75F8(storage + 0x493C, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_117_7AB0(storage + 0x5848, storage + 0x9D0);
    fn_117_7E80(storage + 0x5B50);
    fn_117_7EE0(storage + 0x5D34, storage + 0x9D0);

    entryId = BUILD->v38();
    heap2 = BUILD->v34();
    motionCommand = (char*)BUILD->v30();
    int animValue1 = BUILD->v2c();
    fn_117_8550(storage + 0x44D34, storage + 0x9D0, animValue1, (int)motionCommand,
        heap2, entryId, lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0x44ED8, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_117_861C(storage + 0x44F08, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_117_86B4(storage + 0x452C4, storage + 0x9D0, kineticValue);
    new (storage + 0x45388) SlopeStorage(storage + 0x9D0, 0, 1, BUILD->v88());
    new (storage + 0x45408) ShadowStorage(storage + 0x9D0, 0, &lbl_117_rodata_0);
    int effectValue = BUILD->v64();
    fn_117_8714(storage + 0x45450, storage + 0x9D0, effectValue);
    new (storage + 0x455B0) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0x45704) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0x45750, storage + 0x9D0);
    fn_27_5BED0(storage + 0x457B8, storage + 0x9D0);
    fn_27_14CCEC(storage + 0x457F4, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x5D10))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x5D10);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0x45974, PTR(fighterData, 0x18), 0x28);
    scripts = storage + 0x45984;
    fn_27_1A6CE8(scripts, 0);
    fn_27_1A6CE8(scripts + 0x4F4, 0);
    fn_27_D22D0(scripts + 0x9EC, 0);
    void* defaultScript = fn_117_893C();
    fn_117_8790(scripts + 0xA98, scripts, scripts + 0x4F4, defaultScript);
    local.flags[0] = 0;
    int scriptValue = VALUE();
    fn_117_87AC(scripts + 0xAB4, (short)scriptValue, scripts + 0x9EC, 0, 1,
        lbl_117_rodata_4, &local.flags[0]);
    fn_117_89AC(scripts, 0, 0x13A);
    fn_117_89AC(scripts + 0x4F4, 0, 0x13A);
    fn_117_89AC(fn_117_893C(), 0, 0);
    PAIR(0, scripts + 0xAB4, scripts + 0xA98, 1);

    SETUP_SCRIPT(1, 0xB04, 0x217, 0x2, char*, command)
    SETUP_SCRIPT(2, 0xC30, 0x217, 0x40, , command)
    SETUP_SCRIPT(3, 0xD5C, 0x217, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xE88, 0x217, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xFB4, 0x217, 0x20, char*, command)
    SETUP_SCRIPT(6, 0x10E0, 0x217, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x120C, 0x217, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1338, 0x217, 0x20, , motionCommand)
    {
        extraCommand = scripts + 0x1464;
        char* command = extraCommand;
        local.flags[9] = 1;
        int value = VALUE();
        fn_117_87AC(command, (short)value, command + 0x50, 9, 1,
            lbl_117_rodata_4, &local.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x1588, 0x29, 0x10, , finalCommand)

    main0 = BUILD->v90(0, 0);
    fn_117_89AC(fn_117_8A28(scripts, 0), main0, 0x112);
    main1 = BUILD->v90(0, 1);
    fn_117_89AC(fn_117_8A28(scripts, 1), main1, 0x112);
    fn_117_89AC(fn_117_8A28(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 0x28);
    fn_117_89AC(fn_117_8A28(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 0x28);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_117_8A64(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_117_8A64(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0x45974);
    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_117_data_34F8, lbl_117_data_35A0, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0x471CC, PTR(self, 0x60));
    {
        part = self + 0x47208;
        fn_117_66FC(part, 0);
        PTR(part, 0) = lbl_117_data_3370;
    }
    storage = (char*)PTR(self, 0x60);
    listeners = self + 0x476C0;
    fn_117_66FC(listeners, 0);
    PTR(listeners, 0) = lbl_117_data_33F0;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(self, 0x47758) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0x4775C) = 1;
    PTR(self, 0x47760) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0x47764) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0x471CC))->v0c(PTR(self, 0x60));
    SET_FIGHTER_TABLE(lbl_117_data_1B8)

    fn_27_C749C(self + 0x47768);
    void* commonData = g_ftCommonDataAccesser.getData((ftKind)0x20);
    PTR(self, 0x47778) = commonData;
    typedef void* StatusPointer;
    new (local.finalData) StatusPointer[40]();
    local.finalData[0] = lbl_27_bss_88CC;
    local.finalData[1] = lbl_117_bss_2AC;
    local.finalData[2] = lbl_117_bss_23C;
    local.finalData[3] = lbl_117_bss_28C;
    local.finalData[4] = lbl_117_bss_2DC;
    local.finalData[5] = lbl_27_bss_88CC;
    local.finalData[7] = lbl_27_bss_891C;
    local.finalData[8] = lbl_27_bss_891C;
    local.finalData[9] = lbl_27_bss_890C;
    local.finalData[10] = lbl_27_bss_890C;
    local.finalData[11] = lbl_27_bss_890C;
    local.finalData[12] = lbl_27_bss_890C;
    local.finalData[13] = lbl_27_bss_890C;
    local.finalData[14] = lbl_27_bss_890C;
    local.finalData[15] = lbl_27_bss_890C;
    local.finalData[16] = lbl_27_bss_890C;
    local.finalData[17] = lbl_27_bss_890C;
    local.finalData[18] = lbl_27_bss_890C;
    local.finalData[19] = lbl_27_bss_890C;
    local.finalData[20] = lbl_27_bss_890C;
    local.finalData[21] = lbl_27_bss_88EC;
    local.finalData[22] = lbl_27_bss_88FC;
    local.finalData[23] = lbl_117_bss_2CC;
    local.finalData[24] = lbl_117_bss_24C;
    local.finalData[25] = lbl_117_bss_25C;
    local.finalData[26] = lbl_117_bss_26C;
    local.finalData[28] = lbl_117_bss_27C;
    local.finalData[29] = lbl_117_bss_28C;
    local.finalData[30] = lbl_117_bss_28C;
    local.finalData[31] = lbl_117_bss_28C;
    local.finalData[32] = lbl_117_bss_28C;
    local.finalData[33] = lbl_117_bss_28C;
    local.finalData[34] = lbl_117_bss_28C;
    local.finalData[35] = lbl_117_bss_28C;
    local.finalData[36] = lbl_117_bss_28C;
    local.finalData[37] = lbl_117_bss_28C;
    local.finalData[38] = lbl_117_bss_2DC;
    local.finalData[39] = lbl_117_bss_2DC;
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v78(local.finalData, 40);
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x90))->v2c(PTR(((CommonView*)self)->data, 0xB8));
    return self;
}