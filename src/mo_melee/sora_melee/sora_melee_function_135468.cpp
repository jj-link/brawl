#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on
#pragma fp_contract off

extern const float lbl_27_rodata_1048;
extern "C" void fn_27_196384(soModuleAccesser*, float);

inline float addFloats(float a, float b) {
    return a + b;
}

#define U(n) virtual void slot##n();

class Object_vptr_0 {
public:
    U(0) U(1)
    virtual void slot2(void*, int, int, float);
    virtual int slot3();
    U(4)
    virtual void slot5(int, void*, void*, soModuleAccesser*);
    virtual Object_vptr_0* slot6(int);
    U(7) U(8)
    virtual float slot9();
    U(10) U(11) U(12)
    virtual void slot13(int, float);
    U(14) U(15)
    virtual void slot16(int, int);
    virtual int slot17(int);
    U(18) U(19) U(20) U(21) U(22) U(23) U(24) U(25)
    U(26) U(27) U(28) U(29) U(30) U(31) U(32) U(33)
    U(34) U(35) U(36) U(37) U(38) U(39) U(40) U(41)
    U(42) U(43) U(44) U(45) U(46) U(47) U(48) U(49)
    U(50) U(51) U(52) U(53) U(54) U(55) U(56) U(57)
    U(58) U(59)
    virtual void slot60(int, int);

    unsigned char data[2];
};

class ObjectStatus {
public:
    U(0) U(1) U(2)
    virtual void slot3(int, soModuleAccesser*);
};

class ObjectInt {
public:
    U(0) U(1) U(2) U(3) U(4) U(5) U(6) U(7) U(8)
    virtual int slot9();
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* pc;
    char pad10[4];
    Object_vptr_0* p14;
    char pad18[0x2c];
    Object_vptr_0* p44;
    Object_vptr_0* p48;
    char pad4c[0x10];
    Object_vptr_0* p5c;
    char pad60[4];
    Object_vptr_0* p64;
    char pad68[8];
    Object_vptr_0* p70;
    char pad74[8];
    Object_vptr_0* p7c;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    char pad0[0x60];
    Accesser* acc;
    char pad64[0xb0];
    float f114;
    int i118;
    char pad11c[0xc];
    float f128;
    float f12c;
    float f130;
    float f134;
    unsigned char flags;
};

extern "C" int fn_27_135468(Self* self, int flags) {
    if ((((unsigned int)self->flags >> 7) & 1U) == 1U) {
        Modules* mods = self->acc->modules;
        Object_vptr_0* obj = mods->p48;
        float value = mods->pc->slot9();

        obj->slot2(
            soValueAccesser::getConstantIndefinite(
                (soModuleAccesser*)self->acc, 0xa411, 0),
            1, 1, value);

        Object_vptr_0* other = self->acc->modules->p44;
        other->slot6(((ObjectInt*)obj)->slot9());

        Object_vptr_0* last = self->acc->modules->p5c;
        last->slot60(
            soValueAccesser::getConstantInt(
                (soModuleAccesser*)self->acc, 0x5a02, 0),
            1);
        return 0;
    }

    if (lbl_27_rodata_1048 != (float)self->i118) {
        self->acc->modules->p44->slot16(self->i118, 0);
    }

    if (self->f114 > lbl_27_rodata_1048) {
        fn_27_196384((soModuleAccesser*)self->acc, self->f114);
    }

    if ((flags & 1) && lbl_27_rodata_1048 != self->f128) {
        int frames = soValueAccesser::getConstantInt(
            (soModuleAccesser*)self->acc, 0x59de, 0);
        soModuleAccesser* acc = (soModuleAccesser*)self->acc;
        float add = soValueAccesser::getConstantFloat(acc, 0x7f7, 0);
        add = addFloats(
            self->f128 * soValueAccesser::getConstantFloat(acc, 0x7f6, 0),
            add);

        self->acc->modules->p64->slot13(0x21000001, add);
        self->acc->modules->p64->slot13(0x21000002, self->f12c);
        self->acc->modules->p64->slot13(0x21000003, (float)frames / add);
        ((ObjectStatus*)self->acc->modules->p70)->slot3(
            0x22, (soModuleAccesser*)self->acc);
        return 1;
    }

    if (self->acc->modules->p14->slot3() == 0 &&
        (flags & 4) &&
        lbl_27_rodata_1048 != self->f130 &&
        self->acc->modules->p64->slot17(0x12000002) == 0) {
        soModuleAccesser* acc;
        Object_vptr_0* obj = self->acc->modules->p7c->slot6(4);
        acc = (soModuleAccesser*)self->acc;

        float add = soValueAccesser::getConstantFloat(acc, 0xcb5, 0);
        float mul = soValueAccesser::getConstantFloat(acc, 0xcb4, 0);
        add = addFloats(self->f130 * mul, add);
        Vec2f speed(add, lbl_27_rodata_1048);
        speed.m_x *= -self->f134;

        soModuleAccesser* callAcc = (soModuleAccesser*)self->acc;
        Vec3f vec(
            lbl_27_rodata_1048,
            lbl_27_rodata_1048,
            lbl_27_rodata_1048);
        obj->slot5(0x15, &speed, &vec, callAcc);
        obj->data[1] |= 0x80;
    }

    return 0;
}
