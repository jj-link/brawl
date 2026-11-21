#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void __dl__FPv(void*);
class soKineticEnergy;
template <> class soInstanceUnitFullProperty<soKineticEnergy*> {
public:
    char data[12];
    ~soInstanceUnitFullProperty();
};
struct EnergyArray {
    char pad[12];
    soInstanceUnitFullProperty<soKineticEnergy*> units[2];
    ~EnergyArray() {}
};
struct EnergyManager {
    char pad[16];
    EnergyArray array;
    ~EnergyManager() {}
};

class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };

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

extern "C" void* fn_27_1E2F5C(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        p->energy.~EnergyManager();
        if (p) {
            if ((char*)p + 0x20 && (char*)p + 0x20) {
                s16 id = p->m24;
                p->v20 = (void*)lbl_27_data_1180;
                if (((Object_vptr_0*)soEventSystem::getInstance())->slot6(id) == 1) {
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
                    if (((Object_vptr_0*)soEventSystem::getInstance())->slot6(id) == 1) {
                        soEventManager* mgr = soEventSystem::getInstance()->getManager(p->mC);
                        mgr->eraseObserver(p->mE, p->m10);
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