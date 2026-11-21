#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_125_data_2EE4[];
extern char lbl_125_data_2EDC[];
extern char lbl_125_data_2F3C[];
extern char lbl_27_data_81A0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Object_vptr_0 {
public:
    virtual void fn_125_8060();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void* slot7();
    virtual void slot8();
};

struct Self {
    char base[0x34];
    void* vtable;
    short manager;
    short unit;
    void* list;
    void* field40;
    void* field44;
    void* field48;
    void* field4c;
};

extern "C" Self* fn_125_9CC0(
    Self* self,
    short id,
    soArrayVector<acCmdInterpreterStackData, 8>* stack,
    void* arg,
    int mode,
    const u8* reset,
    float step)
{
    new (self) acCmdInterpreter(stack, mode, 0, reset, step);

    self->vtable = lbl_125_data_2EE4;
    self->manager = id;
    self->unit = 5;
    void* list = 0;
    soEventManager* mgr;
    self->list = 0;

    int idx = id;
    if (id > 0) {
        if ((short)idx > -1) {
            short check = self->manager;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
                if (!soEventSystem::getInstance()->getManager(self->manager)
                         ->getObserverCapacity(self->unit)) {
                    self->list = list;
                } else {
                    short unit = self->unit;
                    mgr = soEventSystem::getInstance()->getManager(self->manager);

                    if (!mgr->getObserverCapacity(unit)) {
                        list = 0;
                    } else {
                        Object_vptr_0* obj = (Object_vptr_0*)__dynamic_cast(
                            mgr->getEventUnit(unit), 0, lbl_125_data_2EDC,
                            lbl_125_data_2F3C, 0);
                        if (obj == 0) {
                            list = 0;
                        } else {
                            list = obj->slot7();
                        }
                    }
                    self->list = list;
                }
            }
        }
    }

    *(void**)self = lbl_27_data_81A0;
    self->vtable = lbl_27_data_81A0 + 0x20;
    self->field40 = arg;
    self->field44 = 0;
    self->field48 = 0;
    self->field4c = 0;
    return self;
}
