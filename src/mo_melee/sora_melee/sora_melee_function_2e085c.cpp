#include <so/event/so_event_system.h>
#pragma force_active on
class soMotionEventObserver;
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
class soItemManageEventObserver;
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionSearchEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionAbsorberEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionReflectorEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionShieldEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCaptureEventObserver;
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soModelEventObserver;
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soCollisionHitEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soSituationEventObserver;
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
class soDamageEventObserver;
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
void fn_27_9FA50(void*, int);
void fn_27_25290(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);
}
extern "C" void* fn_27_2E085C(char* self, int flags) {
    if (self) {
        if (self) {
            if (self + 0xCC && self + 0xCC) {
                if (self + 0x1498) fn_27_63EBC(self + 0x1498, -1);
                if (self + 0x1480) fn_27_5C674(self + 0x1480, -1);
                if (self + 0x1328) fn_27_BED74(self + 0x1328, -1);
                if (self + 0x1190) {
                    fn_27_97968(self + 0x11E8, -1);
                    if (self + 0x1190 && self + 0x1190)
                        __destroy_arr(self + 0x119C, fn_27_9FA50, 0x2C, 1);
                }
                if (self + 0x10F4) fn_27_A1E80(self + 0x10F4, -1);
                if (self + 0x10DC) fn_27_5AE44(self + 0x10DC, -1);
                if (self + 0xF78) fn_27_6A3D8(self + 0x1088, -1);
                if (self + 0xF10) fn_27_565F0(self + 0xF1C, -1);
                if (self + 0xF04) fn_27_6880C(self + 0xF08, -1);
                if (self + 0xEDC) __dt__16soStopModuleImplFv(self + 0xEDC, -1);
                if (self + 0xE6C) fn_27_B5324(self + 0xE8C, -1);
                if (self + 0xDE8) {
                    fn_27_252D0(self + 0xE24, -1);
                    if (self + 0xDE8 && self + 0xDE8)
                        __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 1);
                }
                if (self + 0xBDC) {
                    fn_27_13C90(self + 0xC78, -1);
                    if (self + 0xBDC) {
                        if (self + 0xBFC && self + 0xBFC && self + 0xBFC && self + 0xBFC)
                            __destroy_arr(self + 0xC08, fn_27_AB510, 0x10, 4);
                        if (self + 0xBDC)
                            __destroy_arr(self + 0xBE8, fn_27_AB18C, 0x14, 1);
                    }
                }
                if (self + 0x9FC) __dt__17soModelModuleImplFv(self + 0xB10, -1);
                if (self + 0x9CC) __dt__20soResourceModuleImplFv(self + 0x9E4, -1);
                if (self + 0x9A4) __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                if (self + 0xCC) {
                    reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(self + 0x888)->soEventUnitWithWorkArea<soMotionEventObserver, 1>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(self + 0x850)->soEventUnitWithWorkArea<soItemManageEventObserver, 1>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(self + 0x7f4)->soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(self + 0x798)->soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(self + 0x73c)->soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(self + 0x6e0)->soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(self + 0x684)->soEventUnitWithWorkArea<soCaptureEventObserver, 4>::~soEventUnitWithWorkArea();
                    fn_27_18D3DC(self + 0x640, -1);
                    reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(self + 0x5e4)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(self + 0x588)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(self + 0x52c)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(self + 0x4d0)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
                    fn_27_D597C(self + 0x48C, -1);
                    reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(self + 0x430)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
                    fn_27_18D6CC(self + 0x284, -1);
                    fn_27_18D788(self + 0x198, -1);
                    __dt__23soEventManageModuleImplFv(self + 0x184, -1);
                    reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(self + 0xCC)->~soInstanceManagerSimpleEntity();
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flags > 0) __dl__FPv(self);
    }
    return self;
}
