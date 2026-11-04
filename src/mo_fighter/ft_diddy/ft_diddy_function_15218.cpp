template <class Observer, int Capacity> class soEventUnitWithWorkArea { public: ~soEventUnitWithWorkArea(); };
class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;
template <class T, class S> class soInstanceManagerSimpleEntity { public: ~soInstanceManagerSimpleEntity(); };
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
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
extern "C" void* fn_27_18D3DC(void*, short);
extern "C" void* fn_27_18D498(void*, short);
extern "C" void* fn_27_D597C(void*, short);
extern "C" void* fn_27_18D6CC(void*, short);
extern "C" void* fn_27_18D788(void*, short);
void operator delete(void*);
#pragma force_active on
extern "C" void* fn_115_15218(void* object, short deleting) {
 if (object) {
  unsigned char* storage = static_cast<unsigned char*>(object);
  reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x7c8)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x790)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x734)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x6d8)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x67c)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x620)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x5c4)->~soEventUnitWithWorkArea();
  fn_27_18D3DC(storage + 0x580, -1);
  fn_27_18D498(storage + 0x518, -1);
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x4bc)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x460)->~soEventUnitWithWorkArea();
  reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x404)->~soEventUnitWithWorkArea();
  fn_27_D597C(storage + 0x3c0, -1);
  reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x364)->~soEventUnitWithWorkArea();
  fn_27_18D6CC(storage + 0x1b8, -1);
  fn_27_18D788(storage + 0xcc, -1);
  __dt__23soEventManageModuleImplFv(storage + 0xb8, -1);
  reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
  if (deleting > 0) operator delete(object);
 }
 return object;
}