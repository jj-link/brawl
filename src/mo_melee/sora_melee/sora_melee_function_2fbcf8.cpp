#include <types.h>
#include <ft/ft_common_data_accesser.h>

#pragma force_active on

extern "C" {
int* fn_27_1492A4(void*, int);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_2FFA14(void*, float);

extern char lbl_27_data_80608[];
extern char lbl_27_data_C938[];
extern double lbl_27_rodata_6528;
}

struct KindAccessorBase {
    char pad[0x3C];
};

class KindAccessor : public KindAccessorBase {
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
    virtual void slot39();
    virtual int getKind();
};

class Module14 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*);
};

class Module84 {
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
    virtual int slot24(int);
};

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
};

struct Modules {
    char pad0[0x14];
    Module14* module14;
    char pad18[0x64 - 0x18];
    WorkModule* work;
    char pad68[0x84 - 0x68];
    Module84* module84;
};

struct Fighter {
    char pad0[0x08];
    KindAccessor* kindAccessor;
    char pad0C[0xD8 - 0x0C];
    Modules* modules;
};

extern "C" void fn_27_2FBCF8(void* unused, void* arg) {
    Fighter* fighter = (Fighter*)arg;
    int kind = fighter->kindAccessor->getKind();
    int* common = fn_27_1492A4(&g_ftCommonDataAccesser, kind);

    fighter->modules->module14->slot3(fighter->modules);

    int value;
    if (kind == 5) {
        value = 13;
    } else {
        value = *(int*)((char*)getData__20ftCommonDataAccesserCF6ftKind(
                            &g_ftCommonDataAccesser, 3) +
                        0x98);
    }

    void* object = (void*)fighter->modules->module84->slot24(value);
    if (object != 0) {
        void* casted = __dynamic_cast(
            object, 0, lbl_27_data_80608, lbl_27_data_C938, 0);
        int workValue = fighter->modules->work->slot4(0x10000041);
        float ratio = (float)workValue / (float)*common;
        fn_27_2FFA14(casted, ratio);
    }
}
