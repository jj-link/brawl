#pragma force_active on
#pragma use_simple_stdpnew on
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <new>

extern "C" {
extern char lbl_27_data_20878[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_46658[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern char lbl_27_data_128[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_7C14;
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual int fn_27_14A28(long);
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
};
class Class_1F90 {
public:
    virtual void fn_27_1EFD0();
    virtual void fn_27_E240();
    virtual void fn_27_E190();
    virtual void fn_27_E1A0();
    virtual int fn_27_1D2D0(long);
    virtual void fn_27_1D200();
    virtual void fn_27_1D240();
    virtual void fn_27_1EF00();
    virtual void* fn_27_1EF7C(long);
};
class Class_18ED8 {
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
class Class_32B8 {
public:
    virtual void fn_27_3544C();
    virtual void fn_27_3557C();
    virtual void fn_27_355AC();
    virtual void fn_27_35C14();
    virtual void fn_27_35BE0();
    virtual void fn_27_35BE8();
    virtual void fn_27_355B8();
    virtual int fn_27_35C04();
    virtual void fn_27_35834();
};
struct Pack { void* interpreter; void* addressPack; };
struct CommandKind { short value; char padding[2]; };
class Class_4C28 {
public:
    virtual void fn_27_510BC();
    virtual void fn_27_51074(Pack*, short*);
    virtual void fn_27_5428C();
    virtual void fn_27_51094();
    virtual void fn_27_510A8();
    virtual void fn_27_50358();
    virtual void fn_27_51024();
    virtual void fn_27_5108C();
    virtual void fn_27_50620();
};
struct EventData {
    void* vt;
    short managerId;
    short eventId;
    int value;
};
struct Interpreter {
    unsigned char base[0x34];
    EventData event;
    int kind;
    int a;
    int b;
    int c;
};
struct StackEntry : acCmdInterpreterStackData {
    StackEntry() : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_7C14) {}
};
struct StackStorage {
    void* arrayVt;
    void* arrayVt2;
    unsigned int flags : 8;
    unsigned int flags2 : 8;
    unsigned int remaining : 16;
    StackEntry entries[8];
    StackStorage() : arrayVt(lbl_27_data_15218), arrayVt2(lbl_27_data_15218 + 0x48), flags(0), flags2(0) {}
};
struct Self {
    void* vt;
    int link;
    void* elements;
    int size;
    int pad10;
    StackStorage stack;
    void* packVt;
    char padC4[12];
    Self* owner;
    void* pack1;
    void* pack2;
    Interpreter interpreter;
};
inline void resetData(acCmdInterpreterStackData* p) {
    p->kind = acCmdInterpreterStackData::Invalid;
    p->intData = 0;
    p->boolData = false;
    p->addressData = 0;
    p->floatData = lbl_27_rodata_7C14;
}
inline int getResult(EventData* self) {
    short id = self->eventId;
    Class_1F90* manager = (Class_1F90*)soEventSystem::getInstance()->getManager(self->managerId);
    if (manager->fn_27_1D2D0(id) == 0) return 0;
    Class_18ED8* unit = (Class_18ED8*)__dynamic_cast(manager->fn_27_1EF7C(id), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
    if (unit == 0) return 0;
    return unit->slot7();
}
extern "C" Self* fn_27_37D4C8(Self* self, void* arg, void* elements, float step) {
    self->link = 0;
    self->vt = lbl_27_data_20878;
    self->elements = elements;
    self->size = 0x203;
    if (elements == 0) self->size = 0;
    new (&self->stack) StackStorage;
    self->owner = self;
    self->packVt = lbl_27_data_46658;
    Interpreter* interp;
    int result = 0;
    StackStorage* storage = &self->stack;
    void** packBase = (void**)(storage + 1);
    packBase[5] = lbl_27_bss_D8C;
    packBase[6] = lbl_27_bss_D8C;
    unsigned char reset = 0;
    char* context = *(char**)((char*)arg + 0xd8);
    char* obj = *(char**)(context + 0x80);
    int eid = ((Class_32B8*)(obj + 8))->fn_27_35C04();
    interp = &self->interpreter;
    new (interp) acCmdInterpreter((soArrayVector<acCmdInterpreterStackData, 8>*)storage, 1, 0, &reset, step);
    interp->event.vt = lbl_27_data_466B8;
    interp->event.managerId = eid;
    interp->event.eventId = 5;
    interp->event.value = result;
    int eventId = (short)eid;
    if (eventId > 0 && eventId > -1) {
        if (((Class_1250*)soEventSystem::getInstance())->fn_27_14A28(eventId) != 0) {
            Class_1F90* mgr = (Class_1F90*)soEventSystem::getInstance()->getManager(interp->event.managerId);
            if (mgr->fn_27_1D2D0(interp->event.eventId) == 0) {
                interp->event.value = 0;
            } else {
                short id = interp->event.eventId;
                Class_1F90* manager = (Class_1F90*)soEventSystem::getInstance()->getManager(interp->event.managerId);
                if (manager->fn_27_1D2D0(id) == 0) {
                    result = 0;
                } else {
                    Class_18ED8* unit = (Class_18ED8*)__dynamic_cast(manager->fn_27_1EF7C(id), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (unit == 0) result = 0;
                    else result = unit->slot7();
                }
                interp->event.value = result;
            }
        }
    }
    *(void**)interp = lbl_27_data_81A0;
    interp->event.vt = lbl_27_data_81A0 + 0x20;
    interp->kind = 1;
    interp->a = 0;
    interp->b = 0;
    interp->c = 0;
    CommandKind kind;
    kind.value = 2;
    Pack pack = { &self->interpreter, &self->packVt };
    context = *(char**)((char*)arg + 0xd8);
    ((Class_4C28*)*(void**)(context + 0x6c))->fn_27_51074(&pack, &kind.value);
    return self;
}