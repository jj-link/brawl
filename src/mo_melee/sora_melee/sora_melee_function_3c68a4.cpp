#pragma force_active on

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Vec2 {
    float x, y;
};

struct Owner {
    char pad[0x3c];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual int get();
};

struct Model {
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void getInto(int, Vec*);
    virtual Vec get(int);
    virtual void v26(); virtual void v27(); virtual void v28();
    virtual void set(int, const Vec&);
};

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int getIndex(unsigned int);
    virtual void setIndex(int, unsigned int);
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void set(int, unsigned int);
    virtual void v10(); virtual void v11();
    virtual float getFloat(unsigned int);
    virtual void setFloat(unsigned int, float);
};

struct Pair {
    unsigned int a, b;
};

struct Effect {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void* getObj(int);
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual Pair get(short*);
};

struct Energy {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4();
    virtual void activate(int, Vec2*, Vec*, void*);
    unsigned char flag;
};

struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual float get();
};

struct Collision {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int get();
};

struct Modules {
    char p0[4];
    Model* model;
    char p8[4];
    Posture* posture;
    char p10[4];
    Collision* collision;
    char p18[0x4c];
    Work* work;
    char p68[0x14];
    Effect* effect;
};

struct Accesser {
    char pad[8];
    Owner* owner;
    char pC[0xcc];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_8080[];
extern float lbl_27_data_A2010[];
extern float lbl_27_data_A2020[];
extern char lbl_27_data_2E380[];
extern char lbl_27_data_CDF8[];

float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, Accesser*);
void* __dynamic_cast(void*, long, const void*, const void*, long);

void fn_27_3C68A4(void*, Accesser* a) {
    const float* c = lbl_27_rodata_8080;
    int collision = a->modules->collision->get();
    a->modules->work->getIndex(0x20000008);

    Vec q;
    float direction[3];
    direction[0] = c[2];
    direction[1] = c[2];
    direction[2] = c[2];

    int index = a->modules->work->getIndex(0x20000002);
    if (index >= 0 && index < 4) {
        direction[0] = c[2];
        direction[1] *= lbl_27_data_A2010[index];
        direction[2] *= lbl_27_data_A2020[index];
        a->modules->work->set(1, 0x20000002);
    } else {
        direction[0] = c[2];
        direction[1] = c[2];
        direction[2] = c[2];
    }

    int kind = a->owner->get();
    Model* model = a->modules->model;
    int modelIndex = kind == 5 ? 0x196 : 3;
    model->getInto(modelIndex, (Vec*)direction);

    float angle = a->modules->work->getFloat(0x2100000A);
    float scaled = c[11] * fn_27_192278(a, 0xFAC);
    float f30 = scaled * angle;
    float other = a->modules->work->getFloat(0x21000006);
    float value = other + f30 * fn_27_192278(a, 0xFBE);

    while (value < c[1])
        value += c[6];
    while (value > c[6])
        value -= c[6];

    a->modules->work->setFloat(0x21000006, value);

    short one = 1;
    Pair copy;
    Pair pair = a->modules->effect->get(&one);
    copy = pair;
    float neg = -fn_27_192278(a, 0xFA1);

    if (*(float*)&copy.b <= neg) {
        unsigned char* effect = (unsigned char*)a->modules->effect->getObj(2);
        if (((effect[5] >> 7) & 1) == 0) {
            effect = (unsigned char*)a->modules->effect->getObj(2);
            Energy* target = (Energy*)__dynamic_cast(
                effect, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
            Vec2 p;
            float x = *(float*)&copy.a;
            q.x = c[1];
            q.y = c[1];
            q.z = c[1];
            p.x = x;
            p.y = c[1];
            target->activate(0, &p, &q, a);
            ((unsigned char*)target)[5] |= 0x80;
            fn_27_89DAC(3, a);
        }
    }

    float f = a->modules->work->getFloat(0x21000006);
    int n = a->owner->get() == 5 ? 0x197 : 4;
    Vec b = a->modules->model->get(n);
    b.x = c[7] * f;
    a->modules->model->set(n, b);

    n = a->owner->get() == 5 ? 0x197 : 4;
    Vec d = a->modules->model->get(n);
    if (a->modules->posture->get() == c[3])
        d.y = c[4];
    else
        d.y = c[1];
    a->modules->model->set(n, d);

    a->modules->work->setIndex(collision, 0x20000008);
}
}
