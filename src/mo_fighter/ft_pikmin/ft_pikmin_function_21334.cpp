#pragma force_active on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
union U { unsigned long long r; Vec2 v; };

struct PosMod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 getPos();
};
struct WorkMod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual unsigned int getInt(unsigned int);
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual float getFloat(unsigned int);
};
struct Mods { char pad[0xc]; PosMod* pos; char pad2[0x64 - 0x10]; WorkMod* work; };
struct Acc { char pad[0xd8]; Mods* mods; };
struct Obj {
    virtual void v0();
    virtual void update(Acc*);
    virtual unsigned long long get();
    int pad0;
    Vec2 a, b, c, pad, d;
};

extern "C" {
extern const float lbl_113_rodata_88[];
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
float fn_113_BF74(const Vec2*);
void fn_113_BC00(Vec2*, const Vec2*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Acc*, unsigned long, unsigned long);
void fn_8003DBA8(Vec2*);
void fn_113_1E5B8(Vec2*, float);
}
float mtSqrtf(float);

extern "C" void fn_113_21334(void*, Obj* obj, Acc* acc) {
    const float* c = lbl_113_rodata_88;
    Vec2 pos;
    U diff;
    U n;
    U n2;
    U sv;
    U nl;
    PosMod* pm = acc->mods->pos;
    fn_113_C30C(&pos, pm->getPos().x, pm->getPos().y);
    WorkMod* w = acc->mods->work;
    float ty = w->getFloat(0x11000005);
    U r;
    Vec2 tgt;
    r.r = fn_113_BFB0(fn_113_C30C(&tgt, w->getFloat(0x11000004), ty), &pos);
    diff = r;
    float len = fn_113_BF74(&diff.v);
    if (c[2] == len) {
        Vec2 z; z.x = c[2]; z.y = c[2];
        fn_113_BC00(&obj->a, &z);
        return;
    }
    unsigned int flags = acc->mods->work->getInt(0x10000011);
    unsigned int f4 = flags & 4;
    if (f4 || (flags & 8)) {
        fn_113_BC00(&obj->a, &diff.v);
        Vec2 z; z.x = c[2]; z.y = c[2];
        fn_113_BC00(&obj->b, &z);
        if (f4) {
            float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc7, 0);
            Vec2 v; v.x = f; v.y = f;
            fn_113_BC00(&obj->c, &v);
            f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc9, 0);
            Vec2 v2; v2.x = f; v2.y = f;
            fn_113_BC00(&obj->d, &v2);
        } else {
            Vec2 v; v.x = c[3]; v.y = c[3];
            fn_113_BC00(&obj->c, &v);
            Vec2 v2; v2.x = c[3]; v2.y = c[3];
            fn_113_BC00(&obj->d, &v2);
        }
    } else if (c[2] != len) {
        float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc7, 0);
        Vec2 v; v.x = f; v.y = f;
        fn_113_BC00(&obj->c, &v);
        f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc9, 0);
        Vec2 v2; v2.x = f; v2.y = f;
        fn_113_BC00(&obj->d, &v2);
        U s;
        s.r = obj->get();
        float sl = fn_113_BF74(&s.v);
        if (c[2] != sl) {
            n = diff;
            fn_8003DBA8(&n.v);
            fn_113_1E5B8(&n.v, mtSqrtf(sl));
            fn_113_BC00(&obj->a, &n.v);
        }
        n2 = diff;
        fn_8003DBA8(&n2.v);
        fn_113_1E5B8(&n2.v, getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc6, 0));
        fn_113_BC00(&obj->b, &n2.v);
    } else {
        Vec2 z; z.x = c[2]; z.y = c[2];
        fn_113_BC00(&obj->a, &z);
        Vec2 z2; z2.x = c[2]; z2.y = c[2];
        fn_113_BC00(&obj->b, &z2);
    }
    obj->update(acc);
    if (c[2] != len) {
        U s;
        s.r = obj->get();
        sv = s;
        if (fn_113_BF74(&sv.v) > len) {
            U s2;
            s2.r = obj->get();
            nl = s2;
            fn_8003DBA8(&nl.v);
            fn_113_1E5B8(&nl.v, mtSqrtf(len));
            if (nl.v.y < c[2]) nl.v.y *= c[13];
            fn_113_BC00(&obj->a, &nl.v);
        }
    }
}
