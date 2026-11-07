#pragma force_active on
extern "C" {
extern float lbl_41_rodata_C90[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_1D178(float*);
void fn_41_51C4(void*, void*);
}

struct Vec2 { float f[2]; };
struct Buf { char data[0x10]; };

extern "C" {
Vec2* fn_41_2354(Vec2*, float, float);
float fn_41_15A00(float, Vec2*);
void fn_41_1E768(Buf*, void*, int, float, void*, int);
}

class Object_vptr_0 {
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
    virtual void slot15(Buf*, void*);
    virtual void slot16();
    virtual void slot17();
    virtual float slot18();
};

struct Self {
    char pad[8];
    void* obj;
};

extern "C" void fn_41_1F3B8(Self* self, Object_vptr_0* o, float* pos, void* arg) {
    float* t = lbl_41_rodata_C90;
    if (fn_41_1D178(pos) <= t[0x44 / 4]) return;
    Vec2 v;
    Vec2 tmp;
    v = *fn_41_2354(&tmp, pos[0], pos[1]);
    float a = fn_41_15A00(o->slot18(), &v);
    float m;
    if (t[0x90 / 4] == o->slot18()) {
        m = t[0];
    } else {
        m = t[0x30 / 4];
    }
    a *= m;
    fn_41_51C4(__dynamic_cast(self->obj, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1), arg);
    Buf b;
    fn_41_1E768(&b, self, 2, a, arg, 0);
    o->slot15(&b, arg);
}
