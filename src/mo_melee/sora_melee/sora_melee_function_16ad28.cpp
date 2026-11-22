#pragma force_active on
#include <so/so_value_accesser.h>

class Vt {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
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
    virtual int slot16();
    virtual unsigned int slot17(unsigned int);
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
};

struct KineticBase {
    char pad[8];
};

class Kinetic : public KineticBase {
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
    virtual void* slot32();
};

struct Mods {
    char pad0[0x38];
    Kinetic* p38;
    char pad1[0x64 - 0x3C];
    Vt* p64;
    char pad2[0x70 - 0x68];
    Vt* p70;
};

extern "C" const float lbl_27_rodata_2150;

static inline Mods* getMods(soModuleAccesser* acc) {
    return *(Mods**)((char*)acc + 0xd8);
}

extern "C" void fn_27_16AD28(void* self, soModuleAccesser* acc) {
    float f2;
    Kinetic* P = getMods(acc)->p38;
    void* obj = P->slot32();
    int r29 = getMods(acc)->p70->slot16();

    if (getMods(acc)->p64->slot17(0x22000012) == 1) {
        float f = soValueAccesser::getConstantFloat(acc, 0xBCE, 0);
        getMods(acc)->p64->slot5((int)f, 0x10000039);
    }

    if (r29 != 0x47 && r29 != 0x48) {
        if (*(float*)((char*)obj + 0x1c) > lbl_27_rodata_2150) {
            getMods(acc)->p64->slot19(0x22000011);
            getMods(acc)->p64->slot5((int)*(float*)((char*)obj + 0x1c), 0x10000038);
        } else {
            getMods(acc)->p64->slot18(0x22000011);
            getMods(acc)->p64->slot5(0, 0x10000038);
        }
    }

    int v0 = soValueAccesser::getConstantInt(acc, 0x5A0A, 0);
    getMods(acc)->p64->slot5(v0, 0x10000002);

    float f1 = soValueAccesser::getConstantFloat(acc, 0xC8F, 0);
    float f0 = *(float*)((char*)obj + 0xc);
    f2 = *(float*)((char*)obj + 0x10);
    float f3 = f1 * f1;
    f1 = f2 * f2;
    f0 = f0 * f0;
    f0 = f0 + f1;
    if (f0 > f3) {
        getMods(acc)->p64->slot18(0x1200001B);
        int v1 = soValueAccesser::getConstantInt(acc, 0x5A15, 0);
        getMods(acc)->p64->slot5(v1, 0x10000020);
    }

    int v2 = soValueAccesser::getConstantInt(acc, 0x5A30, 0);
    getMods(acc)->p64->slot5(v2, 0x20000006);
    int v3 = soValueAccesser::getConstantInt(acc, 0x5A31, 0);
    getMods(acc)->p64->slot5(v3, 0x20000007);
}