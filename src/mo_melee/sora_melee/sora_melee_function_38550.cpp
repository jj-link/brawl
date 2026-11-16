#include <types.h>
#pragma force_active on

class soCollision {
public:
    enum Category { CategoryDefault };
};

extern "C" {
extern const float lbl_27_rodata_490;
extern const float lbl_27_rodata_494;
extern char lbl_27_data_3418[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

class soVirtObj {
public:
    virtual void f0();
    virtual void* get(int);
};

class soCollisionAttackPart {
public:
    soCollisionAttackPart(soCollision::Category, bool);

    u32 status;
    char pad04[0x10];
    float unk14;
    char pad18[0x10];
    float x, y, z;
    char pad34[8];
    u32 unused3c : 27;
    u32 flags3c : 5;
    u32 pad40;
    void* vt44;
    void* vt48;
    u32 fieldA : 8;
    u32 fieldB : 4;
    u32 fieldC : 1;
    u32 fieldD : 19;
    char targets[0x38];
};

soCollisionAttackPart::soCollisionAttackPart(soCollision::Category cat, bool b) {
    status = 0;
    x = lbl_27_rodata_490;
    y = lbl_27_rodata_490;
    z = lbl_27_rodata_490;
    flags3c = 0;
    vt44 = lbl_27_data_3418;
    vt48 = lbl_27_data_3418 + 0x48;
    fieldA = 0;
    fieldB = 6 + (b == 1);
    fieldC = 0;
    __construct_array(targets, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 7);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&vt48, 6L + (b == 1), 7L);
    u32* target;
    target = (u32*)((soVirtObj*)&vt44)->get(0);
    *target = 1;
    target = (u32*)((soVirtObj*)&vt44)->get(1);
    *target = 1u << cat;
    target = (u32*)((soVirtObj*)&vt44)->get(2);
    *target = 0;
    unk14 = lbl_27_rodata_494;
    if (b == 1) {
        target = (u32*)((soVirtObj*)&vt44)->get(6);
        target[1] = 1;
    }
}
