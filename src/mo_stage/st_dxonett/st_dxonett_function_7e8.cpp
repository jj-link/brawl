#pragma force_active on

#define V4(n) \
    virtual void n##a(); \
    virtual void n##b(); \
    virtual void n##c(); \
    virtual void n##d();

struct Pad {
    char p[0x3c];
};

struct Ground : Pad {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void unused36();
    virtual void startup(int, int, int);
    virtual void unused38();
    virtual void setData(int);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r)
    V4(s) V4(t) V4(u) V4(v) V4(w) V4(y) V4(z) V4(A) V4(B)
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void setIndex(int);
};

struct Stage {
    char pad0[0x9c];
    int f9c;
    char pad1[0x100];
    int f1a0;
};

extern "C" {
extern char lbl_78_data_0[];

Ground* fn_78_26D8(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_78_7E8(Stage* stage, int kind) {
    Ground* g;
    int flag;
    char* d = lbl_78_data_0;

    switch (kind) {
    case 4:
        g = fn_78_26D8(3, d + 0x90, d + 0xa8);
        flag = 0;
        break;
    case 5:
        g = fn_78_26D8(4, d + 0xbc, d + 0xd4);
        flag = 1;
        break;
    default:
        g = 0;
    }

    if (g) {
        addGround__5StageFP6Ground(stage, g);
        g->startup(stage->f1a0, 0, 0);
        g->setData(stage->f9c);
        g->setIndex(flag);
    }
}
}
