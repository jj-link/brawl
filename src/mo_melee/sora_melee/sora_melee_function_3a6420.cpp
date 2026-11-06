#pragma force_active on
class soEventUnit;
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
template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;
template <class T, class S> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_D597C(void*, short);
void fn_27_9FA50(void*, int);
void fn_27_25290(void*, int);
void fn_27_AB18C(void*, int);
void fn_27_AB510(void*, int);
}

extern "C" void* fn_27_3A6420(char* self, int flag) {
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
                reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(self + 0x888)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(self + 0x850)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(self + 0x7F4)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(self + 0x798)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(self + 0x73C)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(self + 0x6E0)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(self + 0x684)->~soEventUnitWithWorkArea();
                fn_27_18D3DC(self + 0x640, -1);
                reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(self + 0x5E4)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(self + 0x588)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(self + 0x52C)->~soEventUnitWithWorkArea();
                reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(self + 0x4D0)->~soEventUnitWithWorkArea();
                fn_27_D597C(self + 0x48C, -1);
                reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(self + 0x430)->~soEventUnitWithWorkArea();
                fn_27_18D6CC(self + 0x284, -1);
                fn_27_18D788(self + 0x198, -1);
                __dt__23soEventManageModuleImplFv(self + 0x184, -1);
                reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(self + 0xCC)->~soInstanceManagerSimpleEntity();
            }
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
