#include <gf/gf_task.h>
#pragma force_active on

namespace {
class Identity {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
public:
    virtual int getId() = 0;
};

class IdentityModule {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
public:
    virtual Identity* getIdentity() = 0;
};

class StatusModule {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
public:
    virtual int getKind() = 0;
};

struct StatePrefix {
    unsigned int words[2];
};

class StateModule : public StatePrefix {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
public:
    virtual unsigned int getState() = 0;
};

class WorkModule {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
public:
    virtual void setInt(int, int) = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void onFlag(int) = 0;
};

class GrabModule {
    virtual void slot8() = 0;
    virtual void slotC() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void slot78() = 0;
    virtual void slot7C() = 0;
    virtual void slot80() = 0;
    virtual void slot84() = 0;
    virtual void slot88() = 0;
    virtual void slot8C() = 0;
    virtual void slot90() = 0;
    virtual void slot94() = 0;
    virtual void slot98() = 0;
    virtual void slot9C() = 0;
    virtual void slotA0() = 0;
    virtual void slotA4() = 0;
    virtual void slotA8() = 0;
    virtual void slotAC() = 0;
public:
    virtual unsigned int getTaskId(int) = 0;
    virtual void slotB4() = 0;
    virtual void slotB8() = 0;
    virtual void slotBC() = 0;
    virtual void slotC0() = 0;
    virtual void slotC4() = 0;
    virtual void slotC8() = 0;
    virtual void slotCC() = 0;
    virtual void slotD0() = 0;
    virtual void slotD4() = 0;
    virtual void slotD8() = 0;
    virtual void slotDC() = 0;
    virtual void slotE0() = 0;
    virtual void slotE4() = 0;
    virtual void slotE8() = 0;
    virtual void slotEC() = 0;
    virtual void slotF0() = 0;
    virtual void slotF4() = 0;
    virtual void slotF8() = 0;
    virtual void slotFC() = 0;
    virtual void slot100() = 0;
    virtual void slot104() = 0;
    virtual void slot108() = 0;
    virtual void slot10C() = 0;
    virtual void slot110() = 0;
    virtual void slot114() = 0;
    virtual void slot118() = 0;
    virtual void slot11C() = 0;
    virtual void slot120() = 0;
    virtual void slot124() = 0;
    virtual void slot128() = 0;
    virtual void slot12C() = 0;
    virtual void slot130() = 0;
    virtual void slot134() = 0;
    virtual void slot138() = 0;
    virtual void slot13C() = 0;
    virtual void slot140() = 0;
    virtual void slot144() = 0;
    virtual void slot148() = 0;
    virtual void slot14C() = 0;
    virtual void slot150() = 0;
    virtual void slot154() = 0;
    virtual void slot158() = 0;
    virtual void slot15C() = 0;
    virtual void slot160() = 0;
    virtual void slot164() = 0;
public:
    virtual unsigned int isActive() = 0;
};

struct Modules {
    unsigned char pad0[0x18];
    IdentityModule* identity;
    unsigned char pad1[0x54 - 0x1C];
    GrabModule* grab;
    unsigned char pad2[0x64 - 0x58];
    WorkModule* work;
    unsigned char pad3[0x70 - 0x68];
    StatusModule* status;
    unsigned char pad4[0xBC - 0x74];
    StateModule* state;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Object {
    unsigned char pad[0x60];
    Accesser* accesser;
};

struct Event {
    unsigned char pad0[0xC];
    unsigned int taskId;
    unsigned char pad1[0x20 - 0x10];
    signed char id;
    unsigned char type;
    unsigned char kind;
    unsigned char pad2;
    unsigned char value;
};
}

extern "C" void fn_113_1A314(Object* object, Event* event) {
    if (event == 0) return;
    if (object->accesser->modules->status->getKind() != 0x15) return;
    if (event->type == 3) {
        if (event->id == object->accesser->modules->identity->getIdentity()->getId()) return;
        if (object->accesser->modules->state->getState() != 1) return;
        object->accesser->modules->work->onFlag(0x22000001);
        return;
    }
    if (event->type == 2 || event->kind != 0xA ||
        event->id == object->accesser->modules->identity->getIdentity()->getId()) return;
    if (object->accesser->modules->grab->isActive() == 1 &&
        event->taskId == object->accesser->modules->grab->getTaskId(3)) return;
    if (gfTask::getTask(event->taskId) == 0) return;
    object->accesser->modules->work->setInt(event->taskId, 0x20000000);
    object->accesser->modules->work->setInt(event->value, 0x20000001);
}
