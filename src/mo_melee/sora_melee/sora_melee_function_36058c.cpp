#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma fp_contract off

struct Vec3 {
    float x, y, z;
};

struct LocalValues {
    float pad[2];
    float xy[2];
};

struct Obj64 {
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
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, float);
};

struct Obj5C {
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
    virtual float slot16();
    virtual void slot17();
    virtual float slot18();
    virtual void slot19();
    virtual void slot20();
};

struct Obj0C {
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
    virtual void slot15(const Vec3*, int);
};

struct Obj7C {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

struct Modules {
    char pad0[0x0C];
    Obj0C* p0C;
    char pad10[0x4C];
    Obj5C* p5C;
    char pad60[4];
    Obj64* p64;
    char pad68[0x14];
    Obj7C* p7C;
};

struct Self {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
float rsqrtf__Ff(float);
double atan2(double, double);
double sin(double);
double cos(double);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const float lbl_27_rodata_7A40[];
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];

void fn_27_36058C(void*, Self* self) {
    const float* constants = lbl_27_rodata_7A40;
    float angle = self->modules->p64->slot12(0x11000002);

    Vec3 value;
    LocalValues values;
    float y = self->modules->p5C->slot18();
    float x = self->modules->p5C->slot16();
    values.xy[0] = x;
    values.xy[1] = y;

    float lengthSquared =
        values.xy[0] * values.xy[0] + values.xy[1] * values.xy[1];
    float length;
    float absLength = (float)fabs((double)lengthSquared);
    if (absLength <= constants[2]) {
        length = constants[1];
    } else {
        length = lengthSquared * rsqrtf__Ff(lengthSquared);
    }

    if (length > constants[3]) {
        float argX = values.xy[0];
        float argY = values.xy[1];
        lengthSquared = angle - constants[4] * (float)atan2(argY, argX);

        while (lengthSquared > constants[6]) {
            lengthSquared -= constants[5];
        }
        while (lengthSquared < constants[7]) {
            lengthSquared += constants[5];
        }

        float adjustment =
            length * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                         self, 0xFA4, 0);

        if (lengthSquared >= constants[8]) {
            if (lengthSquared <= constants[9]) {
                angle -= adjustment;
            }
        } else if (lengthSquared <= constants[10] &&
                   lengthSquared >= constants[11]) {
            angle += adjustment;
        }
    }

    value.x = -angle;
    value.y = constants[12];
    value.z = constants[1];
    self->modules->p0C->slot15(&value, 0);

    void* result = __dynamic_cast(
        self->modules->p7C->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    float scale = constants[0] * angle;
    float magnitude = self->modules->p64->slot12(0x11000001);
    float vertical = magnitude * (float)sin(scale);
    float cosine = (float)cos(scale);
    values.pad[1] = vertical;
    float horizontal = magnitude * cosine;
    values.pad[0] = horizontal;

    *(float*)((char*)result + 8) = values.pad[0];
    *(float*)((char*)result + 0xC) = values.pad[1];

    self->modules->p64->slot13(0x11000002, angle);
}
}
