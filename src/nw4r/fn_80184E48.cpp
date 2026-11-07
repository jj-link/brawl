#pragma force_active on

extern "C" {
extern void* lbl_804657A0[];
extern int lbl_805A0508;
extern float lbl_805A30E0;

void fn_80204E6C(int, void*);
void fn_80182894(void*, int);
void __dl__FPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__Q34nw4r2ut5ColorFv(void*, int);
}

class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual int slot1();
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

    char pad[0x55];
    unsigned char flag;
};

class Class_804657A8 {
public:
    virtual void fn_80184E48();
    virtual void fn_801856B4();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_801850A4();
    virtual void fn_80183024();
    virtual void fn_801830B0();
    virtual void fn_80184FCC();
    virtual void fn_80185000();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80185074();
    virtual void fn_8018508C();
    virtual void fn_80182B40();
    virtual void fn_80182BEC();
    virtual void fn_80183164();
    virtual void fn_80183180();
    virtual void fn_80183210();
    virtual void fn_80183228();
    virtual void fn_801832FC();
    virtual void fn_80183374();
    virtual void fn_80183618();
    virtual void fn_8018342C();
    virtual void fn_801852B8();
    virtual void fn_80185330();
};

struct Vec {
    float x, y;

    Vec(float a, float b) : x(a), y(b) {}
};

struct Obj {
    void* vtable;
    char pad04[0x24];
    Object_vptr_0* field28;
    char pad2c[0xb4];
    Object_vptr_0* fieldE0;
    float x, y;
    char padEC[0x11];
    unsigned char owned : 1;
    unsigned char rest : 7;
};

inline void setPosition(Obj* self, const Vec& v) {
    self->x = v.x;
    self->y = v.y;
}

extern "C" void* fn_80184E48(void* arg0, int arg1) {
    if (arg0) {
        Obj* self = (Obj*)arg0;
        self->vtable = lbl_804657A0;

        if (self->owned) {
            self->fieldE0->slot0(-1);
            fn_80204E6C(lbl_805A0508, self->fieldE0);
            self->owned = 0;
        }

        self->fieldE0 = 0;
        if (self->fieldE0) {
            setPosition(self, Vec((float)self->fieldE0->slot1(),
                                  (float)self->fieldE0->slot1()));
        } else {
            Vec v(lbl_805A30E0, lbl_805A30E0);
            setPosition(self, v);
        }

        Object_vptr_0* o = self->field28;
        if (o && o->flag == 0) {
            o->slot0(-1);
            fn_80204E6C(lbl_805A0508, self->field28);
            self->field28 = 0;
        }

        ((Class_804657A8*)self)->fn_80185330();
        __destroy_arr((char*)self + 0xd8, __dt__Q34nw4r2ut5ColorFv, 4, 2);
        fn_80182894(self, 0);

        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return arg0;
}
