#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>

#pragma force_active on

class soAnimCmdEventObserver;
template <class T> class soEventObserver {
public:
    static void __vt(int, int);
};

extern "C" {
extern char lbl_27_data_1180[];

void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FA50(void*, int);
void fn_27_C940C(void*, int);
void fn_27_25290(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);

#define DT(name) void* name(void*, short);
DT(__dt__16acCmdInterpreterFv)
DT(fn_27_63EBC)
DT(fn_27_5C674)
DT(fn_27_97968)
DT(fn_27_A1E80)
DT(fn_27_5B39C)
DT(fn_27_6A3D8)
DT(fn_27_565F0)
DT(fn_27_6880C)
DT(__dt__16soStopModuleImplFv)
DT(fn_27_B5324)
DT(__dt__19soPostureModuleImplFv)
DT(fn_27_13C90)
DT(__dt__17soModelModuleImplFv)
DT(__dt__20soResourceModuleImplFv)
DT(__dt__16soHeapModuleImplFv)
DT(__dt__16soModuleAccesserFv)
DT(fn_27_18D3DC)
DT(fn_27_D597C)
DT(fn_27_18D6CC)
DT(fn_27_18D788)
DT(__dt__23soEventManageModuleImplFv)
DT(fn_27_1D81C8)
#undef DT
}

#define EVENT_TYPE(T, N) \
    class T; \
    template <> class soEventUnitWithWorkArea<T, N> { \
    public: \
        ~soEventUnitWithWorkArea(); \
    };

EVENT_TYPE(soMotionEventObserver, 1)
EVENT_TYPE(soItemManageEventObserver, 1)
EVENT_TYPE(soCollisionSearchEventObserver, 4)
EVENT_TYPE(soCollisionAbsorberEventObserver, 4)
EVENT_TYPE(soCollisionReflectorEventObserver, 4)
EVENT_TYPE(soCollisionShieldEventObserver, 4)
EVENT_TYPE(soCaptureEventObserver, 4)
EVENT_TYPE(soModelEventObserver, 4)
EVENT_TYPE(soCollisionAttackEventObserver, 4)
EVENT_TYPE(soCollisionHitEventObserver, 4)
EVENT_TYPE(soSituationEventObserver, 4)
EVENT_TYPE(soDamageEventObserver, 4)
#undef EVENT_TYPE

struct Obs {
    void* vt;
    short manager;
    short event;
    short send;
    short pad;
};

struct Obj {
    char pad[0x1180];
    Obs a;
    Obs b;
};

#define RELEASE(ent, table) \
    if (&(ent)) { \
        if (&(ent)) { \
            short id = (ent).manager; \
            (ent).vt = table; \
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) \
                soEventSystem::getInstance()->getManager((ent).manager)->eraseObserver((ent).event, (ent).send); \
            (ent).send = -1; \
            (ent).manager = -1; \
        } \
    }

#define EVENT(T, N, offset) \
    reinterpret_cast<soEventUnitWithWorkArea<T, N>*>(p + offset)->~soEventUnitWithWorkArea()

extern "C" Obj* fn_27_3ABDD0(Obj* self, int flag) {
    if (self) {
        if (self) {
            char* p = (char*)self;
            if (p + 0xcc) {
                if (p + 0x1478) {
                    if (p + 0x15ac) {
                        if (p + 0x15ac)
                            __dt__16acCmdInterpreterFv(p + 0x15ac, 0);
                    }
                    if (p + 0x147c) {
                        if (p + 0x1558)
                            __dt__16acCmdInterpreterFv(p + 0x1558, 0);
                    }
                }
                if (p + 0xcc) {
                    if (p + 0x1434) fn_27_63EBC(p + 0x1434, -1);
                    if (p + 0x141c) fn_27_5C674(p + 0x141c, -1);
                    if (p + 0x1280) {
                        fn_27_97968(p + 0x12d8, -1);
                        if (p + 0x1280) {
                            if (p + 0x1280)
                                __destroy_arr(p + 0x128c, fn_27_9FA50, 0x2c, 1);
                        }
                    }
                    if (p + 0x1178) {
                        if (p + 0x119c) {
                            if (p + 0x11ac)
                                __destroy_arr(p + 0x11b8, fn_27_C940C, 0x10, 6);
                        }
                        if (p + 0x1178) {
                            RELEASE(self->b, (void*)soEventObserver<soAnimCmdEventObserver>::__vt);
                            RELEASE(self->a, lbl_27_data_1180);
                        }
                    }
                    if (p + 0x1144) fn_27_A1E80(p + 0x1144, -1);
                    if (p + 0x1110) fn_27_5B39C(p + 0x1110, -1);
                    if (p + 0xfac) fn_27_6A3D8(p + 0x10bc, -1);
                    if (p + 0xf44) fn_27_565F0(p + 0xf50, -1);
                    if (p + 0xf38) fn_27_6880C(p + 0xf3c, -1);
                    if (p + 0xf10) __dt__16soStopModuleImplFv(p + 0xf10, -1);
                    if (p + 0xea0) fn_27_B5324(p + 0xec0, -1);
                    if (p + 0xde8) {
                        __dt__19soPostureModuleImplFv(p + 0xe24, -1);
                        if (p + 0xde8) {
                            if (p + 0xde8)
                                __destroy_arr(p + 0xdf4, fn_27_25290, 0x30, 1);
                        }
                    }
                    if (p + 0xbdc) {
                        fn_27_13C90(p + 0xc78, -1);
                        if (p + 0xbdc) {
                            if (p + 0xbfc) {
                                if (p + 0xbfc) {
                                    if (p + 0xbfc) {
                                        if (p + 0xbfc)
                                            __destroy_arr(p + 0xc08, fn_27_AB510, 0x10, 4);
                                    }
                                }
                            }
                            if (p + 0xbdc)
                                __destroy_arr(p + 0xbe8, fn_27_AB18C, 0x14, 1);
                        }
                    }
                    if (p + 0x9fc) __dt__17soModelModuleImplFv(p + 0xb10, -1);
                    if (p + 0x9cc) __dt__20soResourceModuleImplFv(p + 0x9e4, -1);
                    if (p + 0x9a4) __dt__16soHeapModuleImplFv(p + 0x9a4, -1);
                    __dt__16soModuleAccesserFv(p + 0x8c4, -1);
                    if (p + 0xcc) {
                        EVENT(soMotionEventObserver, 1, 0x888);
                        EVENT(soItemManageEventObserver, 1, 0x850);
                        EVENT(soCollisionSearchEventObserver, 4, 0x7f4);
                        EVENT(soCollisionAbsorberEventObserver, 4, 0x798);
                        EVENT(soCollisionReflectorEventObserver, 4, 0x73c);
                        EVENT(soCollisionShieldEventObserver, 4, 0x6e0);
                        EVENT(soCaptureEventObserver, 4, 0x684);
                        fn_27_18D3DC(p + 0x640, -1);
                        EVENT(soModelEventObserver, 4, 0x5e4);
                        EVENT(soCollisionAttackEventObserver, 4, 0x588);
                        EVENT(soCollisionHitEventObserver, 4, 0x52c);
                        EVENT(soSituationEventObserver, 4, 0x4d0);
                        fn_27_D597C(p + 0x48c, -1);
                        EVENT(soDamageEventObserver, 4, 0x430);
                        fn_27_18D6CC(p + 0x284, -1);
                        fn_27_18D788(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<
                            soEventUnit*,
                            soArrayVector<soInstanceUnit<soEventUnit*>, 19>
                        >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
