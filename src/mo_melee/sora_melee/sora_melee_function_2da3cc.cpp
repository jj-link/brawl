#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;
template <class T, class Storage> class soInstanceManagerSimpleEntity {
    unsigned char storage[0xB8];
public:
    soInstanceManagerSimpleEntity();
};
template <class Observer, int N> class soEventUnitWithWorkArea {
    unsigned char storage[0x2C + 12 * N];
public:
    soEventUnitWithWorkArea(short, short);
};
class soDamageEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
class soNullable {
public:
    virtual bool isNull() const;
    bool nullable;
};
class soEventManager {
public:
    virtual short addUnit(soEventUnit*);
    virtual void eraseUnit(unsigned int);
    virtual bool isNullUnit(unsigned int);
    virtual void eraseObserver(short, short);
    virtual unsigned int getObserverCapacity(unsigned int);
    virtual unsigned int getObserverSize(unsigned int);
    virtual bool isExist(short);
    virtual short getManageId();
    virtual soEventUnit* getEventUnit(short);
};
class soEventManageModuleImpl : public soNullable, public soEventManager {
    void* instanceManager;
    short manageId;
    short padding;
public:
    soEventManageModuleImpl(void*);
    virtual short addUnit(soEventUnit*);
    virtual void eraseUnit(unsigned int);
    virtual bool isNullUnit(unsigned int);
    virtual void eraseObserver(unsigned int, int);
    virtual unsigned int getObserverCapacity(unsigned int);
    virtual unsigned int getObserverSize(unsigned int);
    virtual bool isExist(short);
    virtual short getManageId();
    virtual soEventUnit* getEventUnit(short);
};

extern "C" void fn_27_1A9430(void*, short, short);
extern "C" void fn_27_1AA1F4(void*, short, short);
extern "C" void fn_27_D5878(void*, short, short);
extern "C" void fn_27_1AA878(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1E1074(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_2DA3CC(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9430(base + 0xCC, mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1AA1F4(base + 0x1B8, mgr, 5);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x364) soEventUnitWithWorkArea<soDamageEventObserver, 4>(mgr, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D5878(base + 0x3C0, mgr, 7);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x404) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x460) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(mgr, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x4BC) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x518) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1AA878(base + 0x574, mgr, 0xB);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x5B8) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 0xD);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x614) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 0xE);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x670) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 0xF);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x6CC) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 0x10);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x728) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 0x11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x784) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 0xC);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7BC) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 0xA);
    fn_27_1E1070(base + 0x7F4, -1, 3);
    fn_27_1E1074(base + 0x7F5, -1, 0x12);
    fn_27_1E1078(base + 0x7F6, -1, 2);
    return self;
}
