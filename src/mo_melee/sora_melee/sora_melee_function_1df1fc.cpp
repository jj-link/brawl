#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Out {
    int id; float x; float y; unsigned char flags[4];
    Out(int i, float a, float b) {
        id = i;
        flags[0] = 0; flags[1] = 0; flags[2] = 0; flags[3] = 0;
        x = a;
        y = b;
    }
};
struct Req { int a; unsigned char b; Vec3 pos; };

inline void setPos(Req& r, const Vec3& v) {
    ((int*)&r.pos)[0] = ((const int*)&v)[0];
    ((int*)&r.pos)[1] = ((const int*)&v)[1];
    ((int*)&r.pos)[2] = ((const int*)&v)[2];
}

class Obj {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int slot4(int);
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float slot12(int);
    virtual void slot13(); virtual void slot14();
    virtual void slot15(int, Req*);
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(const Out&, float, float);
    virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
    virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38();
    virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42();
    virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46();
    virtual void slot47(); virtual void slot48(); virtual void slot49(); virtual void slot50();
    virtual void slot51(); virtual void slot52(); virtual void slot53(); virtual void slot54();
    virtual void slot55(); virtual void slot56(); virtual void slot57(); virtual void slot58();
    virtual void slot59(); virtual void slot60(); virtual void slot61(); virtual void slot62();
    virtual void slot63(); virtual void slot64(); virtual void slot65(); virtual void slot66();
    virtual void slot67(); virtual void slot68(); virtual void slot69(); virtual void slot70();
    virtual void slot71(); virtual void slot72(); virtual void slot73(); virtual void slot74();
    virtual void slot75(); virtual void slot76(); virtual void slot77(); virtual void slot78();
    virtual void slot79(); virtual void slot80(); virtual void slot81(); virtual void slot82();
    virtual void slot83(); virtual void slot84(); virtual void slot85(); virtual void slot86();
    virtual void slot87(); virtual void slot88(); virtual void slot89(); virtual void slot90();
    virtual Vec3 slot91();
};

struct Holder { char pad0[8]; Obj* at8; char pad1[0x48]; Obj* at54; char pad2[0xc]; Obj* at64; };
struct Self { char pad[0xd8]; Holder* h; };

extern "C" {
extern float lbl_27_rodata_2B58;
void fn_27_1DF1FC(void* unused, Self* self) {
    Req req;
    Obj* ctrl = self->h->at54;
    Obj* obj = self->h->at64;
    req.a = 0x838;
    req.b = 0;
    setPos(req, Vec3(lbl_27_rodata_2B58, lbl_27_rodata_2B58, lbl_27_rodata_2B58));
    ctrl->slot15(3, &req);
    if (req.b != 0) {
        int id = obj->slot4(0x20000000);
        float f29 = obj->slot12(0x21000000);
        float f30 = obj->slot12(0x21000001);
        float f31 = obj->slot12(0x21000002);
        const Vec3& pos = ctrl->slot91();
        float d = nw4r::math::FAbs(pos.x - req.pos.x);
        if (d > f29) d = f29;
        float f1 = d / f31;
        float f2 = f30 * ((f29 - d) / f29);
        float y = (f30 - f2) / f1;
        self->h->at8->slot30(Out(id, f2, y), f1, f2);
    }
}
}
