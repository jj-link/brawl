#include <so/so_value_accesser.h>
#pragma force_active on
struct Prefix { char pad[8]; };
class Motion : public Prefix {
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
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual float slot42();
    virtual int slot43();
};
class Status {
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
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual unsigned int slot48(int);
    virtual int slot49(int);
};
class Action {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, soModuleAccesser*);
};
struct Modules {
    char pad[0x38];
    Motion* motion;
    char pad2[0x18];
    Status* status;
    char pad3[0x18];
    Action* action;
};
struct Object {
    char pad[0x10];
    soModuleAccesser* accesser;
    char pad2[0x14];
    float timer;
};
extern "C" int fn_27_66864(Object* self, int arg) {
    self->timer += ((Modules*)self->accesser->m_enumerationStart)->motion->slot42();
    if (self->timer >= soValueAccesser::getConstantFloat(self->accesser, 0x7f2, 0))
        return 0;
    unsigned int result = 0;
    if (((Modules*)self->accesser->m_enumerationStart)->motion->slot43() == 0) {
        if (((Modules*)self->accesser->m_enumerationStart)->status->slot48(0) == 1U) {
            if (((Modules*)self->accesser->m_enumerationStart)->status->slot49(0) == 0)
                result = 1;
        } else {
            result = 1;
        }
    }
    if (result == 1) {
        if (arg != -1)
            ((Modules*)self->accesser->m_enumerationStart)->action->slot3(arg, self->accesser);
        return 1;
    }
    return 0;
}