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

// ABI-only declarations: the manager's constructors and virtual methods live
// in sora_melee. Its secondary soEventManager base starts at byte 8.
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

extern "C" void* fn_105_8138(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0xCC) soEventUnitWithWorkArea<soStatusEventObserver, 32>(mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x278) soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>(mgr, 5);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x484) soEventUnitWithWorkArea<soDamageEventObserver, 4>(mgr, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x4E0) soEventUnitWithWorkArea<soLinkEventObserver, 4>(mgr, 7);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x53C) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x598) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(mgr, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x5F4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x650) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x6AC) soEventUnitWithWorkArea<soArticleEventObserver, 5>(mgr, 11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x714) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x770) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 14);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7CC) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 15);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x828) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x884) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 17);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x8E0) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 12);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x918) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 10);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x954) soEventUnitWithWorkArea<soTurnEventObserver, 2>(mgr, 18);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x998) soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>(mgr, 2);
    return self;
}