#include <types.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>
#include <so/so_instance_manager.h>
#pragma force_active on

class soAnimCmdEventObserver;
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;

class soEventUnit;

class soEventManager {
public:
    virtual s16 addUnit(soEventUnit*);
    virtual void eraseUnit(u32);
    virtual bool isNullUnit(u32);
    virtual void eraseObserver(s16 id, s16 sendID);
    virtual u32 getObserverCapacity(u32 index);
    virtual u32 getObserverSize(u32 index);
    virtual bool isExist(short);
    virtual s16 getManageId();
    virtual soEventUnit* getEventUnit(short);
};

class soEventSystem {
public:
    soInstanceManagerSimpleEntity<soEventManager*, soArrayVector<soInstanceUnit<soEventManager*>, 500 > > m_instanceManager;

    soEventManager* getManager(s32 manageID);
    static soEventSystem* getInstance();
    soInstanceManager<soEventManager*>& getInstanceManager() { return m_instanceManager; }
};

template <typename T> class soEventObserver {
public:
    static void __vt(int, int);
};

template <typename T, s32 C> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" {
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_97968(void*, short);
void fn_27_9FA50(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);
void fn_27_C940C(void*, int);
void* fn_27_A1E80(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_13C90(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
extern char lbl_27_data_731C[];
extern char lbl_27_data_1180[];
}

#define OBS_RELEASE(off, vt)                                                              \
    if (p + (off) && p + (off)) {                                                         \
        s16 id = *(s16*)(p + (off) + 4);                                                  \
        *(void**)(p + (off)) = (vt);                                                      \
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1)        \
            soEventSystem::getInstance()->getManager(*(s16*)(p + (off) + 4))              \
                ->eraseObserver(*(s16*)(p + (off) + 6), *(s16*)(p + (off) + 8));          \
        *(s16*)(p + (off) + 8) = -1;                                                      \
        *(s16*)(p + (off) + 4) = -1;                                                      \
    }

extern "C" void* fn_27_36513C(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        if (p + 0x1618) fn_27_C31CC(p + 0x1618, -1);
        if (p + 0x15D8) fn_27_63EBC(p + 0x15D8, -1);
        if (p + 0x15C0) fn_27_5C674(p + 0x15C0, -1);
        if (p + 0x1468) fn_27_BED74(p + 0x1468, -1);
        if (p + 0x12D0) {
            fn_27_97968(p + 0x1328, -1);
            if (p + 0x12D0 && p + 0x12D0) __destroy_arr(p + 0x12DC, fn_27_9FA50, 0x2C, 1);
        }
        if (p + 0x10A8) {
            if (p + 0x11C0) {
                OBS_RELEASE(0x11E0, lbl_27_data_731C)
                OBS_RELEASE(0x11D4, (void*)soEventObserver<soAnimCmdEventObserver>::__vt)
            }
            if (p + 0x10F0) {
                if (p + 0x1110 && p + 0x1110 && p + 0x1110 && p + 0x1110) __destroy_arr(p + 0x111C, fn_27_AB510, 0x10, 6);
                if (p + 0x10F0) __destroy_arr(p + 0x10FC, fn_27_AB18C, 0x14, 1);
            }
        }
        if (p + 0x1004) {
            if (p + 0x1028) {
                if (p + 0x1038) __destroy_arr(p + 0x1044, fn_27_C940C, 0x10, 6);
            }
            if (p + 0x1004) {
                OBS_RELEASE(0x1018, (void*)soEventObserver<soAnimCmdEventObserver>::__vt)
                OBS_RELEASE(0x100C, lbl_27_data_1180)
            }
        }
        if (p + 0xFD0) fn_27_A1E80(p + 0xFD0, -1);
        if (p + 0xF9C) fn_27_5B39C(p + 0xF9C, -1);
        if (p + 0xE38) fn_27_6A3D8(p + 0xF48, -1);
        if (p + 0xDD0) fn_27_565F0(p + 0xDDC, -1);
        if (p + 0xDC4) fn_27_6880C(p + 0xDC8, -1);
        if (p + 0xD9C) __dt__16soStopModuleImplFv(p + 0xD9C, -1);
        if (p + 0xD2C) fn_27_B5324(p + 0xD4C, -1);
        if (p + 0xB1C) {
            fn_27_13C90(p + 0xBB8, -1);
            if (p + 0xB1C) {
                if (p + 0xB3C && p + 0xB3C && p + 0xB3C && p + 0xB3C) __destroy_arr(p + 0xB48, fn_27_AB510, 0x10, 4);
                if (p + 0xB1C) __destroy_arr(p + 0xB28, fn_27_AB18C, 0x14, 1);
            }
        }
        if (p + 0x93C) __dt__17soModelModuleImplFv(p + 0xA50, -1);
        if (p + 0x90C) __dt__20soResourceModuleImplFv(p + 0x924, -1);
        if (p + 0x8E4) __dt__16soHeapModuleImplFv(p + 0x8E4, -1);
        __dt__16soModuleAccesserFv(p + 0x804, -1);
        if (self) {
            reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x7C8)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x790)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x734)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x6D8)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x67C)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x620)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x5C4)->~soEventUnitWithWorkArea();
            fn_27_18D3DC(p + 0x580, -1);
            fn_27_18D498(p + 0x518, -1);
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x4BC)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x460)->~soEventUnitWithWorkArea();
            reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x404)->~soEventUnitWithWorkArea();
            fn_27_D597C(p + 0x3C0, -1);
            reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x364)->~soEventUnitWithWorkArea();
            fn_27_18D6CC(p + 0x1B8, -1);
            fn_27_18D788(p + 0xCC, -1);
            __dt__23soEventManageModuleImplFv(p + 0xB8, -1);
            reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(self)->~soInstanceManagerSimpleEntity();
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
