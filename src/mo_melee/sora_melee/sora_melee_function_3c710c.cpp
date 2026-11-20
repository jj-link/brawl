#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Obj;

extern "C" {
extern const float lbl_27_rodata_8080[];
float fn_27_192278(void*, unsigned long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5(int, int, int, int);
    virtual void slot6(int, Vec3f*, Vec3f*, int, int, float, float, float, float, float);
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
    virtual void slot25(int, Obj*);
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
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual int slot40();
};

struct Object_vptr_8_base { char pad[8]; };
class Object_vptr_8 : public Object_vptr_8_base {
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
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99(float*, float*, float*, int);
};

struct P { float x; float y; };
inline P copyP(P p) { return p; }
class Class_1250 {
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
    virtual P slot13(short*);
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* p0c;
    Object_vptr_8* p10;
    char pad14[0x3c];
    Object_vptr_0* p50;
    char pad54[0x8];
    Object_vptr_0* p5c;
    Object_vptr_0* p60;
    char pad64[0x18];
    Class_1250* p7c;
    char pad80[0x8];
    Object_vptr_0* p88;
};

struct Obj {
    char pad0[8];
    Object_vptr_3c* q8;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" void fn_27_3C710C(Obj* self, const Vec2f* dir, float farg0) {
    const float* k = lbl_27_rodata_8080;
    float angle = (float)atan2(-dir->m_x, dir->m_y);
    Vec3f pos = self->modules->p0c->slot4();
    float a, b, c;
    self->modules->p10->slot99(&a, &b, &c, 0);
    if (k[2] == farg0) {
        pos.m_x += c;
    } else {
        pos.m_x -= c;
    }
    float absSum = nw4r::ut::Abs(a + b);
    float halfAbs = k[17] * absSum;
    pos.m_y += halfAbs;
    Vec3f v1;
    Vec3f v2(k[1], k[1], angle);
    v1.m_x = pos.m_x;
    v1.m_y = pos.m_y;
    v1.m_z = k[1];
    self->modules->p88->slot6(9, &v1, &v2, 0, -1, k[2], k[1], pos.m_y, halfAbs, absSum);
    self->modules->p60->slot25(1, self);
    self->modules->p5c->slot55(0xd, 0xa, 0, -1);
    short s = 1;
    P q = copyP(self->modules->p7c->slot13(&s));
    float f31 = fn_27_192278(self, 0xFBD);
    float d = fn_27_192278(self, 0xFB8) - f31;
    float factor = fn_27_192278(self, 0xFBF);
    float prod = factor * d;
    int state = self->q8->slot40();
    if (nw4r::ut::Abs(q.x) >= nw4r::ut::Abs(prod)) {
        if (state == 5) {
            self->modules->p50->slot5(0xc2a, 0, 0, 0);
        } else {
            self->modules->p50->slot5(0x17a3, 0, 0, 0);
        }
        return;
    }
    if (state == 5) {
        self->modules->p50->slot5(0xc29, 0, 0, 0);
    } else {
        self->modules->p50->slot5(0x17a2, 0, 0, 0);
    }
}
