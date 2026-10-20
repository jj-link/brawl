#pragma force_active on
struct SleepCommand {
    int kind;
    int value;
};

struct ModuleData {
    unsigned char padding[0x3c];
};

struct Module : ModuleData {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void send(const SleepCommand*, int);
};

struct grGimmickLadder {
    unsigned char padding[0x14c];
    Module* module;
};

extern "C" bool setSleepArea__10grYakumonoFb(grGimmickLadder*, bool);

extern "C" bool setSleepArea__15grGimmickLadderFb(
    grGimmickLadder* self, bool sleep)
{
    bool result = setSleepArea__10grYakumonoFb(self, sleep);
    if (sleep == true) {
        SleepCommand command;
        command.kind = 0x34;
        command.value = 0;
        self->module->send(&command, -1);
    }
    return result;
}
