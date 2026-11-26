#include <nw4r/math.h>
#include <mt/mt_common.h>

#pragma force_active on
#pragma fp_contract off

class Owner;
class Modules;

class Class_90D8_base {
public:
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual float fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual float fn_27_7ADE8();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual float slot7(int*);
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
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
};

class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual void fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
    virtual void fn_27_39EF4();
    virtual void fn_27_3A0C4();
    virtual void fn_27_3A270();
    virtual void fn_27_3AF7C();
    virtual void fn_27_3B070();
    virtual void fn_27_3B120();
    virtual void fn_27_3A3C8();
    virtual void fn_27_3A430();
    virtual void fn_27_3A4BC();
    virtual void fn_27_3A504();
    virtual void fn_27_3A600();
    virtual void fn_27_3A664();
    virtual void fn_27_3A6A4();
    virtual void fn_27_3A6D8();
    virtual void fn_27_3A718();
    virtual void fn_27_3AD40();
    virtual void fn_27_3ADDC();
    virtual void fn_27_3AF34();
    virtual void fn_27_3A75C();
    virtual void fn_27_3A920();
    virtual void fn_27_3A960();
    virtual void fn_27_3A994();
    virtual void fn_27_3A9EC();
    virtual void fn_27_3AA50();
    virtual void fn_27_3AAA8();
    virtual void fn_27_3AB0C();
    virtual void fn_27_3AB64();
    virtual void fn_27_3ABC8();
    virtual void fn_27_3A54C();
    virtual void fn_27_3A5A4();
    virtual void fn_27_3BCC4();
    virtual void fn_27_3AC30();
    virtual void fn_27_41464();
    virtual void fn_27_41454();
    virtual void fn_27_41434();
    virtual int* fn_27_3ACEC();

    unsigned char pad_04[0x24];
    Owner* owner;
    unsigned char pad_2C[0x14];
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
};

class Modules {
public:
    unsigned char pad0[0xB4];
    Class_90D8* unkB4;
    unsigned char pad1[0x4];
    Class_90D8* unkBC;
    unsigned char pad2[0x4];
    Object_vptr_0* unkC4;
};

class Owner {
public:
    unsigned char pad[0xD8];
    Modules* modules;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
extern void* lbl_27_bss_B8;
extern float lbl_27_data_4B84;
}

extern "C" float fn_27_3A75C(soCollisionAttackModuleImpl* self) {
    float f31;
    float f3;
    f3 = 1.0f;
    int* p = self->fn_27_3ACEC();
    float f30 = self->unk4C +
        self->unk48 * (self->unk58 * ((float)*p * self->unk54));

    if (0.0f != self->unk50) {
        f31 = self->unk40 * self->unk40 + self->unk44 * self->unk44;
        f3 = ((float)(double)nw4r::math::FAbs(f31) <=
              1.1754943508222875e-38f)
            ? 0.0f
            : f31 * rsqrtf(f31);
        f30 += self->unk50 * f3;
    }

    f30 *= self->owner->modules->unkB4->fn_27_7AD2C();
    f30 *= self->owner->modules->unkC4->slot7(p);
    float f1 = self->owner->modules->unkBC->fn_27_7ADE8();

    if (1.0f != f1) {
        f30 *= f1;
        if (lbl_27_bss_B8 == 0) {
            void* obj = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
            if (obj != 0) {
                obj = fn_27_4FAB4(obj);
            }
            lbl_27_bss_B8 = obj;
        }
        if (f30 > lbl_27_data_4B84) {
            f30 = lbl_27_data_4B84;
        }
    }

    return f30;
}
