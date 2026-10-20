#pragma force_active on
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
extern "C" const float lbl_107_rodata_138[];
extern "C" void fn_107_1AE80(Vec3* dst, const Vec3* src);

struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 getPos(); virtual void setPos(Vec3*);
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual float getRotYLr();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Vec3 getRot(int);
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21();
    virtual float getScale();
};
struct Other {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int check(int);
    virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
    virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
    virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
    virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29();
    virtual void a30(); virtual void a31(); virtual void a32(); virtual void a33(); virtual void a34();
    virtual void a35();
    virtual Vec3 get(int, int, int);
};
struct ModelBase { int a, b; };
struct Model : ModelBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13();
    virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18();
    virtual void a19(); virtual void a20(); virtual void a21();
    virtual void setNodeSRT(int, Vec3*, Vec3*, Vec3*);
};
struct Modules { char p[4]; Model* model; char q[4]; Posture* posture; char r[0x44]; Other* other; };
struct Acc { char p[0xd8]; Modules* m; };
struct Obj { char p[0x60]; Acc* acc; };

extern "C" void fn_107_1F468(Obj* obj) {
    const float* c = lbl_107_rodata_138;
    Acc* a = obj->acc;
    if (a->m->other->check(3)) {
        Vec3 v = a->m->other->get(3, 1, 0);
        v.z = c[8];
        a->m->posture->setPos(&v);
    }
    float scale = a->m->posture->getScale();
    Vec3 s;
    s.x = s.y = s.z = scale;
    Vec3 rot;
    Vec3 pos;
    Vec3 rawPos = a->m->posture->getPos();
    fn_107_1AE80(&pos, &rawPos);
    Vec3 rawRot = a->m->posture->getRot(0);
    fn_107_1AE80(&rot, &rawRot);
    rot.y += (c[0] == a->m->posture->getRotYLr()) ? c[2] : c[9];
    a->m->model->setNodeSRT(0, &s, &rot, &pos);
}
