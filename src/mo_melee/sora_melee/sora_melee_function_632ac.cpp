#pragma force_active on

extern "C" float lbl_27_rodata_8D8;
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* self, unsigned long id, unsigned long index);

class soNullable {
public:
    virtual bool isNull();                       // offset 0x8
    virtual void slot1();                        // offset 0xc
    virtual void slot2();                        // offset 0x10
    virtual int slot3(void* moduleAccesser);     // offset 0x14
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
    virtual void slot15(void* moduleAccesser, bool flag); // offset 0x44
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
    virtual soNullable* slot39();                // offset 0xa4
};

class soNullPad {
public:
    int m_pad0;
    int m_pad1;
};

// Damage-module-like object: its own vtable pointer sits at offset 0x8.
class soDamageModuleLayout : public soNullPad {
public:
    virtual bool isNull();
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
    virtual soNullable* slot39();
};

struct soModuleEnumeration {
    char pad0[0x38];
    soDamageModuleLayout* damage;
};

struct soModuleAccesser {
    char pad0[0xD8];
    const soModuleEnumeration* enumStart;
};

extern "C" int fn_27_632AC(void* self, soModuleAccesser* mod, float farg0, float farg1)
{
    soNullable* eff = mod->enumStart->damage->slot39();
    int r = eff->slot3(mod);
    int result = 0;
    switch (r) {
    case 1:
    case 2:
    case 3:
        if (farg0 >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0x7e9, 0)) {
            if (farg0 >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0x7ea, 0)) {
                if (farg1 < lbl_27_rodata_8D8 * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0x7eb, 0)) {
                    eff->slot15(mod, true);
                    result = 3;
                }
            } else {
                eff->slot15(mod, false);
                result = 3;
            }
        }
        break;
    default:
        break;
    }
    return result;
}
