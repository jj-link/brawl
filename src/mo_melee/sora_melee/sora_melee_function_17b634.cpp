#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
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
    virtual void slot19(unsigned int, int);
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
    virtual int slot32(int);
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual int slot37(int);
};

class WorkMod {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(unsigned int);
    virtual void set(int, unsigned int);
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
    virtual void off(unsigned int);
};

class SoundMod {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void play(int, int, int, int);
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
    virtual void stop(int, int);
};

struct Modules {
    char pad0[0x50];
    SoundMod* sound;
    char pad1[0x10];
    WorkMod* work;
    char pad2[0x8];
    Object_vptr_0* status;
    char pad3[0x34];
    Object_vptr_0* a8;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
int fn_27_193590(Access*, int);
void fn_27_17B228(void*, Access*);
void fn_27_17DE50(Access*, int, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(Access*, unsigned long, unsigned long);

void fn_27_17B634(void* self, Access* acc) {
    if (fn_27_193590(acc, acc->modules->status->slot32(0)) == 0) {
        fn_27_17B228(self, acc);
        acc->modules->work->off(0x22000013);
        acc->modules->work->set(0, 0x2000000C);
        acc->modules->work->set(getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x5a60, 0), 0x2000000D);
        acc->modules->work->set(0, 0x2000000E);
        acc->modules->sound->play(0x1f91, 0, 0, 0);
    }
    int flag = acc->modules->a8->slot37(0);
    switch (acc->modules->work->get(0x2000000C)) {
    case 0:
        if (flag == 0) {
            fn_27_17DE50(acc, 0x16b, 0x16f);
        } else {
            fn_27_17DE50(acc, 0x163, 0x167);
        }
        break;
    case 1:
        if (flag == 0) {
            fn_27_17DE50(acc, 0x16c, 0x170);
        } else {
            fn_27_17DE50(acc, 0x164, 0x168);
        }
        break;
    case 2:
        if (flag == 0) {
            fn_27_17DE50(acc, 0x16b, 0x16f);
        } else {
            fn_27_17DE50(acc, 0x163, 0x167);
        }
        break;
    case 3:
        if (flag == 0) {
            fn_27_17DE50(acc, 0x16d, 0x171);
        } else {
            fn_27_17DE50(acc, 0x165, 0x169);
        }
        acc->modules->sound->stop(0x1f93, 0);
        break;
    case 4:
        if (flag == 0) {
            fn_27_17DE50(acc, 0x16e, 0x172);
        } else {
            fn_27_17DE50(acc, 0x166, 0x16a);
        }
        break;
    }
}
}
