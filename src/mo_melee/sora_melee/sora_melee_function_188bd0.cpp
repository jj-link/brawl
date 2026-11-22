#pragma force_active on
#include <mt/mt_vector.h>

extern "C" int randi__Fl(long);
extern "C" const float lbl_27_rodata_24F0;
extern "C" const int lbl_27_rodata_24F8[];

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Param {
    int a;
    float b;
    float c;
    char d;
    char e;
    char f;
    char g;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned int);
    virtual void slot6(int);
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
    virtual void slot18(unsigned int);
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
    virtual void slot30(void*);
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
    virtual void slot75(int, int, int, int, int);
};

struct Obj8_base {
    char pad[8];
};

class Obj8 : public Obj8_base {
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
    virtual int slot33(int);
    virtual void slot34();
    virtual void slot35();
    virtual Vec3f slot36(int, int);
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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

struct Ctx {
    char pad0[8];
    int kind;
    int param;
    Vec3f pos;
};

struct Modules {
    char pad0[4];
    Obj8* m4;
    Object_vptr_0* m8;
    char pad1[0x38];
    Object_vptr_0* m44;
    char pad2[0xc];
    Object_vptr_0* m54;
    char pad3[0xc];
    Object_vptr_0* m64;
};

struct Object {
    char pad0[8];
    Object_vptr_3c* at8;
    char pad1[0xcc];
    Modules* modules;
};

inline Vec3f getPosition(Obj8* o, int param) {
    int v = o->slot33(param);
    return o->slot36(v, 0);
}

extern "C" void fn_27_188BD0(Ctx* ctx, Object* obj) {
    Modules* mods = obj->modules;
    int kind = ctx->kind;
    Object_vptr_0* r31 = mods->m64;
    r31->slot5(kind, 0x20000000);
    switch (ctx->kind) {
    case 1:
        obj->modules->m44->slot6(ctx->param);
        return;
    case 2: {
        Object_vptr_0* m = obj->modules->m8;
        Param p;
        p.a = 0x9c;
        p.b = lbl_27_rodata_24F0;
        p.c = lbl_27_rodata_24F0;
        p.d = 0;
        p.e = 0;
        p.f = 0;
        p.g = 0;
        m->slot30(&p);
        return;
    }
    case 3: {
        int idx = randi__Fl(8);
        r31->slot5(lbl_27_rodata_24F8[idx], 0x20000001);
        int v;
        if (obj->at8->slot40() == 0x2f) {
            v = obj->modules->m4->slot33(0x12e);
        } else {
            v = obj->modules->m4->slot33(0x12d);
        }
        obj->modules->m54->slot75(0, v, ctx->param, 3, 1);
        r31->slot18(0x22000010);
        return;
    }
    case 6:
        r31->slot18(0x22000012);
        return;
    case 7: {
        Vec3f t;
        t = getPosition(obj->modules->m4, ctx->param);
        ctx->pos = t;
        return;
    }
    case 5:
        r31->slot18(0x12000032);
        return;
    default:
        return;
    }
}
