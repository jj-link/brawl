#pragma force_active on
class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(int, float*);
    virtual void v31();
    virtual void v32();
};

struct Sub {
    char pad[0x64];
    VObj* a;
    char pad2[0x20];
    VObj* b;
};

struct Mid {
    char pad[0xD8];
    Sub* s;
};

struct Top {
    char pad[0x60];
    Mid* m;
};

extern "C" void fn_118_8FA0(Top* self, float f) {
    float v[3];
    Sub* s = self->m->s;
    VObj* o1 = s->a;
    VObj* o2 = s->b;
    int r28 = o1->v4(0x10000047);
    int r30 = o1->v4(0x10000048);
    v[0] = f;
    v[1] = f;
    v[2] = f;
    o2->v30(r28, v);
    o2->v30(r30, v);
}
