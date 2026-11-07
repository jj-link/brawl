#pragma force_active on
#include <types.h>

struct Acc;
extern "C" float lbl_27_rodata_79D0;
extern "C" float lbl_27_rodata_79D4;

class Posture {
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
    virtual float slot9();
    virtual void slot10(float);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
};

struct GroundBase { char pad[8]; };
class Ground : public GroundBase {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54();
    virtual int test(int, int);
};
struct Mod { char pad[0xC]; Posture* posture; Ground* ground; };
struct Acc { char pad[0xD8]; Mod* mod; };
union VectorResult {
    unsigned long long bits;
    struct { float x; float y; } vector;
};
struct Vector {
    float x; float y;
    Vector() {}
    Vector(float x_) : x(x_), y(lbl_27_rodata_79D0) {}
};
class Self {
public:
    virtual void v0();
    virtual void v1(Acc*);
    virtual unsigned long long v2();
    unsigned char unk4;
    unsigned char f5a : 1;
    unsigned char f5b : 7;
    unsigned char f6;
    unsigned char unk7;
    float x;
    float y;
    void setVector(const Vector& v) { y = v.y; x = v.x; }
};
inline float reflectedSpeed(Self* self) {
    VectorResult result;
    result.bits = self->v2();
    return lbl_27_rodata_79D4 * result.vector.x;
}
extern "C" void fn_27_359AE8(Self* self, u32 unused, Acc* acc) {
    int flag = true;
    VectorResult result3;
    Vector vector;
    VectorResult result2;
    VectorResult result;
    {
        bool contact = false;
        result.bits = self->v2();
        if (result.vector.x >= lbl_27_rodata_79D0) {
            Ground* ground = acc->mod->ground;
            if (ground->test(4, 0) != 0) contact = true;
        }
        if (!contact) {
            bool contact2 = false;
            result2.bits = self->v2();
            if (result2.vector.x <= lbl_27_rodata_79D0) {
                Ground* ground = acc->mod->ground;
                if (ground->test(2, 0) != 0) contact2 = true;
            }
            if (!contact2) flag = false;
        }
    }
    if (flag) {
        result3.bits = self->v2();
        vector.x = lbl_27_rodata_79D4 * result3.vector.x;
        vector.y = lbl_27_rodata_79D0;
        self->setVector(vector);
        Posture* posture = acc->mod->posture;
        posture->slot10(lbl_27_rodata_79D4 * posture->slot9());
        acc->mod->posture->slot19();
    }
    if ((u32)(!!self->f5a) == 1 && self->f6 == 0) self->v1(acc);
}