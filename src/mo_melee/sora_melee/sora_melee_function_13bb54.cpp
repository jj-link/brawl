#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*);
    virtual Vec3 slot4();
    virtual void slot5(Vec3*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int, void*);
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
    virtual void slot55(int, int, int, int);
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
    virtual void slot86(int, Vec3*, Vec3*);
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

struct Sub {
    char p0[0x0c];
    Object_vptr_0* r0c;
    char p1[0x54 - 0x10];
    Object_vptr_0* q54;
    char p2[0x5c - 0x58];
    Object_vptr_0* t5c;
    char p3[0x64 - 0x60];
    Object_vptr_0* q64;
    char p4[0x70 - 0x68];
    Object_vptr_0* p70;
};

struct Obj {
    char pad[0xd8];
    Sub* sub;
};

struct Fighter {
    char pad[0x60];
    Obj* obj;
    char pad2[0x10c - 0x64];
    int f10c;
};

extern int g_ftManager;
extern "C" const float lbl_27_rodata_1048;
extern "C" void fn_27_13C43C(void* a, void* b, int c, int d, int e);
extern "C" void fn_27_10C330(int a, int b);
extern "C" void fn_27_138CBC(Fighter* self, int a, int b);

static inline void setRange(Obj* o) {
    Vec3 hi;
    Vec3 lo;
    hi.x = lbl_27_rodata_1048;
    hi.y = lbl_27_rodata_1048;
    hi.z = lbl_27_rodata_1048;
    lo.x = lbl_27_rodata_1048;
    lo.y = lbl_27_rodata_1048;
    lo.z = lbl_27_rodata_1048;
    o->sub->q54->slot86(1, &lo, &hi);
}

extern "C" void fn_27_13BB54(Fighter* arg0, Object_vptr_3c* arg1, int c, int d, int e) {
    Obj* o = arg0->obj;
    fn_27_13C43C(arg0, arg1, c, 0, e);
    switch (arg1->slot40()) {
    case 0x45:
        if (o->sub->p70->slot16() == 0xDC) {
            setRange(o);
            o->sub->q54->slot8(3);
            Vec3 pos = o->sub->r0c->slot4();
            pos.z = lbl_27_rodata_1048;
            o->sub->r0c->slot5(&pos);
            o->sub->p70->slot3(0xDD, o);
            o->sub->t5c->slot55(0xF, 0, 0, -1);
        }
        break;
    case 0x15:
        if (o->sub->p70->slot16() == 0xDE) {
            o->sub->q54->slot8(3);
            o->sub->p70->slot3(0xE, o);
        }
        fn_27_10C330(g_ftManager, arg0->f10c);
        break;
    case 0x1B:
    case 0x1D:
        fn_27_138CBC(arg0, 0, 0);
        break;
    case 0x0:
        o->sub->q64->slot19(0x1200002B, o->sub);
        break;
    case 0xD:
        o->sub->q64->slot19(0x1200002D, o->sub);
        break;
    }
}
