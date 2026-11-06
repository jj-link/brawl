#pragma force_active on
struct Vec3 { float x, y, z; Vec3() {} };
struct Vec2 { float x, y; };

struct Posture {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual Vec3 getPos();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void setLr(float);
    virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void update();
    virtual void s20(); virtual void s21();
    virtual float getScale();
};

struct Work {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};

struct Status {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int getStatusKind();
};

struct Kinetic {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual void* getEnergy(int);
};

struct Energy {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4();
    virtual void reset(int, const Vec2*, float*, void*);
};

struct Pad3c { char pad[0x3c]; };
struct Obj : Pad3c {
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
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void call();
};

struct Mods {
    char pad0[0xc];
    Posture* posture;
    char pad1[0x64 - 0x10];
    Work* work;
    char pad2[0x70 - 0x68];
    Status* status;
    char pad3[0x7c - 0x74];
    Kinetic* kinetic;
};

struct Acc {
    char pad[8];
    Obj* obj;
    char pad2[0xd8 - 0xc];
    Mods* mods;
};

extern "C" {
extern const char lbl_119_data_5CF4[], lbl_119_data_1374[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
double atan2(double, double);
Vec3 fn_119_8E54(void*);
float* fn_119_8F00(float*, float, float, float);
Vec3 fn_119_F4A4(const Vec3&, const Vec3&);
float fn_119_897C(Vec3*);
void fn_27_89DAC(int, void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
}

#define CF(id) getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, id, 0)

extern "C" void fn_119_EE24(void*, Acc* a) {
    switch (a->mods->status->getStatusKind()) {
    case 0x116:
        fn_27_89DAC(3, a);
        fn_27_89DAC(1, a);
        fn_27_89DAC(2, a);
        fn_27_89DAC(4, a);
        fn_27_89DAC(0, a);
        break;
    case 0x122: {
        Vec3 p = fn_119_8E54(a);
        Vec3 b = a->mods->posture->getPos();
        float f30 = -a->mods->work->getFloat(0x21000011);
        Vec3 q;
        __memcpy(&q, &p, sizeof(Vec3));
        float f31 = a->mods->posture->getScale();
        q.x = p.x + f30 * (f31 * CF(0xfc7));
        q.y = p.y + f31 * CF(0xfc8);
        a->mods->work->setFloat(q.x, 0x21000004);
        a->mods->work->setFloat(q.y, 0x21000005);
        a->mods->work->setFloat(f30, 0x2100000b);
        int s;
        if (q.x - p.x < 0.0f) s = -1; else s = 1;
        float sgn = (float)s;
        a->mods->work->setFloat(-sgn, 0x21000009);
        q.z = b.z;
        Vec3 d = fn_119_F4A4(q, b);
        float len = fn_119_897C(&d);
        float k = CF(0xfc9);
        float r;
        float mx = (float)getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(a, 0x5dc9, 0);
        r = len / k;
        if (r < 1.0f) {
            k = len;
            r = 1.0f;
        } else if (r > mx) {
            k = len / mx;
            r = mx;
        }
        a->mods->work->setFloat(k, 0x2100000f);
        a->mods->work->setFloat(mx - r, 0x21000008);
        break;
    }
    case 0x123: {
        Vec3 b = a->mods->posture->getPos();
        float dx = a->mods->work->getFloat(0x21000004) - b.x;
        float dy = a->mods->work->getFloat(0x21000005) - b.y;
        a->mods->work->setFloat(57.29578f * (float)atan2(dx, dy), 0x2100000a);
        Vec3 p = fn_119_8E54(a);
        int s;
        if (p.x - a->mods->work->getFloat(0x21000004) < 0.0f) s = -1; else s = 1;
        float lr = (float)s;
        a->mods->posture->setLr(lr);
        a->mods->posture->update();
        a->obj->call();
        break;
    }
    case 0x124: {
        Posture* po = a->mods->posture;
        float v = a->mods->work->getFloat(0x21000009);
        po->setLr(v);
        a->mods->posture->update();
        a->obj->call();
        Energy* e = (Energy*)__dynamic_cast(a->mods->kinetic->getEnergy(1), 0, lbl_119_data_5CF4, lbl_119_data_1374, 1);
        float k = CF(0xfc5);
        Vec2 t;
        t.x = 0.0f;
        t.y = k;
        float rot[3];
        e->reset(0, &t, fn_119_8F00(rot, 0.0f, 0.0f, 0.0f), a);
        *(float*)((char*)e + 0x10) = 0.0f;
        *(float*)((char*)e + 0x14) = k;
        *(float*)((char*)e + 0x1c) = -1.0f;
        *(float*)((char*)e + 0x18) = 0.0f;
        ((unsigned char*)e)[5] |= 0x80;
        break;
    }
    case 0x125: {
        Energy* e = (Energy*)__dynamic_cast(a->mods->kinetic->getEnergy(1), 0, lbl_119_data_5CF4, lbl_119_data_1374, 1);
        float k = CF(0xfc6);
        Vec2 t;
        t.x = 0.0f;
        t.y = -k;
        float rot[3];
        e->reset(0, &t, fn_119_8F00(rot, 0.0f, 0.0f, 0.0f), a);
        *(float*)((char*)e + 0x10) = 0.0f;
        *(float*)((char*)e + 0x14) = k;
        *(float*)((char*)e + 0x1c) = -1.0f;
        *(float*)((char*)e + 0x18) = 0.0f;
        ((unsigned char*)e)[5] |= 0x80;
        break;
    }
    }
}
