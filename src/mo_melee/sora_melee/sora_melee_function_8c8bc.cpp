#pragma force_active on

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
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
    virtual int fn_27_248088();
};

struct soModuleAccesser {
    char pad[8];
    gfTask* module;
};

struct Class_57290_base { char pad[4]; };
class Class_57290 : public Class_57290_base {
public:
    virtual void fn_27_26F548();
    virtual void fn_27_26F554();
    virtual void fn_27_8B658();
    virtual void fn_27_8BC8C();
    virtual void fn_27_8C024();
    virtual void fn_27_8C02C();
    virtual void fn_27_8C064();
    virtual void fn_27_8C078();
    virtual int fn_27_8C08C(soModuleAccesser*, unsigned long, int);
};

extern "C" Class_57290* lbl_27_bss_1B00[5];

extern "C" int fn_27_8C8BC(soModuleAccesser* module, unsigned long variable, int index)
{
    int kind = variable >> 28;
    int invalid = 0;
    if (kind > 0 && kind < 3)
        invalid = 1;
    if (invalid)
        return 0;
    return lbl_27_bss_1B00[module->module->fn_27_248088()]->fn_27_8C08C(module, variable, index);
}
