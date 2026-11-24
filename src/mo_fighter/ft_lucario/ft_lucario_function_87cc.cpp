#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#include <new>
#pragma force_active on

#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_118_data_21B8[];
extern char lbl_118_data_21B0[];
extern char lbl_118_data_2210[];
extern char lbl_27_data_81A0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int slot7();
    virtual void slot8();
};

struct Self {
    char base[0x34];
    void* vtable2;
    short manager;
    short event;
    int result;
    int arg;
    int a;
    int b;
    int c;
};

extern "C" Self* fn_118_87CC(
    Self& self,
    short id,
    soArrayVector<acCmdInterpreterStackData, 8>* stack,
    int arg,
    int mode,
    const u8* reset,
    float step)
{
    new (&self) acCmdInterpreter(stack, mode, 0, reset, step);

    self.vtable2 = lbl_118_data_21B8;
    self.manager = id;
    self.event = 5;
    int result = 0;
    self.result = result;

    s32 idx = id;
    if (id > 0 && (s16)idx > -1) {
        short check = self.manager;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(check)) {
            if (!soEventSystem::getInstance()
                     ->getManager(self.manager)
                     ->getObserverCapacity(self.event)) {
                self.result = result;
            } else {
                soEventManager* manager;
                short event = self.event;
                manager = soEventSystem::getInstance()->getManager(self.manager);

                if (!manager->getObserverCapacity(event)) {
                    result = 0;
                } else {
                    Object_vptr_0* object = (Object_vptr_0*)__dynamic_cast(
                        manager->getEventUnit(event), 0,
                        lbl_118_data_21B0, lbl_118_data_2210, 0);
                    if (object == NULL) {
                        result = 0;
                    } else {
                        result = object->slot7();
                    }
                }
                self.result = result;
            }
        }
    }

    *(void**)&self = lbl_27_data_81A0;
    self.vtable2 = lbl_27_data_81A0 + 0x20;
    self.arg = arg;
    self.a = 0;
    self.b = 0;
    self.c = 0;
    return &self;
}
