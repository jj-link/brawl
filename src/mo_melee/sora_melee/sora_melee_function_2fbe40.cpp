#include <ft/ft_common_data_accesser.h>

#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern float lbl_27_rodata_6520;
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
int fn_27_1922CC(void*, unsigned long);
}

struct CharacterBase {
    char pad[0x3c];
};

struct Character : CharacterBase {
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
    virtual int getStatus();
};

struct ParameterModule {
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
    virtual void setParameter(int, int);
};

struct TimerModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getValue(unsigned long);
    virtual void query(int, unsigned long);
};

struct StateModule {
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
    virtual void setStateTimed(int, float);
    virtual void setState(int);
};

struct Modules {
    char pad0[0x64];
    TimerModule* timer;
    char pad1[0x1c];
    ParameterModule* parameter;
    StateModule* state;
};

struct Accesser {
    char pad0[0x8];
    Character* character;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" void fn_27_2FBE40(void*, Accesser* accesser, int status) {
    int result = fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1);

    switch (result) {
    case 0x119:
    case 0x1a:
    case 0x1e:
    case 0x1f:
    case 0x20: {
        int value;
        if (accesser->character->getStatus() == 5) {
            value = 0xd;
        } else {
            value = *(int*)((char*)g_ftCommonDataAccesser.getData((ftKind)3) + 0x98);
        }

        accesser->modules->parameter->setParameter(value, 0);

        TimerModule* timerModule = accesser->modules->timer;
        int timer = fn_27_1922CC(accesser, 0x5dc0);
        if (timerModule->getValue(0x10000041) >= timer) {
            accesser->modules->state->setStateTimed(0x1a, lbl_27_rodata_6520);
        }
        break;
    }

    case 0x11a:
    case 0x11c:
        break;

    default:
        accesser->modules->timer->query(0, 0x10000041);

        int value;
        if (accesser->character->getStatus() == 5) {
            value = 0xd;
        } else {
            value = *(int*)((char*)g_ftCommonDataAccesser.getData((ftKind)3) + 0x98);
        }

        accesser->modules->parameter->setParameter(value, 0);
        accesser->modules->state->setState(0x1a);
        break;
    }
}
