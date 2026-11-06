#include <so/so_value_accesser.h>
#pragma force_active on
#pragma opt_lifetimes off

#define OBJECT_METHODS \
    virtual void slot0(); \
    virtual void slot1(); \
    virtual void slot2(); \
    virtual int slot3(); \
    virtual void slot4(); \
    virtual int slot5(); \
    virtual void* slot6(int); \
    virtual void slot7(); \
    virtual void slot8(); \
    virtual void slot9(); \
    virtual void slot10(); \
    virtual void slot11(); \
    virtual float slot12(int); \
    virtual void slot13(float, int); \
    virtual void slot14(); \
    virtual void slot15(); \
    virtual void slot16(); \
    virtual int slot17(int); \
    virtual void slot18(int); \
    virtual void slot19(int, int); \
    virtual void slot20(); \
    virtual void slot21(int, soModuleAccesser*); \
    virtual void slot22(); \
    virtual void slot23(float);

class Object_vptr_0 {
public:
    OBJECT_METHODS
};

struct Pad8 {
    int a, b;
};

class Object_vptr_8 : public Pad8 {
public:
    OBJECT_METHODS
};

#undef OBJECT_METHODS

struct Data {
    char pad0[0xC];
    Object_vptr_0* posture;
    Object_vptr_8* ground;
    Object_vptr_0* situation;
    char pad1[0x4C];
    Object_vptr_0* work;
    char pad2[0x14];
    Object_vptr_0* kinetic;
};

extern "C" {
extern char lbl_27_data_2E380[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_24D8;
extern const float lbl_27_rodata_24E4;

void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_188340(void*, soModuleAccesser* acc) {
    const Data* data = reinterpret_cast<const Data*>(acc->m_enumerationStart);
    Object_vptr_0* situation = data->situation;
    Object_vptr_0* work = data->work;
    Object_vptr_0* posture = data->posture;
    Object_vptr_8* ground = data->ground;
    Object_vptr_0* kinetic = data->kinetic;

    if (situation->slot5() != 0) {
        if (situation->slot3() == 0) {
            ground->slot19(1, 0);
            kinetic->slot21(6, acc);
        } else {
            ground->slot19(5, 0);
            kinetic->slot21(0, acc);
            float value = work->slot12(0x21000004);
            void* energy = kinetic->slot6(2);
            void* result = __dynamic_cast(
                energy, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
            *reinterpret_cast<float*>(static_cast<char*>(result) + 0x3C) = value;
        }
    }

    if (work->slot17(0x22000010) == 0) {
        float remaining = work->slot12(0x21000006);
        if (remaining <= lbl_27_rodata_24E4) {
            work->slot18(0x22000010);
        } else {
            remaining -= lbl_27_rodata_24D8;
            float maximum = soValueAccesser::getConstantFloat(acc, 0xD69, 0);
            float factor = soValueAccesser::getConstantFloat(acc, 0xD68, 0);
            float rate = (maximum - remaining) / maximum;
            rate *= factor;
            float speed = work->slot12(0x21000007);
            factor = lbl_27_rodata_24D8 - factor;
            rate = factor + rate;
            rate *= speed * soValueAccesser::getConstantFloat(acc, 0xC18, 0);
            posture->slot23(rate);
            work->slot13(remaining, 0x21000006);
        }
    }
}
