#include <types.h>
#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_20878[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_46658[];
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern char lbl_27_data_128[];
extern char lbl_27_bss_D8C[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_7C14;

void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct StackEntry : acCmdInterpreterStackData {
    StackEntry()
        : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_7C14) {}
};

struct StackStorage {
    void* arrayVtable;
    void* arrayVtable2;
    s32 topIndex : 5;
    s32 lastIndex : 5;
    s32 size : 5;
    u32 isFull : 1;
    StackEntry entries[8];

    StackStorage()
        : arrayVtable(lbl_27_data_15218),
          arrayVtable2(lbl_27_data_15218 + 0x48),
          topIndex(0),
          lastIndex(0),
          size(0),
          isFull(0) {}
};

struct Obj {
    char pad[0x14];
    StackStorage stack;
    struct AddressPack {
        void* vtable;
        char cachedAddresses[0xc];
        Obj* owner;
        void* second;
        void* third;
    } addressPack;
    char interpreter[0x50];
};

struct InterpreterRegistration {
    void* interpreter;
    Obj::AddressPack* addressPack;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual s32 slot7();
    virtual void slot8();
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 value();
};

struct CommandKind {
    s16 value;
    char padding[2];
};

struct Listener {
    virtual void v0();
    virtual void v1(InterpreterRegistration*, const s16*);
};

extern "C" Obj* fn_27_37FBA0(Obj* self, void* arg1, s32 mode, f32 dt) {
    *(s32*)((char*)self + 4) = 0;
    *(void**)((char*)self) = lbl_27_data_20878;
    *(s32*)((char*)self + 8) = mode;
    *(s32*)((char*)self + 12) = 0x29;
    if (mode == 0)
        *(s32*)((char*)self + 12) = 0;

    new (&self->stack) StackStorage;

    self->addressPack.owner = self;
    self->addressPack.vtable = lbl_27_data_46658;
    acCmdInterpreter* ip;
    s32 result = 0;
    StackStorage* storage = &self->stack;
    Obj::AddressPack* pack = (Obj::AddressPack*)(storage + 1);
    pack->second = lbl_27_bss_D8C;
    pack->third = lbl_27_bss_D8C;

    soArrayVector<acCmdInterpreterStackData, 8>* stack =
        (soArrayVector<acCmdInterpreterStackData, 8>*)storage;
    u8 flag = result;
    void* ctx = *(void**)((char*)arg1 + 0xd8);
    void* src = *(void**)((char*)ctx + 0x80);
    s32 id = ((Object_vptr_0*)((char*)src + 8))->slot7();

    new (ip = (acCmdInterpreter*)self->interpreter) acCmdInterpreter(
        stack, 1, 0, &flag, dt);

    *(void**)((char*)ip + 0x34) = lbl_27_data_466B8;
    *(s16*)((char*)ip + 0x38) = id;
    *(s16*)((char*)ip + 0x3a) = 5;
    *(s32*)((char*)ip + 0x3c) = result;

    s32 eventId = (s16)id;
    if (eventId > 0 && eventId > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(eventId)) {
            soEventManager* mgr = soEventSystem::getInstance()->getManager(
                *(s16*)((char*)ip + 0x38));
            if (mgr->getObserverCapacity(*(s16*)((char*)ip + 0x3a)) == 0) {
                *(s32*)((char*)ip + 0x3c) = result;
            } else {
                s16 kind = *(s16*)((char*)ip + 0x3a);
                soEventManager* mgr2 = soEventSystem::getInstance()->getManager(
                    *(s16*)((char*)ip + 0x38));
                if (mgr2->getObserverCapacity(kind) == 0) {
                    result = 0;
                } else {
                    void* data = mgr2->getEventUnit(kind);
                    Unit* unit = (Unit*)__dynamic_cast(
                        data, 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (unit == 0) {
                        result = 0;
                    } else {
                        result = unit->value();
                    }
                }
                *(s32*)((char*)ip + 0x3c) = result;
            }
        }
    }

    *(void**)((char*)ip) = lbl_27_data_81A0;
    *(void**)((char*)ip + 0x34) = lbl_27_data_81A0 + 0x20;
    *(s32*)((char*)ip + 0x40) = 10;
    *(s32*)((char*)ip + 0x44) = 0;
    *(s32*)((char*)ip + 0x48) = 0;
    *(s32*)((char*)ip + 0x4c) = 0;

    CommandKind commandKind;
    commandKind.value = 16;
    InterpreterRegistration registration;
    registration.interpreter = self->interpreter;
    registration.addressPack = &self->addressPack;
    void* target = *(void**)((char*)*(void**)((char*)arg1 + 0xd8) + 0x6c);
    ((Listener*)target)->v1(&registration, &commandKind.value);
    return self;
}