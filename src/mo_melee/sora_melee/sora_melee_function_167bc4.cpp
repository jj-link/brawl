#include <so/controller/so_controller_impl.h>
#pragma force_active on

class WorkModule {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);
};

class ControlModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual unsigned int slot38();
};

struct Access;
class OtherModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, Access*);
};

struct Modules {
    char pad[0x5c];
    ControlModule* control;
    char pad60[4];
    WorkModule* work;
    char pad68[8];
    OtherModule* other;
};
struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_1677E0(void*, Access*, int);
extern "C" void fn_27_19585C(Access*);

static inline unsigned int test(ControlModule* control) {
    unsigned int mask = soController::getButtonMask(soController::Pad_Button_Special);
    unsigned int buttons = control->slot38();
    return buttons & mask;
}

extern "C" void fn_27_167BC4(void* self, Access* access) {
    if (access->modules->work->slot17(0x1200000b) == 1) {
        ControlModule* control = access->modules->control;
        unsigned int mask = soController::getButtonMask(soController::Pad_Button_Attack);
        unsigned int buttons = control->slot38();
        if ((buttons & mask) ||
            test(access->modules->control)) {
            access->modules->control->slot4();
            access->modules->other->slot3(0xe4, access);
        } else {
            fn_27_1677E0(self, access, 0);
        }
    } else {
        fn_27_19585C(access);
        fn_27_1677E0(self, access, 1);
    }
}