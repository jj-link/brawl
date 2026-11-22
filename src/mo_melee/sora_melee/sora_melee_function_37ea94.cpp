#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern u8 lbl_27_data_20878[];
extern u8 lbl_27_data_15218[];
extern u8 lbl_27_data_46658[];
extern u8 lbl_27_data_466B8[];
extern u8 lbl_27_data_81A0[];
extern u8 lbl_27_bss_D8C[];
extern u8 lbl_27_data_128[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_7C14;

void* __dynamic_cast(void*, long, const void*, const void*, long);
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
    virtual s32 slot7();
    virtual void slot8();
};

struct EventSystemView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int has(long);
    virtual void v7();
    virtual void v8();
};

struct EventManagerView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int has(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* get(long);
};

struct EventUnitView {
    virtual void v0();
    virtual void v1(void*, s16*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int value();
    virtual void v8();
};

struct Entry {
    s32 a; s32 b; u8 c; s32 d; f32 e;
    Entry() : a(-1), b(0), c(0), d(0), e(lbl_27_rodata_7C14) {}
};

struct StackInit {
    u8* vt;
    u8* vt2;
    u32 flags : 8;
    u32 flags2 : 8;
    u32 remaining : 16;
    Entry entries[8];

    StackInit() : vt(lbl_27_data_15218), vt2(lbl_27_data_15218 + 0x48),
        flags(0), flags2(0) {}
};

struct Self {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    StackInit stack;
    u32 fc0;
    u32 fc4;
    u32 fc8;
    u32 fcc;
    u32 fd0;
    u32 fd4;
    u32 fd8;
    u8 interpreter[0x80];
};

inline s32 getObserverList(acCmdInterpreter* interpreter) {
    s16 kind = *(s16*)((u8*)interpreter + 0x3a);
    EventManagerView* manager =
        (EventManagerView*)soEventSystem::getInstance()->getManager(
            *(s16*)((u8*)interpreter + 0x38));

    if (manager->has(kind) == 0)
        return 0;

    EventUnitView* unit = (EventUnitView*)__dynamic_cast(
        manager->get(kind), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);

    if (unit == 0)
        return 0;

    return unit->value();
}

struct InterpreterInit {
    acCmdInterpreter commandInterpreter;

    InterpreterInit(s32 eventId, soArrayVector<acCmdInterpreterStackData, 8>* stack,
                    const u8* reset, float time)
        : commandInterpreter(stack, 1, 0, reset, time) {
        acCmdInterpreter* interpreter = &commandInterpreter;
        int result = 0;
        *(u32*)((u8*)interpreter + 0x34) = (u32)lbl_27_data_466B8;
        *(s16*)((u8*)interpreter + 0x38) = eventId;
        *(s16*)((u8*)interpreter + 0x3a) = 5;
        *(s32*)((u8*)interpreter + 0x3c) = result;

        s32 checkedId = (s16)eventId;
        if (checkedId > 0 && checkedId > -1) {
            if (((EventSystemView*)soEventSystem::getInstance())->has(checkedId) != 0) {
                EventManagerView* manager =
                    (EventManagerView*)soEventSystem::getInstance()->getManager(
                        *(s16*)((u8*)interpreter + 0x38));

                if (manager->has(*(s16*)((u8*)interpreter + 0x3a)) == 0) {
                    *(s32*)((u8*)interpreter + 0x3c) = 0;
                } else {
                    s16 kind = *(s16*)((u8*)interpreter + 0x3a);
                    EventManagerView* manager2 =
                        (EventManagerView*)soEventSystem::getInstance()->getManager(
                            *(s16*)((u8*)interpreter + 0x38));
                    if (manager2->has(kind) == 0) {
                        result = 0;
                    } else {
                        EventUnitView* unit = (EventUnitView*)__dynamic_cast(
                            manager2->get(kind), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                        if (unit == 0) {
                            result = 0;
                        } else {
                            result = unit->value();
                        }
                    }
                    *(s32*)((u8*)interpreter + 0x3c) = result;
                }
            }
        }

        *(u32*)((u8*)interpreter + 0) = (u32)lbl_27_data_81A0;
        *(u32*)((u8*)interpreter + 0x34) =
            (u32)(lbl_27_data_81A0 + 0x20);
        *(u32*)((u8*)interpreter + 0x40) = 6;
        *(u32*)((u8*)interpreter + 0x44) = 0;
        *(u32*)((u8*)interpreter + 0x48) = 0;
        *(u32*)((u8*)interpreter + 0x4c) = 0;
    }
};

inline void initAddressPack(Self* self, StackInit* stackStorage) {
    self->fd0 = (u32)self;
    self->fc0 = (u32)lbl_27_data_46658;
    *(u32*)((u8*)stackStorage + 0xc0) = (u32)lbl_27_bss_D8C;
    *(u32*)((u8*)stackStorage + 0xc4) = (u32)lbl_27_bss_D8C;
}

extern "C" Self* fn_27_37EA94(
    Self* self, void* arg1, s32 mode, float time
) {
    self->f4 = 0;
    self->f0 = (u32)lbl_27_data_20878;
    self->f8 = mode;
    self->fc = 0x203;
    if (mode == 0)
        self->fc = 0;

    new (&self->stack) StackInit;

    self->fd0 = (u32)self;
    self->fc0 = (u32)lbl_27_data_46658;
    u8* interpreter;
    s32 result = 0;
    StackInit* stackStorage = &self->stack;
    u8* pack = (u8*)(stackStorage + 1);
    *(u32*)(pack + 0x14) = (u32)lbl_27_bss_D8C;
    *(u32*)(pack + 0x18) = (u32)lbl_27_bss_D8C;
    soArrayVector<acCmdInterpreterStackData, 8>* stack =
        (soArrayVector<acCmdInterpreterStackData, 8>*)stackStorage;
    u8 reset = result;
    void* initObj = *(void**)(*(u32*)((u8*)arg1 + 0xd8) + 0x80);
    s32 eventId = ((Object_vptr_0*)((u8*)initObj + 8))->slot7();
    interpreter = self->interpreter;
    new (interpreter) acCmdInterpreter(stack, 1, 0, &reset, time);
    *(u32*)(interpreter + 0x34) = (u32)lbl_27_data_466B8;
    *(s16*)(interpreter + 0x38) = eventId;
    *(s16*)(interpreter + 0x3a) = 5;
    *(s32*)(interpreter + 0x3c) = result;
    s32 checkedId = (s16)eventId;
    if (checkedId > 0 && checkedId > -1) {
        if (((EventSystemView*)soEventSystem::getInstance())->has(checkedId) != 0) {
            EventManagerView* manager = (EventManagerView*)soEventSystem::getInstance()->getManager(*(s16*)(interpreter + 0x38));
            if (manager->has(*(s16*)(interpreter + 0x3a)) == 0) {
                result = 0;
                *(s32*)(interpreter + 0x3c) = result;
            } else {
                s16 kind = *(s16*)(interpreter + 0x3a);
                EventManagerView* manager2 = (EventManagerView*)soEventSystem::getInstance()->getManager(*(s16*)(interpreter + 0x38));
                if (manager2->has(kind) == 0) {
                    result = 0;
                } else {
                    EventUnitView* unit = (EventUnitView*)__dynamic_cast(manager2->get(kind), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (unit == 0) {
                        result = 0;
                    } else {
                        result = unit->value();
                    }
                }
                *(s32*)(interpreter + 0x3c) = result;
            }
        }
    }
    *(u32*)interpreter = (u32)lbl_27_data_81A0;
    *(u32*)(interpreter + 0x34) = (u32)(lbl_27_data_81A0 + 0x20);
    *(u32*)(interpreter + 0x40) = 6;
    *(u32*)(interpreter + 0x44) = 0;
    *(u32*)(interpreter + 0x48) = 0;
    *(u32*)(interpreter + 0x4c) = 0;

    struct Count { s16 value; char padding[2]; } count;
    count.value = 0x80;
    void* range[2];
    range[0] = self->interpreter;
    range[1] = &self->fc0;

    void* module = *(void**)(*(u32*)((u8*)arg1 + 0xd8) + 0x6c);
    ((EventUnitView*)module)->v1(range, &count.value);

    return self;
}
