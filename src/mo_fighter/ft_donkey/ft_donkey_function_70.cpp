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
void fn_92_71F8(void*, int, int, u8, void*);
void* fn_92_7260(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_92_72E8(void*, void*, int);
void fn_92_74BC(void*, void*, void*);
void fn_92_752C(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_92_6DD8(void*, int, void*);
void fn_92_7590(void*, void*, int, int, void*);
void fn_92_7654(void*, void*, int, int, void*);
void fn_92_7718(void*, void*, int, int);
void fn_92_77EC(void*, void*, int, int);
void fn_92_78C0(void*, void*, int, int, void*);
void fn_92_7958(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_92_79C4(void*, void*, int);
void fn_92_7A20(void*, void*, int, void*);
void fn_92_7AB0(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_92_7B04(void*, void*, short);
void fn_92_7B74(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_92_7BE0(void*, short);
void fn_92_7C24(void*, void*, int, int);
void fn_92_80DC(void*, void*);
void fn_92_84AC(void*);
void fn_92_850C(void*, void*);
void fn_92_872C(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_92_87F8(void*, void*, u8, void*);
void fn_92_8890(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_92_88F0(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A6AE0(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_92_8B18();
void fn_92_896C(void*, void*, void*, void*);
void fn_92_8988(void*, short, void*, int, int, float, signed char*);
void fn_92_8B88(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_92_8C04(void*, int);
void fn_92_8C40(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_92_6DC4(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_92_6EA4(void*);

extern float lbl_92_rodata_0, lbl_92_rodata_4;
extern char lbl_92_data_5E8[], lbl_92_data_100[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[], lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_92_data_16C4[], lbl_92_data_176C[];
extern char lbl_92_data_153C[], lbl_92_data_15BC[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_73BC[];
extern char lbl_92_bss_1C4[], lbl_92_bss_1D4[], lbl_92_bss_1E4[], lbl_92_bss_1F4[], lbl_92_bss_204[], lbl_92_bss_214[], lbl_92_bss_224[], lbl_92_bss_234[], lbl_92_bss_244[], lbl_92_bss_254[], lbl_92_bss_264[], lbl_92_bss_274[], lbl_92_bss_284[], lbl_92_bss_294[];
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
    virtual void v8c(void*); virtual void v90(); virtual void v94(); virtual void v98(int, void*);
};

struct Locals {
    signed char flags[11];
    char pad0;
    short kinds[11];
    char pad1[2];
    void* pairs[22];
    char buildData[0x30];
    void* finalData[35];
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
        fn_92_896C(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[i] = 0; \
        int value = VALUE(); \
        fn_92_8988(target + 0xDC, (short)value, target + 0x14, i, 1, \
            lbl_92_rodata_4, &local.flags[i]); \
        PAIR(i, target + 0xDC, target + 0xC0, kind); \
    }

template<char* table>
class CaptainActionLeaf {
public:
    CaptainActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) CaptainActionLeaf<label>(storage);

extern "C" void* fn_92_70(char* self, int entryId, s32 heap1, s32 heap2, s32 heap3) {
    char* part;
    void* accesser;
    Locals local;
    fn_27_1257EC(self, entryId, 1, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_92_data_5E8)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)1, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap2, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0x12578, self + 0x12580);
    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* scripts;
    char* storage = self + 0x194;
    fn_92_6EA4(storage);

    new (storage + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(storage + 0x1168),
        reinterpret_cast<soModelModule*>(storage + 0x1374),
        reinterpret_cast<soMotionModule*>(storage + 0x16F4),
        reinterpret_cast<soPostureModule*>(storage + 0x18A0),
        reinterpret_cast<soGroundModule*>(storage + 0x1968),
        reinterpret_cast<soSituationModule*>(storage + 0x19C0),
        storage + 0x1A2C,
        reinterpret_cast<soCollisionAttackModule*>(storage + 0x208C),
        reinterpret_cast<soCollisionHitModule*>(storage + 0x2A20),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x2C4C),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x36B4),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        storage + 0x3888,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(storage + 0x3A1C),
        storage + 0x3B20,
        storage + 0x3B84,
        reinterpret_cast<soStopModule*>(storage + 0x3BB8),
        storage + 0x3BDC,
        storage + 0x3C90,
        reinterpret_cast<soSoundModule*>(storage + 0x3CC0),
        reinterpret_cast<soLinkModule*>(storage + 0x3E60),
        reinterpret_cast<soVisibilityModule*>(storage + 0x3EB4),
        reinterpret_cast<soControllerModule*>(storage + 0x449C),
        reinterpret_cast<soCameraModule*>(storage + 0x4658),
        reinterpret_cast<soWorkManageModule*>(storage + 0x467C),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x46B0),
        reinterpret_cast<soStatusModule*>(storage + 0x55C8),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x5678),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0xFBD8,
        reinterpret_cast<soEffectModule*>(storage + 0xFC80),
        storage + 0xFDB8,
        reinterpret_cast<soAreaModule*>(storage + 0xFDF8),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        storage + 0x101D8,
        storage + 0x10220,
        reinterpret_cast<soShadowModule*>(storage + 0x102A0),
        reinterpret_cast<soItemManageModule*>(storage + 0x1038C),
        reinterpret_cast<soColorBlendModule*>(storage + 0x103F8),
        storage + 0x1054C,
        storage + 0x10598,
        reinterpret_cast<soSlowModule*>(storage + 0x10600),
        lbl_27_bss_69C,
        storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0x1063C);

    heap2 = ((HeapBuildView*)local.buildData)->getHeapSlotNo();
    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    char* command = (char*)((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, heap2);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_92_71F8(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_92_7260(storage + 0x1180, (soModuleAccesser*)(storage + 0x9D0), modelScale,
        motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_92_72E8(storage + 0x1440, storage + 0x9D0, motionValue);
    fn_92_74BC(storage + 0x1864, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_92_752C(storage + 0x1918, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x19C0, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_92_6DD8(storage + 0x19FC, collisionValue, storage + 0x9D0);
    fn_92_7590(storage + 0x1A70, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_92_7654(storage + 0x212C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_92_7718(storage + 0x2A88, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_92_77EC(storage + 0x2CA0, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_92_78C0(storage + 0x370C, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_92_7958(storage + 0x3970, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x3B20, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x3B84, storage + 0x9D0);
    fn_27_154088(storage + 0x3BB8, storage + 0x9D0);
    fn_27_693F4(storage + 0x3BDC, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_92_79C4(storage + 0x3C14, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_92_7A20(storage + 0x3CAC, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_92_7AB0(storage + 0x3D1C, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x3EB4, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_92_7B04(storage + 0x3EE4, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_92_7B74(storage + 0x4608, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x467C, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_92_7BE0(storage + 0x46B0, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_92_7C24(storage + 0x47A4, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_92_80DC(storage + 0x5678, storage + 0x9D0);
    fn_92_84AC(storage + 0x5980);
    fn_92_850C(storage + 0x5B64, storage + 0x9D0);

    entryId = BUILD->v38();
    heap2 = BUILD->v34();
    motionCommand = (char*)BUILD->v30();
    int animValue1 = BUILD->v2c();
    fn_92_872C(storage + 0xFC14, storage + 0x9D0, animValue1, (int)motionCommand,
        heap2, entryId, lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0xFDB8, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_92_87F8(storage + 0xFDE8, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_92_8890(storage + 0x1015C, storage + 0x9D0, kineticValue);
    new (storage + 0x10220) SlopeStorage(storage + 0x9D0, 0, 1, BUILD->v88());
    new (storage + 0x102A0) ShadowStorage(storage + 0x9D0, 0, &lbl_92_rodata_0);
    int effectValue = BUILD->v64();
    fn_92_88F0(storage + 0x102E8, storage + 0x9D0, effectValue);
    new (storage + 0x103F8) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0x1054C) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0x10598, storage + 0x9D0);
    fn_27_5BED0(storage + 0x10600, storage + 0x9D0);
    fn_27_14CCEC(storage + 0x1063C, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x5B40))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x5B40);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0x107BC, PTR(fighterData, 0x18), 0x23);
    scripts = storage + 0x107CC;
    fn_27_1A6AE0(scripts, 0);
    fn_27_1A6AE0(scripts + 0x4E0, 0);
    fn_27_D22D0(scripts + 0x9C4, 0);
    void* defaultScript = fn_92_8B18();
    fn_92_896C(scripts + 0xA70, scripts, scripts + 0x4E0, defaultScript);
    local.flags[0] = 0;
    int scriptValue = VALUE();
    fn_92_8988(scripts + 0xA8C, (short)scriptValue, scripts + 0x9C4, 0, 1,
        lbl_92_rodata_4, &local.flags[0]);
    fn_92_8B88(scripts, 0, 0x135);
    fn_92_8B88(scripts + 0x4E0, 0, 0x135);
    fn_92_8B88(fn_92_8B18(), 0, 0);
    PAIR(0, scripts + 0xA8C, scripts + 0xA70, 1);

    SETUP_SCRIPT(1, 0xADC, 0x204, 0x2, char*, command)
    SETUP_SCRIPT(2, 0xC08, 0x204, 0x40, , command)
    SETUP_SCRIPT(3, 0xD34, 0x204, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xE60, 0x204, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xF8C, 0x204, 0x20, char*, command)
    SETUP_SCRIPT(6, 0x10B8, 0x204, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x11E4, 0x204, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1310, 0x204, 0x20, , motionCommand)
    {
        extraCommand = scripts + 0x143C;
        char* command = extraCommand;
        local.flags[9] = 1;
        int value = VALUE();
        fn_92_8988(command, (short)value, command + 0x50, 9, 1,
            lbl_92_rodata_4, &local.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x1560, 0x29, 0x10, , finalCommand)

    main0 = BUILD->v90(0, 0);
    fn_92_8B88(fn_92_8C04(scripts, 0), main0, 0x112);
    main1 = BUILD->v90(0, 1);
    fn_92_8B88(fn_92_8C04(scripts, 1), main1, 0x112);
    fn_92_8B88(fn_92_8C04(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 0x23);
    fn_92_8B88(fn_92_8C04(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 0x23);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_92_8C40(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_92_8C40(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0x107BC);
    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_92_data_16C4, lbl_92_data_176C, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0x11FEC, PTR(self, 0x60));
    {
        part = self + 0x12028;
        fn_92_6DC4(part, 0);
        PTR(part, 0) = lbl_92_data_153C;
    }
    storage = (char*)PTR(self, 0x60);
    listeners = self + 0x124E0;
    fn_92_6DC4(listeners, 0);
    PTR(listeners, 0) = lbl_92_data_15BC;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(self, 0x12578) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0x1257C) = 1;
    PTR(self, 0x12580) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0x12584) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0x11FEC))->v0c(PTR(self, 0x60));
    SET_FIGHTER_TABLE(lbl_92_data_100)

    fn_27_C749C(self + 0x12588);
    PTR(self, 0x12598) = g_ftCommonDataAccesser.getData((ftKind)1);
    typedef void* StatusPointer;
    new (local.finalData) StatusPointer[35]();
    local.finalData[1] = lbl_92_bss_1C4;
    local.finalData[2] = lbl_92_bss_1D4;
    local.finalData[4] = lbl_92_bss_1F4;
    local.finalData[5] = lbl_92_bss_244;
    local.finalData[6] = lbl_92_bss_254;
    local.finalData[7] = lbl_92_bss_244; local.finalData[8] = lbl_92_bss_244;
    local.finalData[9] = lbl_92_bss_244; local.finalData[10] = lbl_92_bss_244;
    local.finalData[11] = lbl_92_bss_244; local.finalData[12] = lbl_92_bss_244;
    local.finalData[13] = lbl_92_bss_244; local.finalData[14] = lbl_92_bss_274;
    local.finalData[15] = lbl_92_bss_264; local.finalData[16] = lbl_92_bss_284;
    local.finalData[17] = lbl_92_bss_264; local.finalData[18] = lbl_92_bss_264;
    local.finalData[19] = lbl_92_bss_264; local.finalData[20] = lbl_92_bss_264;
    local.finalData[21] = lbl_92_bss_264; local.finalData[22] = lbl_92_bss_264;
    local.finalData[23] = lbl_92_bss_264; local.finalData[24] = lbl_92_bss_294;
    local.finalData[25] = lbl_92_bss_294; local.finalData[26] = lbl_92_bss_294;
    local.finalData[27] = lbl_92_bss_294; local.finalData[30] = lbl_27_bss_73BC;
    local.finalData[31] = lbl_92_bss_1E4; local.finalData[33] = lbl_92_bss_204;
    local.finalData[34] = lbl_92_bss_214;
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v78(local.finalData, 35);
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v98(0x97, lbl_92_bss_224);
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v98(0x39, lbl_92_bss_234);
    ((ModuleVirtuals*)PTR(PTR(PTR(self, 0x60), 0xD8), 0x70))->v98(0x3A, lbl_92_bss_234);
    return self;
}
