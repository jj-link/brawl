#pragma force_active on
extern "C" float lbl_41_rodata_DB8;

struct Accesser;
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int, Accesser*, float);
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600(int, int, Accesser*);
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
};
struct ModuleTable {
    char pad[0x6C];
    soAnimCmdEventObserver* anim;
};
struct Accesser {
    char pad[0xD8];
    ModuleTable* modules;
};
struct Command {
    char pad[0xC];
    int value;
};
extern "C" void fn_41_2A630(Command** self, Accesser* accesser, int kind) {
    soAnimCmdEventObserver* anim = accesser->modules->anim;
    int command = (*self)->value;
    if (command != 0) {
        anim->fn_41_13600(kind, command, accesser);
        anim->slot4(kind, accesser, lbl_41_rodata_DB8);
        anim->fn_41_13600(kind, 0, accesser);
    }
}
