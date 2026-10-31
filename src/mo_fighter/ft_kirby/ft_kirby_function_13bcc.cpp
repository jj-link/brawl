#pragma force_active on
struct Module {
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
    virtual void call(int, bool, bool);
};
struct Modules {
    char padding[0x88];
    Module* module;
};
struct Fighter {
    char padding[0xD8];
    Modules* modules;
};
extern "C" void fn_96_13BCC(void*, Fighter* fighter, int state)
{
    switch (state) {
    case 0x12A:
    case 0x12B:
        break;
    default:
        fighter->modules->module->call(2, true, true);
        break;
    }
}
