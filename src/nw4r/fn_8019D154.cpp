#pragma force_active on

struct Color {
    unsigned char c0, c1, c2, c3;
};

struct Res {
    int id;
    float x, y;
    Color color;
};

struct Req {
    char pad[0xC];
    int unkC;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
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
    virtual void v30();
    virtual void v31();
    virtual Res* get(Req* req);
};

struct Out {
    int id;
    float x, y;
    char pad[8];
    Color color;

    void set(float a, float b) {
        if (this != 0) {
            x = a;
            y = b;
        }
    }
};

extern "C" void fn_8019D154(Obj* obj, Out** out) {
    Req req;
    req.unkC = -1;
    Res* p = obj->get(&req);

    Out* t = *out;
    int id = p->id;
    if (t != 0) {
        t->id = id;
    }

    t = *out;
    t->set(p->x, p->y);

    Color c = p->color;
    t = *out;
    if (t != 0) {
        t->color = c;
    }
}
