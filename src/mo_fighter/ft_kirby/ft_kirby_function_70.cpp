#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <ft/ft_common_data_accesser.h>
#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>

#pragma force_active on

inline void* operator new[](size_t, void* storage) { return storage; }

extern "C" {
void fn_27_1257EC(void*, int, int, int, void*);
void fn_27_14B5F8(void*, void*);
void fn_96_2DCC(void*, int, int, u8, void*);
void* fn_96_2F40(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_96_309C(void*, void*, int);
void fn_96_36D4(void*, void*, void*);
void fn_96_3744(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_96_25F8(void*, int, void*);
void fn_96_3820(void*, void*, int, int, void*);
void fn_96_3968(void*, void*, int, int, void*);
void fn_96_3AB0(void*, void*, int, int);
void fn_96_3C14(void*, void*, int, int);
void fn_96_3D78(void*, void*, int, int, void*);
void fn_96_3F90(void*, void*, void*);
void fn_96_3E7C(void*, void*, int, int);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_96_41E0(void*, void*, int);
void fn_96_42B0(void*, void*, int, void*);
void fn_96_43EC(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_96_4508(void*, void*, short);
void fn_96_4654(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_96_4734(void*, short);
void fn_96_4900(void*, void*, int, int);
void fn_96_5AA8(void*, void*);
void fn_96_606C(void*);
void fn_96_612C(void*, void*);
void fn_96_9834(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_96_99F4(void*, void*, u8, void*);
void fn_96_9B24(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8);
void fn_27_B62E4(void*, void*, float, int);
void fn_96_9C14(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A6DEC(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void* fn_96_A390();
void fn_96_A1E4(void*, void*, void*, void*);
void fn_96_A200(void*, short, void*, int, int, float, signed char*);
void fn_96_A400(void*, void*, int);
void fn_27_1A079C(void*, int);
void* fn_96_AB24(void*, int);
void fn_96_AB60(void*, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_96_1FD0(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void* fn_96_28D8(void*);
void fn_96_1C244(void*, soModuleAccesser*);
void fn_96_1C4E8(void*, int);
int fn_27_10B2A4(void*, int);
int fn_27_10B2E4(void*, int, int);
void fn_27_195B34(void*, void*, void*);

extern const f32 lbl_96_rodata_0[];
extern char lbl_96_data_610[], lbl_96_data_120[], lbl_96_data_5C50[], lbl_96_data_5CF8[];
extern char lbl_96_data_5AC8[], lbl_96_data_5B48[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[], lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_3AC[], lbl_27_bss_4BC[], lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_96_bss_C9C[], lbl_96_bss_C4C[], lbl_96_bss_C0C[];
extern char lbl_96_bss_C5C[], lbl_96_bss_D1C[], lbl_96_bss_CEC[];
extern char lbl_96_bss_CDC[], lbl_96_bss_CBC[], lbl_96_bss_CFC[];
extern char lbl_96_bss_CCC[], lbl_96_bss_C1C[], lbl_96_bss_C2C[];
extern char lbl_96_bss_C3C[], lbl_96_bss_C6C[], lbl_96_bss_C7C[];
extern char lbl_27_bss_7CDC[], lbl_27_bss_7CEC[], lbl_27_bss_7C64[];
extern char lbl_27_bss_80A4[], lbl_27_bss_82D4[], lbl_27_bss_83CC[];
extern char lbl_27_bss_8034[], lbl_27_bss_8044[], lbl_27_bss_8054[];
extern char lbl_27_bss_8074[], lbl_27_bss_8064[], lbl_27_bss_7704[];
extern char lbl_27_bss_8BEC[], lbl_27_bss_7DD4[], lbl_27_bss_7E14[];
extern char lbl_27_bss_7E24[], lbl_27_bss_8204[], lbl_27_bss_7CFC[];
extern char lbl_27_bss_73BC[], lbl_27_bss_8A14[], lbl_27_bss_8A24[];
extern char lbl_27_bss_8A34[], lbl_27_bss_8A44[], lbl_27_bss_7F34[];
extern char lbl_27_bss_7F44[], lbl_27_bss_7F54[], lbl_27_bss_8BFC[];
extern char lbl_27_bss_8C0C[], lbl_27_bss_8C1C[], lbl_27_bss_8C2C[];
extern char lbl_27_bss_8C3C[], lbl_27_bss_8C4C[], lbl_27_bss_8C5C[];
extern char lbl_27_bss_8C6C[], lbl_27_bss_826C[], lbl_27_bss_8A54[];
extern char lbl_27_bss_88CC[], lbl_27_bss_891C[], lbl_27_bss_890C[];
extern char lbl_27_bss_88EC[], lbl_27_bss_88FC[], lbl_27_bss_8004[];
extern char lbl_27_bss_8014[], lbl_27_bss_73CC[], lbl_27_bss_8A9C[];
extern char lbl_27_bss_897C[], lbl_27_bss_75C4[], lbl_27_bss_75E4[];
extern char lbl_27_bss_75F4[], lbl_27_bss_75D4[], lbl_27_bss_7604[];
extern char lbl_27_bss_7D74[];
}

class SlopeStorage {
public:
    SlopeStorage(void* accesser, u8 initial, int count) {
        fn_27_ACAC4(this, accesser, initial, count, initial);
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

struct KirbyCommonDataView {
    char prefix[0x1B678];
    char* data;
};

struct ReflectorInit {
    void* data;
    int count;
    f32 x, y, z, scale;
    u32 active : 1;
};

struct Locals {
    s8 flags[11];
    s16 kinds[11];
    void* pairs[22];
    ReflectorInit reflector;
    u8 reflectorOutput[0x20];
    char buildData[0x30];
    void* status[0xAE];
};

class InitialArea {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual void reserved10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual void reserved20();
    virtual void reserved24();
    virtual void reserved28();
    virtual void addArea(void*);
    virtual void reserved30();
    virtual void reserved34();
    virtual void setStatus(int, int, int);
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
        fn_96_A1E4(target + 0xC0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        local.flags[i] = 0; \
        int value = VALUE(); \
        fn_96_A200(target + 0xDC, (short)value, target + 0x14, i, 1, \
            rodata[1], &local.flags[i]); \
        PAIR(i, target + 0xDC, target + 0xC0, kind); \
    }

template<char* table>
class KirbyActionLeaf {
public:
    KirbyActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) KirbyActionLeaf<label>(storage);

extern "C" void* fn_96_70(char* self, int entryId, s32 heap1, s32 heap3) {
    const f32* const rodata = lbl_96_rodata_0;
    char* part;
    Locals local;
    fn_27_1257EC(self, entryId, 5, heap1, self + 0xB64);
    SET_FIGHTER_TABLE(lbl_96_data_610)

    new (local.buildData) ftFighterBuildData(entryId, (ftKind)5, (Heaps::HeapType)heap1,
        (Heaps::HeapType)heap1, (Heaps::HeapType)heap3, 0,
        (soModuleAccesser*)PTR(self, 0x60), -1, self + 0x1B668, self + 0x1B670);
    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* scripts;
    char* storage = self + 0x194;
    fn_96_28D8(storage);

    new (storage + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(storage + 0x1168),
        reinterpret_cast<soModelModule*>(storage + 0x1374),
        reinterpret_cast<soMotionModule*>(storage + 0x1668),
        reinterpret_cast<soPostureModule*>(storage + 0x181C),
        reinterpret_cast<soGroundModule*>(storage + 0x18E4),
        reinterpret_cast<soSituationModule*>(storage + 0x193C),
        storage + 0x19A8,
        reinterpret_cast<soCollisionAttackModule*>(storage + 0x2008),
        reinterpret_cast<soCollisionHitModule*>(storage + 0x299C),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x2D58),
        reinterpret_cast<soCollisionShieldModule*>(storage + 0x34D0),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        storage + 0x36A4,
        reinterpret_cast<soCollisionSearchModule*>(storage + 0x38D8),
        reinterpret_cast<soDamageModule*>(storage + 0x3A8C),
        storage + 0x3B90,
        storage + 0x3BF4,
        reinterpret_cast<soStopModule*>(storage + 0x3C28),
        storage + 0x3C4C,
        storage + 0x3D00,
        reinterpret_cast<soSoundModule*>(storage + 0x3D30),
        reinterpret_cast<soLinkModule*>(storage + 0x3F38),
        reinterpret_cast<soVisibilityModule*>(storage + 0x3F8C),
        reinterpret_cast<soControllerModule*>(storage + 0x4574),
        reinterpret_cast<soCameraModule*>(storage + 0x4730),
        reinterpret_cast<soWorkManageModule*>(storage + 0x4754),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage + 0x4788),
        reinterpret_cast<soStatusModule*>(storage + 0x595C),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(storage + 0x5A0C),
        reinterpret_cast<soEventManageModule*>(storage + 0xB8),
        storage + 0x1882C,
        reinterpret_cast<soEffectModule*>(storage + 0x188D4),
        storage + 0x18A0C,
        reinterpret_cast<soAreaModule*>(storage + 0x18A4C),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        storage + 0x18E20,
        storage + 0x18E68,
        reinterpret_cast<soShadowModule*>(storage + 0x18EE8),
        reinterpret_cast<soItemManageModule*>(storage + 0x19024),
        reinterpret_cast<soColorBlendModule*>(storage + 0x19090),
        storage + 0x191E4,
        storage + 0x19230,
        reinterpret_cast<soSlowModule*>(storage + 0x19298),
        lbl_27_bss_69C,
        storage + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(storage + 0xAC8),
        storage + 0x192D4);

    entryId = ((HeapBuildView*)local.buildData)->getHeapSlotNo();
    char* motionCommand = (char*)((HeapBuildView*)local.buildData)->getNWMotionInstanceHeap();
    char* command = (char*)((HeapBuildView*)local.buildData)->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = ((HeapBuildView*)local.buildData)->getInstanceHeap();
    new (storage + 0xAB0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, entryId);
    fn_27_14B5F8(storage + 0xAC8, storage + 0x9D0);
    fn_96_2DCC(storage + 0x115C, ((soModuleAccesserBuildData*)local.buildData)->getMdlResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getAnmResId(),
        ((soModuleAccesserBuildData*)local.buildData)->getResGroupNo(), storage + 0x9D0);

    motionCommand = (char*)BUILD->v68();
    float modelScale = BUILD->v50();
    fn_96_2F40(storage + 0x1180, (soModuleAccesser*)(storage + 0x9D0), modelScale,
        motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    int motionValue = BUILD->v18();
    fn_96_309C(storage + 0x1444, storage + 0x9D0, motionValue);
    fn_96_36D4(storage + 0x17E0, storage + 0x9D0, lbl_27_bss_A48);
    int groundValue = BUILD->v28();
    fn_96_3744(storage + 0x1894, storage + 0x9D0, groundValue);
    int situationValue = VALUE();
    fn_27_3513C(storage + 0x193C, (short)situationValue, storage + 0x9D0, lbl_27_bss_A48);
    int collisionValue = BUILD->v14();
    fn_96_25F8(storage + 0x1978, collisionValue, storage + 0x9D0);
    fn_96_3820(storage + 0x19EC, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_96_3968(storage + 0x20A8, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_96_3AB0(storage + 0x2A04, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_96_3C14(storage + 0x2DAC, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_96_3D78(storage + 0x3528, storage + 0x9D0, INT(self, 0x28),
        (*(u32*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_96_3E7C(storage + 0x3788, storage + 0x9D0, INT(self, 0x28), (*(u32*)(self + 0x2C) >> 7) & 0xFF);
    fn_96_3F90(storage + 0x39E0, storage + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(storage + 0x3B90, storage + 0x9D0, 1);
    fn_27_65EE4(storage + 0x3BF4, storage + 0x9D0);
    fn_27_154088(storage + 0x3C28, storage + 0x9D0);
    fn_27_693F4(storage + 0x3C4C, storage + 0x9D0);
    int damageValue = BUILD->v1c();
    fn_96_41E0(storage + 0x3C84, storage + 0x9D0, damageValue);
    int stopValue = BUILD->v84();
    fn_96_42B0(storage + 0x3D1C, storage + 0x9D0, stopValue, lbl_27_bss_A48);
    fn_96_43EC(storage + 0x3D8C, storage + 0x9D0);
    int soundValue = BUILD->v20();
    fn_27_5B248(storage + 0x3F8C, storage + 0x9D0, soundValue, 2);
    int linkValue = VALUE();
    fn_96_4508(storage + 0x3FBC, storage + 0x9D0, (short)linkValue);
    motionCommand = (char*)BUILD->v60();
    int visibilityValue1 = BUILD->v5c();
    fn_96_4654(storage + 0x46E0, storage + 0x9D0, visibilityValue1,
        (int)motionCommand, lbl_27_bss_A48);
    int controllerValue = BUILD->v54();
    fn_27_A1DA4(storage + 0x4754, storage + 0x9D0, controllerValue);
    int cameraValue = VALUE();
    fn_96_4734(storage + 0x4788, (short)cameraValue);
    motionCommand = (char*)BUILD->v70();
    int workValue1 = BUILD->v24();
    fn_96_4900(storage + 0x487C, storage + 0x9D0, workValue1, (int)motionCommand);
    fn_96_5AA8(storage + 0x5A0C, storage + 0x9D0);
    fn_96_606C(storage + 0x5D14);
    fn_96_612C(storage + 0x5EF8, storage + 0x9D0);

    fn_96_9834(storage + 0x18868, storage + 0x9D0, BUILD->v2c(),
        (int)(motionCommand = (char*)BUILD->v30()),
        (entryId = BUILD->v34()), BUILD->v38(), lbl_27_bss_A48);
    fn_27_14FBD8(storage + 0x18A0C, storage + 0x9D0);
    int statusValue = BUILD->v58();
    fn_96_99F4(storage + 0x18A3C, storage + 0x9D0, (u8)statusValue, lbl_27_bss_A48);
    BUILD->v40();
    BUILD->v3c();
    BUILD->v44();
    int kineticValue = BUILD->v48();
    fn_96_9B24(storage + 0x18E1C, storage + 0x9D0, kineticValue);
    BUILD->v88();
    new (storage + 0x18E68) SlopeStorage(storage + 0x9D0, 0, 1);
    new (storage + 0x18EE8) ShadowStorage(storage + 0x9D0, 0, rodata);
    int effectValue = BUILD->v64();
    fn_96_9C14(storage + 0x18F30, storage + 0x9D0, effectValue);
    new (storage + 0x19090) ColorBlendStorage(storage + 0x9D0, 10, 1);
    new (storage + 0x191E4) JostleStorage(storage + 0x9D0, 0, 8, BUILD->v6c());
    fn_27_196664(storage + 0x19230, storage + 0x9D0);
    fn_27_5BED0(storage + 0x19298, storage + 0x9D0);
    fn_27_14CCEC(storage + 0x192D4, storage + 0x9D0);

    if (((CheckVirtual*)(storage + 0x5ED4))->v08() == 0)
        ((RegisterVirtual*)PTR(PTR(storage, 0xAA8), 0x64))->v14(1, storage + 0x5ED4);

    char* fighterData = (char*)PTR(local.buildData, 0x0C);
    fn_27_C74BC(storage + 0x19454, PTR(fighterData, 0x18), 0xAE);
    scripts = storage + 0x19464;
    fn_27_1A6DEC(scripts, 0);
    fn_27_1A6DEC(scripts + 0x70C, 0);
    fn_27_D22D0(scripts + 0xE1C, 0);
    void* defaultScript = fn_96_A390();
    fn_96_A1E4(scripts + 0xEC8, scripts, scripts + 0x70C, defaultScript);
    local.flags[0] = 0;
    int scriptValue = VALUE();
    fn_96_A200(scripts + 0xEE4, (short)scriptValue, scripts + 0xE1C, 0, 1,
        rodata[1], &local.flags[0]);
    fn_96_A400(scripts, 0, 0x1C0);
    fn_96_A400(scripts + 0x70C, 0, 0x1C0);
    fn_96_A400(fn_96_A390(), 0, 0);
    PAIR(0, scripts + 0xEE4, scripts + 0xEC8, 1);

    SETUP_SCRIPT(1, 0xF34, 0x31D, 0x2, char*, command)
    SETUP_SCRIPT(2, 0x1060, 0x31D, 0x40, , command)
    SETUP_SCRIPT(3, 0x118C, 0x31D, 0x40, char*, command)
    SETUP_SCRIPT(4, 0x12B8, 0x31D, 0x2, char*, command)
    SETUP_SCRIPT(5, 0x13E4, 0x31D, 0x20, char*, command)
    SETUP_SCRIPT(6, 0x1510, 0x31D, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x163C, 0x31D, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x1768, 0x31D, 0x20, , motionCommand)
    {
        extraCommand = scripts + 0x1894;
        char* command = extraCommand;
        local.flags[9] = 1;
        int value = VALUE();
        fn_96_A200(command, (short)value, command + 0x50, 9, 1,
            rodata[1], &local.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x19B8, 0x29, 0x10, , finalCommand)

    main0 = BUILD->v90(0, 0);
    fn_96_A400(fn_96_AB24(scripts, 0), main0, 0x112);
    main1 = BUILD->v90(0, 1);
    fn_96_A400(fn_96_AB24(scripts, 1), main1, 0x112);
    fn_96_A400(fn_96_AB24(scripts, 0), PTR(PTR(local.buildData, 0x0C), 0x24), 0xAE);
    fn_96_A400(fn_96_AB24(scripts, 1), PTR(PTR(local.buildData, 0x0C), 0x28), 0xAE);
    void* disguise0 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 0);
    fn_96_AB60(scripts, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)local.buildData)->getAnimCmdDisguiseList(false, 1);
    fn_96_AB60(scripts, 1, disguise1);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x70))->v8c(storage + 0x19454);
    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(storage + 0x9D0), 0xA805, 0);
    void* cast = __dynamic_cast(PTR(PTR(storage, 0xAA8), 0x90), 0,
        lbl_96_data_5C50, lbl_96_data_5CF8, 0);
    if (cast)
        fn_27_14E0B8(cast, constant);
    ((ModuleVirtuals*)PTR(PTR(storage, 0xAA8), 0x90))->v2c(constant);

    fn_27_1404D4(self + 0x1B0DC, PTR(self, 0x60));
    {
        part = self + 0x1B118;
        fn_96_1FD0(part, 0);
        PTR(part, 0) = lbl_96_data_5AC8;
    }
    storage = (char*)PTR(self, 0x60);
    listeners = self + 0x1B5D0;
    fn_96_1FD0(listeners, 0);
    PTR(listeners, 0) = lbl_96_data_5B48;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(self, 0x1B668) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7F9, 0);
    INT(self, 0x1B66C) = 1;
    PTR(self, 0x1B670) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(self, 0x60), 0xA7FC, 0);
    INT(self, 0x1B674) = 1;
    fn_27_126470(self);
    ((ModuleVirtuals*)(self + 0x1B0DC))->v0c(PTR(self, 0x60));
    SET_FIGHTER_TABLE(lbl_96_data_120)

    void* common = g_ftCommonDataAccesser.getData((ftKind)5);
    PTR(self, 0x1B678) = common;
    fn_27_C749C(self + 0x1B67C);
    *(u8*)(self + 0x1B68C) = 0;
    *(u8*)(self + 0x1B68D) = 0;
    typedef char Entry[0x10];
    Entry* second;
    char* upper = self + 0x20000;
    Entry* first = (Entry*)(upper - 0x4960);
    do {
        upper = self + 0x20000;
        second = (Entry*)(upper - 0x4920);
        ++first;
    } while (first < second);
    do {
        ++second;
    } while (second < (Entry*)(self + 0x1B720));
    fn_96_1C244(self + 0x1B72C, (soModuleAccesser*)PTR(self, 0x60));
    *(s32*)(self + 0x1C290) = heap3;

    typedef void* StatusPointer;
    new (local.status) StatusPointer[0xAE]();
    local.status[0] = lbl_96_bss_C9C;
    local.status[1] = lbl_96_bss_C4C;
    local.status[2] = lbl_96_bss_C0C;
    local.status[3] = lbl_96_bss_C5C;
    local.status[4] = lbl_96_bss_D1C;
    local.status[5] = lbl_96_bss_C9C;
    local.status[7] = lbl_96_bss_CEC;
    local.status[8] = lbl_96_bss_CEC;
    local.status[9] = lbl_96_bss_CDC;
    local.status[10] = lbl_96_bss_CDC;
    local.status[11] = lbl_96_bss_CDC;
    local.status[12] = lbl_96_bss_CDC;
    local.status[13] = lbl_96_bss_CDC;
    local.status[14] = lbl_96_bss_CDC;
    local.status[15] = lbl_96_bss_CDC;
    local.status[16] = lbl_96_bss_CDC;
    local.status[17] = lbl_96_bss_CDC;
    local.status[18] = lbl_96_bss_CDC;
    local.status[19] = lbl_96_bss_CDC;
    local.status[20] = lbl_96_bss_CBC;
    local.status[21] = lbl_96_bss_CFC;
    local.status[22] = lbl_96_bss_CCC;
    local.status[23] = lbl_96_bss_C1C;
    local.status[24] = lbl_96_bss_C2C;
    local.status[25] = lbl_96_bss_C3C;
    local.status[26] = lbl_96_bss_C6C;
    local.status[27] = lbl_96_bss_C7C;
    local.status[28] = lbl_96_bss_D1C;
    local.status[29] = lbl_96_bss_D1C;
    local.status[30] = lbl_96_bss_D1C;
    local.status[31] = lbl_96_bss_D1C;
    local.status[32] = lbl_96_bss_D1C;
    local.status[33] = lbl_27_bss_7CDC;
    local.status[34] = lbl_27_bss_7CEC;
    local.status[35] = lbl_27_bss_7C64;
    local.status[37] = lbl_27_bss_80A4;
    local.status[50] = lbl_27_bss_82D4;
    local.status[54] = lbl_27_bss_83CC;
    local.status[55] = lbl_27_bss_83CC;
    local.status[56] = lbl_27_bss_83CC;
    local.status[57] = lbl_27_bss_8034;
    local.status[58] = lbl_27_bss_8034;
    local.status[60] = lbl_27_bss_8044;
    local.status[61] = lbl_27_bss_8044;
    local.status[62] = lbl_27_bss_8054;
    local.status[63] = lbl_27_bss_8074;
    local.status[64] = lbl_27_bss_8064;
    local.status[65] = lbl_27_bss_8064;
    local.status[66] = lbl_27_bss_8064;
    local.status[67] = lbl_27_bss_8064;
    local.status[72] = lbl_27_bss_7704;
    local.status[73] = lbl_27_bss_7704;
    local.status[75] = lbl_27_bss_8BEC;
    local.status[76] = lbl_27_bss_8BEC;
    local.status[77] = lbl_27_bss_8BEC;
    local.status[78] = lbl_27_bss_8BEC;
    local.status[79] = lbl_27_bss_8BEC;
    local.status[80] = lbl_27_bss_8BEC;
    local.status[81] = lbl_27_bss_8BEC;
    local.status[82] = lbl_27_bss_8BEC;
    local.status[83] = lbl_27_bss_8BEC;
    local.status[84] = lbl_27_bss_8BEC;
    local.status[85] = lbl_27_bss_8BEC;
    local.status[88] = lbl_27_bss_7DD4;
    local.status[89] = lbl_27_bss_7E14;
    local.status[90] = lbl_27_bss_7E14;
    local.status[91] = lbl_27_bss_7E24;
    local.status[92] = lbl_27_bss_7E14;
    local.status[93] = lbl_27_bss_8204;
    local.status[94] = lbl_27_bss_8204;
    local.status[95] = lbl_27_bss_8204;
    local.status[96] = lbl_27_bss_8204;
    local.status[97] = lbl_27_bss_7CFC;
    local.status[98] = lbl_27_bss_7CFC;
    local.status[99] = lbl_27_bss_7CFC;
    local.status[100] = lbl_27_bss_7CFC;
    local.status[104] = lbl_27_bss_73BC;
    local.status[106] = lbl_27_bss_8A14;
    local.status[107] = lbl_27_bss_8A24;
    local.status[108] = lbl_27_bss_8A34;
    local.status[109] = lbl_27_bss_8A44;
    local.status[110] = lbl_27_bss_7F34;
    local.status[111] = lbl_27_bss_7F44;
    local.status[112] = lbl_27_bss_7F54;
    local.status[114] = lbl_27_bss_8BFC;
    local.status[115] = lbl_27_bss_8C0C;
    local.status[116] = lbl_27_bss_8C1C;
    local.status[117] = lbl_27_bss_8C2C;
    local.status[118] = lbl_27_bss_8C3C;
    local.status[119] = lbl_27_bss_8C4C;
    local.status[120] = lbl_27_bss_8C5C;
    local.status[121] = lbl_27_bss_8C6C;
    local.status[122] = lbl_27_bss_826C;
    local.status[123] = lbl_27_bss_826C;
    local.status[124] = lbl_27_bss_826C;
    local.status[125] = lbl_27_bss_826C;
    local.status[126] = lbl_27_bss_826C;
    local.status[127] = lbl_27_bss_8A54;
    local.status[128] = lbl_27_bss_88CC;
    local.status[129] = lbl_27_bss_88CC;
    local.status[131] = lbl_27_bss_891C;
    local.status[132] = lbl_27_bss_891C;
    local.status[133] = lbl_27_bss_890C;
    local.status[134] = lbl_27_bss_890C;
    local.status[135] = lbl_27_bss_890C;
    local.status[136] = lbl_27_bss_890C;
    local.status[137] = lbl_27_bss_890C;
    local.status[138] = lbl_27_bss_890C;
    local.status[139] = lbl_27_bss_890C;
    local.status[140] = lbl_27_bss_890C;
    local.status[141] = lbl_27_bss_890C;
    local.status[142] = lbl_27_bss_890C;
    local.status[143] = lbl_27_bss_890C;
    local.status[144] = lbl_27_bss_890C;
    local.status[145] = lbl_27_bss_88EC;
    local.status[146] = lbl_27_bss_88FC;
    local.status[148] = lbl_27_bss_8004;
    local.status[149] = lbl_27_bss_8014;
    local.status[150] = lbl_27_bss_73CC;
    local.status[151] = lbl_27_bss_8A9C;
    local.status[152] = lbl_27_bss_897C;
    local.status[153] = lbl_27_bss_897C;
    local.status[154] = lbl_27_bss_897C;
    local.status[155] = lbl_27_bss_897C;
    local.status[157] = lbl_27_bss_75C4;
    local.status[158] = lbl_27_bss_75E4;
    local.status[160] = lbl_27_bss_75F4;
    local.status[161] = lbl_27_bss_75D4;
    local.status[162] = lbl_27_bss_7604;
    local.status[163] = lbl_27_bss_7D74;

    soModuleAccesser** access = (soModuleAccesser**)(self + 0x60);
    (*access)->m_enumerationStart->m_statusModule->addRangeUniqProc(
        (soStatusUniqProcess*)local.status, 0xAE);
    int count = fn_27_10B2A4(g_ftManager, INT(self, 0x10C));
    for (int i = 0; i < count; ++i) {
        fn_96_1C4E8(self + 0x1B72C, fn_27_10B2E4(g_ftManager, INT(self, 0x10C), i));
    }

    KirbyCommonDataView* commonView = (KirbyCommonDataView*)self;
    (*access)->m_enumerationStart->m_collisionShieldModule->add(
        (soCollisionShieldGroupData*)(commonView->data + 0x15C), 1);

    local.reflector.data = 0;
    local.reflector.count = 0;
    local.reflector.x = rodata[2];
    local.reflector.y = rodata[2];
    local.reflector.z = rodata[2];
    local.reflector.scale = rodata[2];
    local.reflector.active = 0;
    fn_27_195B34(PTR(commonView->data, 0x16C), local.reflectorOutput, &local.reflector);
    (*access)->m_enumerationStart->m_collisionReflectorModule->add(
        (soCollisionReflectorGroupData*)&local.reflector, 2);
    (*access)->m_enumerationStart->m_collisionReflectorModule->setStatus(0, 0, 2);

    ((InitialArea*)(*access)->m_enumerationStart->m_areaModule)->addArea(
        commonView->data + 0x17C);
    ((InitialArea*)(*access)->m_enumerationStart->m_areaModule)->setStatus(9, 0, -1);
    ((InitialArea*)(*access)->m_enumerationStart->m_areaModule)->setStatus(10, 0, -1);
    ((InitialArea*)(*access)->m_enumerationStart->m_areaModule)->setStatus(11, 0, -1);
    return self;
}
