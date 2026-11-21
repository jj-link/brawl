#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>

#pragma force_active on
#pragma opt_lifetimes off

struct SpeedPair {
    float x, y;
    SpeedPair(float b, float a) {
        x = a;
        y = b;
    }
};

struct Scalar {
    float value;
    float padding;
    Scalar(float v) : value(v) {}
};

struct Param {
    int kind;
    float a, b;
    char c, d, e, f;
};

struct Mask {
    int value;
    char flag;
};

#define METHODS \
    virtual void slot0(); \
    virtual void slot1(); \
    virtual void slot2(); \
    virtual void slot3(); \
    virtual void slot4(); \
    virtual void slot5(); \
    virtual void* slot6(int, int = 0); \
    virtual void slot7(int); \
    virtual void slot8(); \
    virtual void slot9(); \
    virtual void slot10(); \
    virtual void slot11(); \
    virtual void slot12(unsigned int); \
    virtual void slot13(void*, int); \
    virtual void slot14(); \
    virtual void slot15(); \
    virtual void slot16(int, Mask*, int); \
    virtual void slot17(); \
    virtual void slot18(); \
    virtual void slot19(int, int); \
    virtual void slot20(); \
    virtual void slot21(); \
    virtual void slot22(); \
    virtual void slot23(); \
    virtual void slot24(); \
    virtual void slot25(); \
    virtual void slot26(); \
    virtual void slot27(int, int); \
    virtual void slot28(); \
    virtual void slot29(); \
    virtual void slot30(Param*);

class Object_vptr_0 { public: METHODS };
struct Pad8 { int a, b; };
class Object_vptr_8 : public Pad8 { public: METHODS };
#undef METHODS

class Kinetic {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

struct Data {
    char pad0[8];
    Object_vptr_0* motion;
    Object_vptr_0* posture;
    Object_vptr_8* ground;
    Object_vptr_0* situation;
    char pad1[8];
    Object_vptr_0* kinetic2;
    char pad2[0x30];
    Object_vptr_0* hit;
    Object_vptr_0* area;
    char pad3[8];
    Object_vptr_0* work;
    char pad4[0x14];
    Kinetic* kinetic;
};

extern "C" {
extern char lbl_27_data_2E380[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_24D8;
extern const float lbl_27_rodata_24E4;
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_1885F0(void*, soModuleAccesser* acc, int status) {
    if (status == 14) {
        Kinetic* kinetic = ((Data*)acc->m_enumerationStart)->kinetic;
        char* a = (char*)__dynamic_cast(
            kinetic->slot6(2), 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
        char* b = (char*)__dynamic_cast(
            kinetic->slot6(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);

        ((Data*)acc->m_enumerationStart)->situation->slot6(2, 0);
        ((Data*)acc->m_enumerationStart)->ground->slot19(5, 0);

        Scalar x(soValueAccesser::getConstantFloat(acc, 0xD6F, 0));
        x.padding = soValueAccesser::getConstantFloat(acc, 0xD70, 0);
        float converted = static_cast<float>(x.padding);
        *(SpeedPair*)(a + 8) = SpeedPair((lbl_27_rodata_24E4), x.value);
        *(float*)(b + 12) = converted;
        b[5] |= 0x80;

        int n = soValueAccesser::getConstantInt(acc, 0x5A53, 0);
        ((Data*)acc->m_enumerationStart)->kinetic2->slot27(n, 0);
    }

    ((Data*)acc->m_enumerationStart)->work->slot12(0x21000007);
    ((Data*)acc->m_enumerationStart)->posture->slot23();

    Object_vptr_0* kinetic2 = ((Data*)acc->m_enumerationStart)->kinetic2;
    kinetic2->slot13(
        soValueAccesser::getConstantIndefinite(acc, 0xA803, 0), 0);

    ((Data*)acc->m_enumerationStart)->area->slot7(1);

    Mask m;
    m.value = 0x20;
    m.flag = 0;
    ((Data*)acc->m_enumerationStart)->hit->slot16(-1, &m, 0);

    if (status == 0xEF) {
        int kind;
        switch (randi(5)) {
        case 1: kind = 0xA5; break;
        case 2: kind = 0xA6; break;
        case 3: kind = 0xA7; break;
        case 4: kind = 0xA8; break;
        default: kind = 0xA4; break;
        }
        Param p;
        p.kind = kind;
        p.a = lbl_27_rodata_24E4;
        p.b = lbl_27_rodata_24D8;
        p.c = 0; p.d = 0; p.e = 0; p.f = 0;
        ((Data*)acc->m_enumerationStart)->motion->slot30(&p);
    }
}
