#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void __dl__FPv(void*);

class soEventUnit;
class soEventManager {
public:
    virtual s16 addUnit(soEventUnit*);
    virtual void eraseUnit(u32);
    virtual bool isNullUnit(u32);
    virtual void eraseObserver(s16, s16);
    virtual u32 getObserverCapacity(u32);
    virtual u32 getObserverSize(u32);
    virtual bool isExist(short);
    virtual s16 getManageId();
    virtual soEventUnit* getEventUnit(short);
};

class soEventSystem {
public:
    static soEventSystem* getInstance();
    soEventManager* getManager(s32);
};

template <class T> class soInstanceUnitFullProperty {
public:
    T m_element;
    int m_id;
    s16 m_attribute;
    s16 m_10;
    ~soInstanceUnitFullProperty();
};

class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
class soKineticEnergy;

struct EnergyArray {
    char pad[12];
    soInstanceUnitFullProperty<soKineticEnergy*> units[12];
    ~EnergyArray() {}
};

struct EnergyManager {
    char pad[16];
    EnergyArray array;
    ~EnergyManager() {}
};

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16);
};

struct Obj {
    u32 m0;
    u32 m4;
    void* v8;
    s16 mC;
    s16 mE;
    s16 m10;
    char pad12[14];
    void* v20;
    s16 m24;
    s16 m26;
    s16 m28;
    char pad2A[6];
    EnergyManager energy;
};

extern "C" void* fn_27_313AA0(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        p->energy.~EnergyManager();
        if (p) {
            if ((char*)p + 0x20 && (char*)p + 0x20) {
                s16 id = p->m24;
                p->v20 = (void*)lbl_27_data_1180;
                if (((EvSys*)soEventSystem::getInstance())->v6(id) == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m24);
                    mgr->eraseObserver(p->m26, p->m28);
                }
                p->m28 = -1;
                p->m24 = -1;
            }
            if (p) {
                if ((char*)p + 8 && (char*)p + 8) {
                    s16 id = p->mC;
                    p->v8 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                    if (((EvSys*)soEventSystem::getInstance())->v6(id) == 1) {
                        soEventManager* mgr = soEventSystem::getInstance()->getManager(p->mC);
                        mgr->eraseObserver(p->mE, p->m10);
                    }
                    p->m10 = -1;
                    p->mC = -1;
                }
            }
        }
        if (flag > 0) __dl__FPv(arg);
    }
    return arg;
}
