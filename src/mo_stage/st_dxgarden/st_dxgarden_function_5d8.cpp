#pragma force_active on
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct Pad { char p[0x3c]; };
struct Ground : Pad {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void x38();
    virtual void init(int, int, int);
    virtual void x40();
    virtual void setData(int);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s) V4(t) V4(u) V4(v) V4(w) V4(y) V4(z) V4(A) V4(B)
    virtual void x114(int);
};
struct Stage { char pad0[0x9c]; int f9c; char pad1[0x1a0-0xa0]; int f1a0; };
extern "C" {
extern char lbl_77_data_0[];
Ground* fn_77_605C(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_77_5D8(Stage* stage, int kind) {
    Ground* g;
    int flag;
    char* d = lbl_77_data_0;
    switch (kind) {
    case 8:
        g = fn_77_605C(1, d + 0x74, d + 0x88);
        flag = 0;
        break;
    case 9:
        g = fn_77_605C(2, d + 0x98, d + 0xa8);
        flag = 1;
        break;
    default:
        g = 0;
    }
    if (g) {
        addGround__5StageFP6Ground(stage, g);
        g->init(stage->f1a0, 0, 0);
        g->setData(stage->f9c);
        g->x114(flag);
    }
}
}
