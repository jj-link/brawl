#pragma force_active on

#define V4(n) \
    virtual void n##a(); \
    virtual void n##b(); \
    virtual void n##c(); \
    virtual void n##d();

struct Ground {
    char pad[0x3c];
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void unused36();
    virtual void startup(int, int, int);
    virtual void unused38();
    virtual void setData(int);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s)
    V4(t) V4(u) V4(v) V4(w) V4(y) V4(z) V4(A) V4(B) V4(C) V4(D)
    virtual void fn120(void*);
    virtual void fn121(void*);
    virtual void fn122(void*);
    virtual void fn123(void*);
    virtual void fn124(void*);
    virtual void fn125(void*);
    virtual void fn126(int);
};

struct Stage {
    char pad0[0x9c];
    int f9c;
    char pad1[0x100];
    int f1a0;
    char pad2[0x34];
    char f1d8[8];
    char f1e0[2];
    char f1e2[2];
    char f1e4[0x780];
    char f964[0x27c];
    char fbe0[4];
};

extern "C" {
extern char lbl_61_data_0[];

Ground* fn_61_D2D4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_61_D58(Stage* stage, int kind) {
    Ground* ground;
    int index;
    char* data = lbl_61_data_0;

    switch (kind) {
    case 11:
        ground = fn_61_D2D4(0x50, data + 0x1b8, data + 0x1c4);
        index = 4;
        break;
    case 12:
        ground = fn_61_D2D4(0x50, data + 0x1b8, data + 0x1dc);
        index = 5;
        break;
    case 13:
        ground = fn_61_D2D4(0x50, data + 0x1b8, data + 0x1f4);
        index = 6;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->f1a0, 0, 0);
        ground->setData(stage->f9c);
        ground->fn122(stage->f1e0);
        ground->fn123(stage->f1d8);
        ground->fn120(stage->f1e2);
        ground->fn121(stage->fbe0);
        ground->fn124(stage->f1e4);
        ground->fn125(stage->f964);
        ground->fn126(index);
    }
}
}