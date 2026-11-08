#include <so/so_instance_manager.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>
class soEventUnit;
template <class T, int N> class soEventUnitWithWorkArea { public: ~soEventUnitWithWorkArea(); };

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
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}
extern "C" void* fn_107_4974(void* object, short deleting) {
 if (object) {
  char* storage = static_cast<char*>(object);
  short destroy = -1;
  reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x7bc)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x784)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x728)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x6cc)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x670)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x614)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x5b8)->~soEventUnitWithWorkArea();
  fn_27_18D3DC(storage + 0x574, destroy);
  reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x518)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x4bc)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x460)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x404)->~soEventUnitWithWorkArea();
  fn_27_D597C(storage + 0x3c0, destroy);
  reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x364)->~soEventUnitWithWorkArea();
  fn_27_18D6CC(storage + 0x1b8, destroy);
  fn_27_18D788(storage + 0xcc, destroy);
  __dt__23soEventManageModuleImplFv(storage + 0xb8, destroy);
  reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
  if (deleting > 0) operator delete(object);
 }
 return object;
}