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
class soCollisionAttackEventObserver;
class soModelEventObserver;

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

extern "C" void fn_27_D6358(void*, short, short);
extern "C" void fn_27_1A9C84(void*, short, short);
extern "C" void fn_27_2E6790(void*, short, short);
extern "C" void fn_27_D56A8(void*, short, short);
extern "C" void fn_27_2E6794(void*, short, short);
extern "C" void fn_27_2E6798(void*, short, short);
extern "C" void fn_27_D6A98(void*, short, short);
extern "C" void fn_27_2E679C(void*, short, short);
extern "C" void fn_27_D7CB8(void*, short, short);
extern "C" void fn_27_2E67A0(void*, short, short);
extern "C" void fn_27_2E67A4(void*, short, short);
extern "C" void fn_27_2ECF40(void*, short, short);
extern "C" void fn_27_2E67A8(void*, short, short);
extern "C" void fn_27_2E67AC(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1A8A0C(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_2ECD14(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6358(base + 0xCC, mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9C84(base + 0x188, mgr, 5);
    fn_27_2E6790(base + 0x28C, -1, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D56A8(base + 0x290, mgr, 7);
    fn_27_2E6794(base + 0x2C8, -1, 8);
    fn_27_2E6798(base + 0x2C9, -1, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x2CC) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x328) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6A98(base + 0x384, mgr, 0xB);
    fn_27_2E679C(base + 0x3BC, -1, 0xD);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7CB8(base + 0x3C0, mgr, 0xE);
    fn_27_2E67A0(base + 0x3F8, -1, 0xF);
    fn_27_2E67A4(base + 0x3F9, -1, 0x10);
    fn_27_2ECF40(base + 0x3FA, -1, 0x11);
    fn_27_2E67A8(base + 0x3FB, -1, 0xC);
    fn_27_2E67AC(base + 0x3FC, -1, 0xA);
    fn_27_1E1070(base + 0x3FD, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8A0C(base + 0x400, mgr, 0x12);
    fn_27_1E1078(base + 0x474, -1, 2);
    return self;
}
