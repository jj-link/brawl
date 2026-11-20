#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_102_data_1EC8[];
extern char lbl_102_data_1ED0[];
extern char lbl_102_data_203C[];
extern char lbl_27_data_81A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct FtKoopaCmdInterpreter : public acCmdInterpreter {
    void* m_presenterVtbl; // 0x34
    s16 m_manageID;        // 0x38
    s16 m_unitID;          // 0x3a
    void* m_observerList;  // 0x3c
    s32 m_unk40;           // 0x40
    s32 m_unk44;           // 0x44
    s32 m_unk48;           // 0x48
    s32 m_unk4C;           // 0x4c
};

class FtKoopaDynIface {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
};

extern "C" FtKoopaCmdInterpreter* fn_102_7C50(FtKoopaCmdInterpreter* self, s16 id,
    soArrayVector<acCmdInterpreterStackData, 8>* stk, s32 arg3, s32 mode,
    const u8* resetMode, float fixedTimeStep)
{
    void* list;
    s16 id2;
    new (self) acCmdInterpreter(stk, mode, 0, resetMode, fixedTimeStep);
    self->m_presenterVtbl = lbl_102_data_1ED0;
    self->m_manageID = id;
    self->m_unitID = 5;
    list = 0;
    self->m_observerList = list;
    s32 idx = id;
    if (id > 0 && (s16)idx > -1) {
        id2 = self->m_manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id2)) {
            if (soEventSystem::getInstance()->getManager(self->m_manageID)->getObserverCapacity(self->m_unitID) == 0) {
                self->m_observerList = list;
            } else {
                soEventManager* mgr;
                s16 unitID = self->m_unitID;
                mgr = soEventSystem::getInstance()->getManager(self->m_manageID);
                if (mgr->getObserverCapacity(unitID) == 0) {
                    list = 0;
                } else {
                    void* q = __dynamic_cast(mgr->getEventUnit(unitID), 0, lbl_102_data_1EC8, lbl_102_data_203C, 0);
                    if (q == 0) {
                        list = 0;
                    } else {
                        list = reinterpret_cast<FtKoopaDynIface*>(q)->f7();
                    }
                }
                self->m_observerList = list;
            }
        }
    }
    *reinterpret_cast<void**>(self) = lbl_27_data_81A0;
    self->m_presenterVtbl = lbl_27_data_81A0 + 0x20;
    self->m_unk40 = arg3;
    self->m_unk44 = 0;
    self->m_unk48 = 0;
    self->m_unk4C = 0;
    return self;
}