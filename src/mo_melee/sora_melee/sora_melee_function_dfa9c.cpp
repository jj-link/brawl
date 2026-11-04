#pragma force_active on

struct Pair {
    int a, b;
};

struct Data {
    int a;
    Pair b;
    int c;
    float d;
    int e, f, g, h;
    float i, j, k;
    int l, m, n, o, p;
    Pair q;
    int r;
    Pair s;
    int t;
    unsigned short u;
    unsigned char v, w;
    int x;
    unsigned char y;
};

#define PAD virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); \
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); \
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); \
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); \
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); \
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); \
    virtual void v24(); virtual void v25();

struct Base { PAD virtual Data* get(); };
struct Derived { PAD virtual Data* get(int); };

extern "C" void fn_27_DFA9C(Derived* self, int unused, int idx) {
    Data* src = ((Base*)self)->get();
    Data* dst = self->get(idx);
    *dst = *src;
}