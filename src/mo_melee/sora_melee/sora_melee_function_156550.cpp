#include <ft/ft_manager.h>
#include <so/controller/so_controller_module_impl.h>

#pragma force_active on

class Task : public gfTask {
public:
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
    virtual int slot40();
};

class Value {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
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
    virtual unsigned int slot17(int);
};

class State {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

class Controller {
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
    virtual float slot18();
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
    virtual int slot16();
};

struct OtherBase {
    char pad[8];
};

class Other : public OtherBase {
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
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual int slot71(int);
};

struct Modules {
    char pad[0x10];
    Other* other;
    State* state;
    char pad2[0x44];
    Controller* controller;
    char pad3[4];
    Value* value;
    char pad4[8];
    Status* status;
};

struct Object {
    char pad[8];
    Task* task;
    char pad2[0xcc];
    Modules* modules;
};

struct Conditions {
    char pad[12];
    int player;
    unsigned short flags;
};

extern float lbl_27_rodata_1F10;
extern "C" unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);

extern "C" int fn_27_156550(void*, Object* obj, const Conditions* cond) {
    int status = obj->modules->status->slot16();
    if (status != 0xbf) {
        bool ok;

        if (cond->player == -1)
            goto player_ok;

        {
            ftManager* manager = g_ftManager;
            if (cond->player != manager->getPlayerNo(
                    obj->modules->value->slot4(0x10000000))) {
                ok = false;
                goto done;
            }
        }

    player_ok:
        if (!(cond->flags & 8) && obj->task->slot40() == 15 &&
            obj->modules->value->slot17(0x1200002e) == 1) {
            ok = false;
        } else if ((cond->flags & 2) && obj->modules->state->slot3() != 0) {
            ok = false;
        } else if ((cond->flags & 1) &&
                   obj->modules->controller->slot18() < lbl_27_rodata_1F10) {
            ok = false;
        } else if (cond->flags & 4) {
            Controller* controller = obj->modules->controller;
            unsigned int mask = soController::getButtonMask(
                soController::Pad_Button_Attack);
            unsigned int buttons = controller->slot38();
            if (!(buttons & mask)) {
                ok = false;
                goto done;
            }
            goto success;
        } else {
        success:
            ok = true;
        }

    done:
        if (ok == 1 &&
            (*fn_27_14554C(&g_ftCommonDataAccesser, obj->task->slot40(),
                           status) & 1)) {
            return obj->modules->other->slot71(0) != 1;
        }
    }
    return 0;
}
