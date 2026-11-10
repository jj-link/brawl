#pragma force_active on

#define V1(p) virtual void p();
#define V2(p) V1(p##a) V1(p##b)
#define V4(p) V2(p##a) V2(p##b)
#define V8(p) V4(p##a) V4(p##b)
#define V32(p) V8(p##a) V8(p##b) V8(p##c) V8(p##d)

struct ObjectBase {
    char pad[0x3c];
};

struct Obj : ObjectBase {
    V32(a) V8(b)
    virtual int getStatus();
    V32(c) V32(d) V32(e) V32(f) V8(g) V8(h)
    virtual int get();
};

struct Motion {
    V8(a) V8(b)
    virtual int kind();
    V8(c) V4(d) V2(e) V1(f)
    virtual int get(int);
};

struct Work {
    V4(a)
    virtual int getInt(unsigned int);
    virtual void set(int, int);
    V4(b) V2(c)
    virtual float getFloat(unsigned int);
    V4(d)
    virtual unsigned int isOn(int);
    virtual void off(int);
    virtual void on(int);
};

struct Mod14 {
    V2(a) V1(b)
    virtual int get();
};

struct Mod4 {
    V4(a)
    virtual void run();
};

struct ModA8 {
    V32(a) V4(b) V1(c)
    virtual int get(int);
};

struct Req {
    int id;
    float a;
    float b;
    unsigned char c, d, e, f;
};

struct Anim {
    V4(a) V2(b) V1(c)
    virtual void f7(float);
    V4(d)
    virtual float f12();
    V8(e) V8(f) V1(g)
    virtual void f30(Req*);
    V8(h)
    virtual void f39(int, int, int, int, int, float, float);
    virtual void f40(int);
    V4(i)
    virtual int f45(int);
    virtual void f46(int, float);
};

struct Mods {
    char pad0[8];
    Anim* anim;
    char pad1[8];
    Mod14* mod14;
    char pad2[0x40];
    Mod4* mod58;
    Mod4* mod5c;
    char pad3[4];
    Work* work;
    char pad4[8];
    Motion* motion;
    char pad5[0x34];
    ModA8* moda8;
};

struct Accesser {
    char pad[8];
    Obj* obj;
    char padC[0xcc];
    Mods* m;
};

extern "C" {
    int fn_27_193590(Accesser*, int);
    void fn_27_17B228(void*, Accesser*);
    void fn_27_17DA90(void*, Accesser*, float);
    void fn_27_17E3F8(Accesser*, int, int);
    void fn_27_193378(Accesser*, float);
    void fn_27_1D6434(int, int, int, int, Accesser*);
    float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned int, unsigned int);
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    extern const char lbl_27_data_69C0[];
    extern const char lbl_27_data_248[];
    extern float lbl_27_rodata_2388[];
}

extern "C" void fn_27_17CD5C(void* self, Accesser* acc) {
    const float* k = lbl_27_rodata_2388;
    int kind = acc->m->motion->kind();
    int mot = acc->m->motion->get(0);
    switch (acc->obj->getStatus()) {
    case 7:
        acc->m->work->off(0x22000013);
        break;
    default:
        acc->m->work->on(0x22000013);
        break;
    }
    if (fn_27_193590(acc, mot) == 0) {
        acc->m->mod58->run();
        fn_27_17B228(self, acc);
        if (acc->m->work->isOn(0x22000013) != 1 || acc->m->mod14->get() != 2) {
            acc->m->anim->f39(1, 0x173, 0x135, 0, 0, k[2], k[3]);
        }
        if (acc->m->anim->f45(1) != -1) {
            acc->m->anim->f46(1, k[2]);
        } else {
            acc->m->anim->f7(k[2]);
        }
        acc->m->work->set(0, 0x2000000c);
        float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd79, 0);
        fn_27_17DA90(self, acc, c);
        Obj* o = (Obj*)__dynamic_cast(acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        fn_27_1D6434(2, 0x64, 1, o->get(), acc);
        acc->m->mod5c->run();
    }
    int m2 = acc->m->moda8->get(0);
    switch (acc->m->work->getInt(0x2000000C)) {
    case 0:
        if (acc->m->work->isOn(0x22000013) == 1 && acc->m->mod14->get() == 2) {
            acc->m->anim->f40(1);
            Req r;
            r.id = 0x17a;
            r.a = k[2];
            r.b = k[2];
            r.c = 0;
            r.d = 0;
            r.e = 0;
            r.f = 0;
            acc->m->anim->f30(&r);
            fn_27_17DA90(self, acc, k[2]);
        } else {
            if (acc->m->anim->f45(1) == -1) {
                Anim* a = acc->m->anim;
                float f = a->f12();
                a->f39(1, 0x173, 0x135, 0, 0, f, k[2]);
                fn_27_17DA90(self, acc, k[2]);
            }
            fn_27_17E3F8(acc, 0x150, 0x179);
        }
        break;
    case 1:
        if (acc->m->work->isOn(0x22000013) == 1 && acc->m->mod14->get() == 2) {
            acc->m->anim->f40(1);
            Req r;
            r.id = 0x175;
            r.a = k[2];
            r.b = k[3];
            r.c = 0;
            r.d = 0;
            r.e = 0;
            r.f = 0;
            acc->m->anim->f30(&r);
        } else {
            if (acc->m->anim->f45(1) == -1) {
                acc->m->anim->f39(1, 0x173, 0x135, 0, 0, k[2], k[3]);
            }
            if (kind != 0xae) {
                if (m2 == 0) {
                    fn_27_17E3F8(acc, 0x177, 0x178);
                } else {
                    fn_27_17E3F8(acc, 0x174, 0x175);
                }
            } else {
                if (acc->m->anim->f45(1) != -1) {
                    acc->m->anim->f46(1, k[2]);
                } else {
                    acc->m->anim->f7(k[2]);
                }
                acc->m->work->set(0, 0x2000000c);
                break;
            }
        }
        if (acc->m->work->isOn(0x22000013) == 1 && acc->m->mod14->get() == 2) {
            fn_27_193378(acc, acc->m->work->getFloat(0x21000008) - k[4]);
        } else {
            fn_27_17DA90(self, acc, k[2]);
        }
        break;
    }
}
