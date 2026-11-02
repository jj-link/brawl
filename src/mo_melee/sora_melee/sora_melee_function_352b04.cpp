#include <so/event/so_event_system.h>

#pragma force_active on

class soAnimCmdEventObserver;

template <typename T>
class soEventObserver {
public:
    static void __vt(int, int);
};

class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;

#define DECLARE_EVENT_UNIT(T, N) \
    template <> class soEventUnitWithWorkArea<T, N> { \
    public: \
        ~soEventUnitWithWorkArea(); \
    }

DECLARE_EVENT_UNIT(soMotionEventObserver, 1);
DECLARE_EVENT_UNIT(soItemManageEventObserver, 1);
DECLARE_EVENT_UNIT(soCollisionSearchEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionAbsorberEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionReflectorEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionShieldEventObserver, 4);
DECLARE_EVENT_UNIT(soCaptureEventObserver, 4);
DECLARE_EVENT_UNIT(soModelEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionAttackEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionHitEventObserver, 4);
DECLARE_EVENT_UNIT(soSituationEventObserver, 4);
DECLARE_EVENT_UNIT(soDamageEventObserver, 4);

extern "C" {
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);

void fn_27_9FA50(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);
void fn_27_C940C(void*, int);
void fn_27_25290(void*, int);
void fn_27_137EC(void*, int);

void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void __dl__FPv(void*);

extern char lbl_27_data_731C[];
extern char lbl_27_data_1180[];
}

#define EVENT_UNIT_DTOR(T, N, OFFSET) \
    reinterpret_cast<soEventUnitWithWorkArea<T, N>*>(p + OFFSET) \
        ->~soEventUnitWithWorkArea()

#define REMOVE_OBSERVER(OFFSET, VTABLE) \
    do { \
        short id = *reinterpret_cast<short*>(p + (OFFSET) + 4); \
        *reinterpret_cast<void**>(p + (OFFSET)) = (void*)(VTABLE); \
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) { \
            soEventSystem::getInstance()->getManager( \
                *reinterpret_cast<short*>(p + (OFFSET) + 4))->eraseObserver( \
                *reinterpret_cast<short*>(p + (OFFSET) + 6), \
                *reinterpret_cast<short*>(p + (OFFSET) + 8)); \
        } \
        *reinterpret_cast<short*>(p + (OFFSET) + 8) = -1; \
        *reinterpret_cast<short*>(p + (OFFSET) + 4) = -1; \
    } while (0)

extern "C" void* fn_27_352B04(void* object, int deleting) {
    char* p = static_cast<char*>(object);

    if (p) {
        if (p + 0x16BC)
            fn_27_5C674(p + 0x16BC, -1);
        if (p + 0x1564)
            fn_27_BED74(p + 0x1564, -1);

        if (p + 0x13CC) {
            fn_27_97968(p + 0x1424, -1);
            if (p + 0x13CC && p + 0x13CC)
                __destroy_arr(p + 0x13D8, fn_27_9FA50, 0x2C, 1);
        }

        if (p + 0x11AC) {
            if (p + 0x12BC) {
                if (p + 0x12DC && p + 0x12DC) {
                    REMOVE_OBSERVER(0x12DC, lbl_27_data_731C);
                }
                if (p + 0x12D0 && p + 0x12D0) {
                    REMOVE_OBSERVER(0x12D0, soEventObserver<soAnimCmdEventObserver>::__vt);
                }
            }
            if (p + 0x11F4) {
                if (p + 0x1214 && p + 0x1214 &&
                    p + 0x1214 && p + 0x1214)
                    __destroy_arr(p + 0x1220, fn_27_AB510, 0x10, 6);
                if (p + 0x11F4)
                    __destroy_arr(p + 0x1200, fn_27_AB18C, 0x14, 1);
            }
        }

        if (p + 0x1108) {
            if (p + 0x112C && p + 0x113C)
                __destroy_arr(p + 0x1148, fn_27_C940C, 0x10, 6);

            if (p + 0x1108) {
                if (p + 0x111C && p + 0x111C) {
                    REMOVE_OBSERVER(0x111C, soEventObserver<soAnimCmdEventObserver>::__vt);
                }
                if (p + 0x1110 && p + 0x1110) {
                    REMOVE_OBSERVER(0x1110, lbl_27_data_1180);
                }
            }
        }

        if (p + 0x10D4)
            fn_27_A1E80(p + 0x10D4, -1);
        if (p + 0x10BC)
            fn_27_5AE44(p + 0x10BC, -1);
        if (p + 0x0F58)
            fn_27_6A3D8(p + 0x1068, -1);
        if (p + 0x0EF0)
            fn_27_565F0(p + 0x0EFC, -1);
        if (p + 0x0EE4)
            fn_27_6880C(p + 0x0EE8, -1);
        if (p + 0x0EBC)
            __dt__16soStopModuleImplFv(p + 0x0EBC, -1);
        if (p + 0x0E4C)
            fn_27_B5324(p + 0x0E6C, -1);
        if (p + 0x0E10)
            fn_27_3544C(p + 0x0E10, -1);

        if (p + 0x0D58) {
            __dt__19soPostureModuleImplFv(p + 0x0D94, -1);
            if (p + 0x0D58 && p + 0x0D58)
                __destroy_arr(p + 0x0D64, fn_27_25290, 0x30, 1);
        }

        if (p + 0x0B10) {
            fn_27_13C90(p + 0x0BE8, -1);
            if (p + 0x0B98 && p + 0x0B98)
                __destroy_arr(p + 0x0BA4, fn_27_137EC, 0x2C, 1);
            if (p + 0x0B10) {
                if (p + 0x0B30 && p + 0x0B30 &&
                    p + 0x0B30 && p + 0x0B30)
                    __destroy_arr(p + 0x0B3C, fn_27_AB510, 0x10, 4);
                if (p + 0x0B10)
                    __destroy_arr(p + 0x0B1C, fn_27_AB18C, 0x14, 1);
            }
        }

        if (p + 0x0930)
            __dt__17soModelModuleImplFv(p + 0x0A44, -1);
        if (p + 0x0900)
            __dt__20soResourceModuleImplFv(p + 0x0918, -1);
        if (p + 0x08D8)
            __dt__16soHeapModuleImplFv(p + 0x08D8, -1);

        __dt__16soModuleAccesserFv(p + 0x07F8, -1);

        if (p) {
            EVENT_UNIT_DTOR(soMotionEventObserver, 1, 0x07BC);
            EVENT_UNIT_DTOR(soItemManageEventObserver, 1, 0x0784);
            EVENT_UNIT_DTOR(soCollisionSearchEventObserver, 4, 0x0728);
            EVENT_UNIT_DTOR(soCollisionAbsorberEventObserver, 4, 0x06CC);
            EVENT_UNIT_DTOR(soCollisionReflectorEventObserver, 4, 0x0670);
            EVENT_UNIT_DTOR(soCollisionShieldEventObserver, 4, 0x0614);
            EVENT_UNIT_DTOR(soCaptureEventObserver, 4, 0x05B8);
            fn_27_18D3DC(p + 0x0574, -1);
            EVENT_UNIT_DTOR(soModelEventObserver, 4, 0x0518);
            EVENT_UNIT_DTOR(soCollisionAttackEventObserver, 4, 0x04BC);
            EVENT_UNIT_DTOR(soCollisionHitEventObserver, 4, 0x0460);
            EVENT_UNIT_DTOR(soSituationEventObserver, 4, 0x0404);
            fn_27_D597C(p + 0x03C0, -1);
            EVENT_UNIT_DTOR(soDamageEventObserver, 4, 0x0364);
            fn_27_18D6CC(p + 0x01B8, -1);
            fn_27_18D788(p + 0x00CC, -1);
            __dt__23soEventManageModuleImplFv(p + 0x00B8, -1);
            reinterpret_cast<
                soInstanceManagerSimpleEntity<
                    soEventUnit*,
                    soArrayVector<soInstanceUnit<soEventUnit*>, 19>
                >*
            >(p)->~soInstanceManagerSimpleEntity();
        }

        if (deleting > 0)
            __dl__FPv(p);
    }

    return object;
}
