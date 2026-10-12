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

// Fixed embedded layout of Pikachu's event-management aggregate.
class PikachuEventStorage {
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > instances;
    soEventManageModuleImpl manager;
    soEventUnitWithWorkArea<soStatusEventObserver, 32> status;
    soEventUnitWithWorkArea<soAnimCmdEventObserver, 40> animCmd;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    soEventUnitWithWorkArea<soLinkEventObserver, 4> link;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    soEventUnitWithWorkArea<soArticleEventObserver, 5> article;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion;
    unsigned char motionPadding[4];
    soEventUnitWithWorkArea<soTurnEventObserver, 2> turn;
    soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> catchUnit;
public:
    PikachuEventStorage();
};

PikachuEventStorage::PikachuEventStorage()
    : manager(this),
      status(manager.getManageId(), 4),
      animCmd(manager.getManageId(), 5),
      damage(manager.getManageId(), 6),
      link(manager.getManageId(), 7),
      situation(manager.getManageId(), 8),
      hit(manager.getManageId(), 0),
      attack(manager.getManageId(), 1),
      model(manager.getManageId(), 9),
      article(manager.getManageId(), 11),
      capture(manager.getManageId(), 13),
      shield(manager.getManageId(), 14),
      reflector(manager.getManageId(), 15),
      absorber(manager.getManageId(), 16),
      search(manager.getManageId(), 17),
      item(manager.getManageId(), 12),
      motion(manager.getManageId(), 10),
      turn(manager.getManageId(), 18),
      catchUnit(manager.getManageId(), 2) {
}
