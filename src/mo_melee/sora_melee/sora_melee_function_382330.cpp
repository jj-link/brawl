#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <so/event/so_event_system.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct ArgData {
    s32 type;
    u32 value;
};

struct NullableArg {
    ArgData* data;
    u8 isNull;
};

struct EffectArg {
    s32 id;
    bool flag;
    Vec3f pos;
};

struct Bits {
    s32 x;
    s32 y;
    s32 z;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual u32 slot4(u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(u32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(s32, EffectArg*, s32);
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
    virtual s32 slot16();
};

struct Mid {
    char pad0[0x54];
    Object_vptr_0* effect;
    char pad58[0x0c];
    Object_vptr_0* work;
    char pad68[0x08];
    Status* status;
};

struct Obj {
    char pad0[0xd8];
    Mid* mid;
};

class Command {
public:
    virtual void slot0();
    virtual s8 slot1();
    virtual s8 slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual s32 slot6(NullableArg*, s32);
};

class Element {
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
    virtual void slot14(s32, s32);
    virtual void slot15(s32);
};

class List {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Element** slot2(s32);
    virtual void slot3();
    virtual s32 slot4();
};

class Unit {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual List* slot7();
};

class gfTask_base {
public:
    char pad[0x3c];
};

class Self : public gfTask_base {
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
    virtual s32 slot47(s8);

    char pad40[0x7fa4 - 0x40];
    s16 id1;
    s16 id2;
    List* cached;
};

extern "C" {
extern char lbl_27_bss_3188[];
extern char lbl_27_data_27038[];
extern char lbl_27_data_94D38[];
extern char __RTTI__6gfTask[];
extern char __RTTI__11soEventUnit[];
extern f32 lbl_27_rodata_7C14;

void* __dynamic_cast(void*, long, const void*, const void*, long);
s32 fn_27_133AA4(void*, void*, void*, s32);
void fn_27_383A44(void*, s32);
void fn_27_388930(void*, void*);
void fn_27_394E64(Vec3f*, void*, s32);
}

inline bool checkManageId(const Self* self, s32& id) {
    id = self->id1;
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline List* selectList(Self* self, s32& id) {
    soEventManager* mgr;
    List* cur;
    Unit* unit;
    int flag;

    if (self->id1 <= -1)
        return (List*)lbl_27_bss_3188;
    if (self->cached != 0)
        goto C;
    if (self->id1 <= -1 || !checkManageId(self, id)) {
        flag = 0;
        goto CHECK;
    }
    if (soEventSystem::getInstance()->getManager(self->id1)->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id = self->id2;
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(id) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->getEventUnit(id), 0,
                                     lbl_27_data_27038, __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->slot7();
    }
    self->cached = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (List*)lbl_27_bss_3188;

C:
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        return (List*)lbl_27_bss_3188;
    }
    return self->cached;
}

extern "C" s32 fn_27_382330(Self* self, Command* cmd, Obj* acc, s32 arg3) {
    EffectArg fallbackEffect;
    EffectArg effect2;
    EffectArg effect1;
    Vec3f fallback;
    Vec3f pos2;
    Vec3f pos1;
    NullableArg arg46;
    NullableArg arg47;
    s32 id;

    if (self->slot47(cmd->slot1()) == 0) {
        return 0;
    }

    switch (cmd->slot2()) {
    case 5:
        fn_27_383A44(self, 1);
        return 1;

    case 44:
        fn_27_388930((char*)self + 0x7fac, acc);
        return 1;

    case 45:
        if (acc->mid->status->slot16() == 0x116) {
            arg3 = (s32)acc->mid->work->slot4(0x10000043);
            gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
                (gfTask::Category)12, (u32)arg3);

            if (task != 0) {
                void* castTask = __dynamic_cast(
                    task, 0x3c, lbl_27_data_94D38, __RTTI__6gfTask, 1);

                fn_27_394E64(&pos1, castTask, 0);
                effect1.id = 0x839;
                effect1.flag = false;
                *(Bits*)&effect1.pos = *(Bits*)&pos1;
                acc->mid->effect->slot16(-1, &effect1, 0);

                fn_27_394E64(&pos2, castTask, 1);
                effect2.id = 0x839;
                effect2.flag = false;
                *(Bits*)&effect2.pos = *(Bits*)&pos2;
                acc->mid->effect->slot16(-1, &effect2, 0);
            }
        } else {
            float y = acc->mid->work->slot12(0x11000014);
            float x = acc->mid->work->slot12(0x11000013);

            fallback.m_x = x;
            fallback.m_y = y;
            fallback.m_z = lbl_27_rodata_7C14;

            fallbackEffect.id = 0x839;
            fallbackEffect.flag = false;
            *(Bits*)&fallbackEffect.pos = *(Bits*)&fallback;
            acc->mid->effect->slot16(-1, &fallbackEffect, 0);
        }
        return 1;

    case 46: {
        if (cmd->slot3() < 1) {
            return 1;
        }

        arg46.data = 0;
        arg46.isNull = 0;
        if (cmd->slot6(&arg46, 0) == 0) {
            return 1;
        }

        s32 value;
        if (arg46.isNull == 1) {
            value = 0;
        } else {
            value = arg46.data->value;
        }

        s32 i;
        List* list = selectList(self, id);

        for (i = 0; i < list->slot4(); ++i) {
            Element* element = *list->slot2(i);
            element->slot14(value, 0);
        }
        return 1;
    }

    case 47: {
        if (cmd->slot3() < 1) {
            return 1;
        }

        arg47.data = 0;
        arg47.isNull = 0;
        if (cmd->slot6(&arg47, 0) == 0) {
            return 1;
        }

        s32 value;
        if (arg47.isNull == 1) {
            value = 0;
        } else {
            value = arg47.data->value;
        }

        s32 i;
        List* list = selectList(self, id);

        for (i = 0; i < list->slot4(); ++i) {
            Element* element = *list->slot2(i);
            element->slot15(value);
        }
        return 1;
    }

    default:
        return fn_27_133AA4(self, cmd, acc, arg3);
    }
}
