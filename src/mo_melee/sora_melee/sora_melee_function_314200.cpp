#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_1E0CC4(void* p, int n);
void fn_27_1E0D04(void* p, int n);
void fn_27_1E0D44(void* p, int n);
void fn_27_18D3DC(void* p, int n);
void fn_27_18D498(void* p, int n);
void fn_27_1AA40C(void* p, int n);
void fn_27_1A9648(void* p, int n);
void fn_27_D597C(void* p, int n);
void __dt__23soEventManageModuleImplFv(void* p, int n);
void __dl__FPv(void* p);
}

struct soMotionEventObserver {};
struct soItemManageEventObserver {};
struct soCollisionSearchEventObserver {};
struct soCollisionAbsorberEventObserver {};
struct soCollisionReflectorEventObserver {};
struct soCollisionShieldEventObserver {};
struct soCaptureEventObserver {};
struct soCollisionAttackEventObserver {};
struct soCollisionHitEventObserver {};
struct soSituationEventObserver {};
struct soDamageEventObserver {};

template<class T, int N>
struct soEventUnitWithWorkArea {
    ~soEventUnitWithWorkArea();
};

struct soEventUnit {};
template<class T, int N> struct soArrayVector {};
template<class T> struct soInstanceUnit {};
template<class A, class B>
struct soInstanceManagerSimpleEntity {
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_27_314200(void* self, int flag) {
    if (self) {
        u8* base = (u8*)self;
        fn_27_1E0CC4(base + 0x81a, -1);
        fn_27_1E0D04(base + 0x819, -1);
        fn_27_1E0D44(base + 0x818, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(base + 0x7E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(base + 0x7A8)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(base + 0x74C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(base + 0x6F0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(base + 0x694)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(base + 0x638)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(base + 0x5DC)->~soEventUnitWithWorkArea();
        fn_27_18D3DC(base + 0x598, -1);
        fn_27_18D498(base + 0x530, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(base + 0x4D4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(base + 0x478)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(base + 0x41C)->~soEventUnitWithWorkArea();
        fn_27_D597C(base + 0x3D8, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(base + 0x37C)->~soEventUnitWithWorkArea();
        fn_27_1AA40C(base + 0x1C4, -1);
        fn_27_1A9648(base + 0xCC, -1);
        __dt__23soEventManageModuleImplFv(base + 0xB8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(self)->~soInstanceManagerSimpleEntity();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
