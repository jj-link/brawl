#pragma force_active on
struct P { int x; int y; };
struct D {
    P a; int c;
    P d; int e; int f;
    P g; int h;
    P i; int j, k, l, m;
    P n; int o;
    float p, q, r;
    P s; P t; P u;
    short v;
    unsigned char w, x, y;
};

#define PAD virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); \
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); \
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); \
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); \
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); \
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); \
    virtual void v24(); virtual void v25();

struct B { PAD virtual D* get(); };
struct A { PAD virtual D* get(int i); };

extern "C" void fn_51_98C4(A* o, int x, int idx) {
    D* src = ((B*)o)->get();
    D* dst = o->get(idx);
    *dst = *src;
}
