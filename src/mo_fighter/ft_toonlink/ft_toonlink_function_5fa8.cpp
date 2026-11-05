#include <so/event/so_event_system.h>
#pragma force_active on
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
template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
extern "C" {
void* fn_121_62B8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_121_62F8(void*, short);
void* fn_121_6394(void*, short);
void* fn_121_63F0(void*, short);
void* fn_121_644C(void*, short);
void* fn_121_229C(void*, short);
void* fn_121_64A8(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_121_6508(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_121_6564(void*, short);
void* fn_121_65C4(void*, short);
void* fn_121_2240(void*, short);
void* fn_121_664C(void*, short);
void* fn_121_66A8(void*, short);
void* fn_121_6714(void*, short);
void* fn_121_6774(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_121_2C0C(void*, short);
void* fn_121_6800(void*, short);
void* fn_121_6888(void*, short);
void* fn_121_68F4(void*, short);
void* fn_121_696C(void*, short);
void* fn_121_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dl__FPv(void*);
#pragma dont_inline on
void* fn_121_5FA8(void* object, short deleting) {
 if (object) {
 unsigned char* p = static_cast<unsigned char*>(object);
 short d = -1;
 fn_121_62B8(p+0x16ac,d);
 fn_27_C7770(p+0x169c,d);
 if (object) {
 if (p+0xcc) {
 if (p+0x1564 && p+0x1568) {
 fn_121_62F8(p+0x1644,d);
 fn_121_62B8(p+0x1628,d);
 fn_121_6394(p+0x157c,d);
 if(p+0x1568) fn_27_C7770(p+0x1568,d);
 }
 if(p+0xcc) {
 short e = -1;
 fn_121_63F0(p+0x1548,e);
 fn_121_644C(p+0x13f0,e);
 fn_121_229C(p+0x13a4,e);
 fn_121_64A8(p+0x1354,e);
 if(p+0x11b4) {
 fn_27_97968(p+0x1218,e);
 fn_27_1CCCC(p+0x1208,e);
 fn_121_6508(p+0x11ec,e);
 if(p+0x11b4) fn_27_CBF58(p+0x11b4,e);
 }
 short f=-1;
 fn_121_6564(p+0x1154,f);
 fn_121_65C4(p+0x10ac,f);
 fn_121_2240(p+0x1078,f);
 fn_121_664C(p+0x1060,f);
 fn_121_66A8(p+0xefc,f);
 fn_121_6714(p+0xeec,f);
 fn_121_6774(p+0xe7c,f);
 if(p+0xe30) fn_27_252D0(p+0xe34,f);
 if(p+0xbe8) {
 short g=-1;
 fn_27_13C90(p+0xcc0,g);
 fn_27_21038(p+0xcac,g);
 fn_121_2C0C(p+0xc70,g);
 fn_121_6800(p+0xbe8,g);
 }
 short h=-1;
 fn_121_6888(p+0xa08,h);
 fn_121_68F4(p+0x9d8,h);
 fn_121_696C(p+0x9c8,h);
 fn_121_1F54(p+0x9b0,h);
 __dt__16soModuleAccesserFv(p+0x8d0,h);
 if(p+0xcc) {
 reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p+0x894)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p+0x85c)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p+0x800)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p+0x7a4)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p+0x748)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p+0x6ec)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p+0x690)->~soEventUnitWithWorkArea();
 fn_27_18D3DC(p+0x64c,h);
 fn_27_18D498(p+0x5e4,h);
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p+0x588)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p+0x52c)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p+0x4d0)->~soEventUnitWithWorkArea();
 fn_27_D597C(p+0x48c,h);
 reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p+0x430)->~soEventUnitWithWorkArea();
 fn_27_18D6CC(p+0x284,h);
 fn_27_18D788(p+0x198,h);
 __dt__23soEventManageModuleImplFv(p+0x184,h);
 reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
 }
 }
 }
 fn_27_1D81C8(object,0);
 }
 if(deleting>0) __dl__FPv(object);
 }
 return object;
}
#pragma dont_inline reset
}