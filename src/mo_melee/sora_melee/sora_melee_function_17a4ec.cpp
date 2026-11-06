#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_13690[];
extern "C" char lbl_27_data_CDF8[];

class Module {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
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
    virtual void slot17();
    virtual void slot18(unsigned int);
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
    virtual int slot32(int);
};

class CastTarget {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

struct Modules {
    char pad0[0x64];
    Module* m64;
    char pad68[8];
    Module* m70;
    char pad74[8];
    Module* m7C;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_17A4EC(void*, Object* obj) {
    if (obj->modules->m70->slot16() == 0x21) {
        switch (obj->modules->m70->slot32(0)) {
        case 0x49:
            obj->modules->m64->slot18(0x22000012);
            break;
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0xC0:
            obj->modules->m64->slot18(0x22000012);
            obj->modules->m64->slot18(0x22000013);
            break;
        }
    } else {
        CastTarget* p = (CastTarget*)__dynamic_cast(obj->modules->m7C->slot6(4), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
        p->slot6();
    }
}
