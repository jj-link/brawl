#include <types.h>

#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);

class soKineticEnergy;
class soAnimCmdEventObserver;

template <class T>
class soInstanceUnitFullProperty {
public:
    T m_element;
    int m_id;
    s16 m_attribute;
    s16 m_10;
    ~soInstanceUnitFullProperty();
};

template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

struct EnergyArray {
    char pad[12];
    soInstanceUnitFullProperty<soKineticEnergy*> units[8];
    ~EnergyArray() {}
};

struct EnergyManager {
    char pad[16];
    EnergyArray array;
    ~EnergyManager() {}
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual u32 slot6(s16);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16, s16);
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

extern "C" void* fn_27_2DB610(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        p->energy.~EnergyManager();
        if (p) {
            if ((char*)p + 0x20 && (char*)p + 0x20) {
                s16 id = p->m24;
                p->v20 = (void*)lbl_27_data_1180;
                if (((Object_vptr_0*)getInstance__13soEventSystemFv())->slot6(id) == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), p->m24);
                    mgr->v3(p->m26, p->m28);
                }
                p->m28 = -1;
                p->m24 = -1;
            }
            if (p) {
                if ((char*)p + 8 && (char*)p + 8) {
                    s16 id = p->mC;
                    p->v8 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                    if (((Object_vptr_0*)getInstance__13soEventSystemFv())->slot6(id) == 1) {
                        EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                            getInstance__13soEventSystemFv(), p->mC);
                        mgr->v3(p->mE, p->m10);
                    }
                    p->m10 = -1;
                    p->mC = -1;
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
