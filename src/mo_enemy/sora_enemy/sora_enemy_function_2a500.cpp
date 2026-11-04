#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int, int, float);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7(int, int, int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(int);
    virtual void slot18();
    virtual void slot19(int);
    virtual void slot20();
    virtual void slot21();
};

struct Outer {
    char pad[0x64];
    soNullable* workobj;
    char pad2[4];
    soNullable* acc;
};

struct Arg1Struct {
    char pad[0xd8];
    Outer* outer;
};

extern float lbl_41_rodata_DB8;

extern "C" int fn_41_2A500(soNullable* arg0, Arg1Struct* arg1, int arg2, int arg3) {
    soNullable* acc = arg1->outer->acc;
    
    if (*(int*)(*(int*)arg0 + 8) == 0) {
        return 1;
    }
    
    arg1->outer->workobj->slot19(0x22000004);
    arg1->outer->workobj->slot5(arg3, 0x20000000);
    
    int func = *(int*)(*(int*)arg0 + 8);
    acc->slot7(arg2, func, (int)arg1);
    acc->slot4(arg2, (int)arg1, lbl_41_rodata_DB8);
    
    if (arg1->outer->workobj->slot17(0x22000004) == 1) {
        return 1;
    }
    
    acc->slot7(arg2, 0, (int)arg1);
    return 0;
}