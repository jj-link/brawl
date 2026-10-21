#pragma force_active on

struct EffectModule {
    virtual void entry8();
    virtual void entryc();
    virtual void entry10();
    virtual void entry14();
    virtual void entry18();
    virtual void entry1c();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2c();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3c();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual void entry4c();
    virtual void entry50();
    virtual void entry54();
    virtual void entry58();
    virtual void entry5c();
    virtual void entry60();
    virtual void entry64();
    virtual void entry68();
    virtual void entry6c();
    virtual void entry70();
    virtual void entry74();
    virtual void entry78();
    virtual void entry7c();
    virtual void entry80();
    virtual void entry84();
    virtual void entry88();
    virtual void entry8c();
    virtual void entry90();
    virtual void entry94();
    virtual void entry98();
    virtual void entry9c();
    virtual void entrya0();
    virtual void entrya4();
    virtual void entrya8();
    virtual void entryac();
    virtual void entryb0();
    virtual void entryb4();
    virtual void entryb8();
    virtual void entrybc();
    virtual void entryc0();
    virtual void entryc4();
    virtual void entryc8();
    virtual void entrycc();
    virtual void entryd0();
    virtual void entryd4();
    virtual void entryd8();
    virtual void entrydc();
    virtual void entrye0();
    virtual void entrye4();
    virtual void notify(int, int);
};

struct WorkModule {
    virtual void entry8();
    virtual void entryc();
    virtual void entry10();
    virtual void entry14();
    virtual int getInt(unsigned int);
    virtual void entry1c();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2c();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3c();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual int isFlag(unsigned int);
    virtual void entry50();
    virtual void offFlag(unsigned int);
};

struct SoundModule {
    virtual void entry8();
    virtual void entryc();
    virtual void entry10();
    virtual void entry14();
    virtual void entry18();
    virtual void entry1c();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2c();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3c();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual void entry4c();
    virtual void entry50();
    virtual void entry54();
    virtual void stopSE(int, int);
};

struct Modules {
    char pad0[0x50];
    SoundModule* sound;
    char pad1[8];
    EffectModule* effect;
    char pad2[4];
    WorkModule* work;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_120_E4C4(void*, Fighter* fighter, int status) {
    switch (status) {
    case 0x119:
    case 0x11a:
        break;
    default:
        fighter->modules->effect->notify(2, 7);
        fighter->modules->effect->notify(8, 7);
        break;
    }

    if (fighter->modules->work->isFlag(0x22000016)) {
        int handle = fighter->modules->work->getInt(0x20000003);
        if (handle >= 0) {
            fighter->modules->sound->stopSE(handle, 0);
        }
        fighter->modules->work->offFlag(0x22000016);
    }
}
