#pragma force_active on

typedef unsigned long u32;
typedef unsigned char u8;

struct Node {
    u32 a;
    u32 b;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual Node* get(u32);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void next();
};

struct Arg {
    Node* p;
    u8 flag;

    Arg(Node* q) : p(q), flag(0) {}
};

inline Arg argument(Obj* obj) {
    return Arg(obj->get(0));
}

inline u32 value(Arg a) {
    return a.flag == 1 ? 0 : a.p->b;
}

struct Dest {
    u8 pad[0x30];

    u32 a0 : 9;
    u32 a : 10;
    u32 a1 : 3;
    u32 b : 1;
    u32 c : 4;
    u32 a2 : 5;

    u32 d0 : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
    u32 d1 : 19;

    u32 h : 16;
    u32 h0 : 1;
    u32 i : 1;
    u32 j : 1;
    u32 k : 3;
    u32 l : 1;
    u32 m : 1;
    u32 n : 1;
    u32 o : 1;
    u32 p : 1;
    u32 h1 : 5;

    u32 q : 1;
    u32 q0 : 31;
};

extern "C" void fn_27_410F0(void*, void*, Obj* obj, Dest* dst) {
    dst->h = value(argument(obj));
    obj->next();

    u32 v = value(argument(obj));
    dst->d = v >> 21;
    dst->i = v >> 25;
    dst->j = v >> 26;
    dst->a = v >> 6;
    dst->k = v;
    dst->e = v >> 22;
    dst->l = v >> 27;
    dst->b = v >> 20;
    dst->m = v >> 28;
    dst->f = v >> 23;
    dst->n = v >> 29;
    dst->c = v >> 16;
    dst->o = v >> 30;
    dst->g = v >> 24;
    dst->p = v >> 31;
    dst->q = v >> 4;

    obj->next();
}
