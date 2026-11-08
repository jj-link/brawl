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
    soEventUnitWithWorkArea(short managerId, short eventId);
};
class soStatusEventObserver;
class soAnimCmdEventObserver;
class soDamageEventObserver;
class soLinkEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soArticleEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
class soTurnEventObserver;
class soCollisionCatchEventObserver;

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

extern "C" void* fn_109_6870(void* self) {
    char* base = static_cast<char*>(self);
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    new (base + 0xCC) soEventUnitWithWorkArea<soStatusEventObserver, 32>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 4);
    new (base + 0x278) soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 5);
    new (base + 0x484) soEventUnitWithWorkArea<soDamageEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 6);
    new (base + 0x4E0) soEventUnitWithWorkArea<soLinkEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 7);
    new (base + 0x53C) soEventUnitWithWorkArea<soSituationEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 8);
    new (base + 0x598) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 0);
    new (base + 0x5F4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 1);
    new (base + 0x650) soEventUnitWithWorkArea<soModelEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 9);
    new (base + 0x6AC) soEventUnitWithWorkArea<soArticleEventObserver, 5>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 11);
    new (base + 0x714) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 13);
    new (base + 0x770) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 14);
    new (base + 0x7CC) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 15);
    new (base + 0x828) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 16);
    new (base + 0x884) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 17);
    new (base + 0x8E0) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 12);
    new (base + 0x918) soEventUnitWithWorkArea<soMotionEventObserver, 1>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 10);
    new (base + 0x954) soEventUnitWithWorkArea<soTurnEventObserver, 2>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 18);
    new (base + 0x998) soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>(reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId(), 2);
    return self;
}
