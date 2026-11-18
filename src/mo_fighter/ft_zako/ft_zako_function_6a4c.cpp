#include <new>
#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <so/anim/so_anim_cmd_event_presenter.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class Class_BD8 {
public:
    virtual void fn_126_51C8();
    virtual void fn_126_186C();
    virtual void fn_126_73D0();
    virtual void fn_126_73C8();
    virtual void fn_126_73C0();
    virtual void fn_126_73B8();
    virtual void fn_126_73B0();
    virtual soInstanceManagerFullProperty<soAnimCmdEventObserver*>* fn_126_73A8();
    virtual void fn_126_73A0();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern unsigned char lbl_126_data_16A0[];
extern unsigned char lbl_126_data_1698[];
extern unsigned char lbl_126_data_16F8[];
extern unsigned char lbl_27_data_81A0[];
}

struct Interpreter {
    unsigned char base[0x34];
    void* presenterVtable;
    short managerId;
    short unitId;
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* observers;
    void* accesser;
    int field44;
    int field48;
    int field4C;
};

inline bool hasManager(s16 id) {
    s16 copy = id;
    return soEventSystem::getInstance()->getInstanceManager().isContain(copy);
}

extern "C" Interpreter* fn_126_6A4C(
    Interpreter* self, s16 id,
    soArrayVector<acCmdInterpreterStackData, 8>* stack,
    void* accesser, int mode, const unsigned char* resetMode, float step)
{
    soInstanceManagerFullProperty<soAnimCmdEventObserver*>* observers;
    soEventManager* mgr;

    new (self) acCmdInterpreter(stack, mode, 0, resetMode, step);

    self->presenterVtable = lbl_126_data_16A0;
    self->managerId = id;
    self->unitId = 5;
    self->observers = 0;
    observers = self->observers;

    s32 checkedId = (s16)id;
    if (checkedId > 0 && (s16)checkedId > -1) {
        s16 managerId = self->managerId;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(managerId)) {
            if (soEventSystem::getInstance()->getManager(self->managerId)
                    ->getObserverCapacity(self->unitId) == 0) {
                self->observers = observers;
            } else {
                short uid = self->unitId;
                mgr = soEventSystem::getInstance()->getManager(self->managerId);
                if (mgr->getObserverCapacity(uid) == 0) {
                    observers = 0;
                } else {
                    Class_BD8* unit = static_cast<Class_BD8*>(__dynamic_cast(
                        mgr->getEventUnit(uid), 0, lbl_126_data_1698,
                        lbl_126_data_16F8, 0));
                    if (unit == 0) {
                        observers = 0;
                    } else {
                        observers = unit->fn_126_73A8();
                    }
                }
                self->observers = observers;
            }
        }
    }

    *reinterpret_cast<void**>(self) = lbl_27_data_81A0;
    self->presenterVtable = lbl_27_data_81A0 + 0x20;
    self->accesser = accesser;
    self->field44 = 0;
    self->field48 = 0;
    self->field4C = 0;
    return self;
}
