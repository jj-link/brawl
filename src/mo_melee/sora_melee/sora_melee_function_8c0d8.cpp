#pragma force_active on
class ModuleInfo {
public:
    unsigned char padding[0x3C];

    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual unsigned long getKind();
};

struct soModuleAccesser {
    unsigned char padding[8];
    ModuleInfo* info;
};

class ValueAccesser {
public:
    unsigned long padding;

    virtual void slot00();
    virtual void slot01();
    virtual float getVariableFloat(
        soModuleAccesser*, unsigned long, unsigned long);
};

extern "C" {
extern ValueAccesser* lbl_27_bss_1B00[5];

float getVariableFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser* module, unsigned long variable, unsigned long index)
{
    ValueAccesser* accesser =
        lbl_27_bss_1B00[module->info->getKind()];

    return accesser->getVariableFloat(module, variable, index);
}
}
