#pragma force_active on
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
extern "C" const float lbl_107_rodata_100[];
extern "C" void fn_107_1AE80(Vec3* dst, const Vec3* src);

struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 getPos();
    virtual void setPos(Vec3*);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Vec3 getRot(int);
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual float getAux18();
    virtual void v19(); virtual void v20(); virtual void v21();
    virtual float getScale();
};

struct Other {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float check(int);
};

struct ModelBase { int a; int b; };
struct Model : ModelBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual void setSRT(int, Vec3*, Vec3*, Vec3*);
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void setX(int, float);
};

struct Modules { char p[4]; Model* model; char q[4]; Posture* posture; char r[0x54]; Other* other; };
struct Acc { char p[0xd8]; Modules* m; };
struct Obj { char p[0x60]; Acc* acc; };

extern "C" void fn_107_1AD2C(Obj* obj) {
    const float* const c = lbl_107_rodata_100;
    Acc* acc = obj->acc;
    float v = (c[0] == acc->m->other->check(0x21000000)) ? c[6] : c[2];
    obj->acc->m->model->setX(4, v);
    float scale = acc->m->posture->getScale();
    Vec3 s;
    Vec3 rot;
    Vec3 pos;
    s.x = s.y = s.z = scale;
    Vec3 rawPos = acc->m->posture->getPos();
    fn_107_1AE80(&pos, &rawPos);
    Vec3 rawRot = acc->m->posture->getRot(0);
    fn_107_1AE80(&rot, &rawRot);
    rot.y += acc->m->posture->getAux18();
    acc->m->model->setSRT(0, &s, &rot, &pos);
}
