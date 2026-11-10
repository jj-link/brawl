#pragma force_active on

#define V4(n) \
    virtual void n##a(); \
    virtual void n##b(); \
    virtual void n##c(); \
    virtual void n##d();

struct Ground {
    char pad[0x3c];
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void u36();
    virtual void v37(void*, int, int);
    virtual void u38();
    virtual void v39(void*);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s)
    V4(t) V4(u) V4(v) V4(w) V4(y) V4(z) V4(A) V4(B)
    virtual void u112();
    virtual void v113(void*);
    virtual void v114(int);
};

struct Stage {
    char pad0[0x9c];
    void* f9c;
    char pad1[0x100];
    void* f1a0;
    char pad2[0xd0];
    char f274[8];
};

extern "C" {
extern char lbl_73_data_0[];

Ground* fn_73_E688(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_73_9E0(Stage* stage, int kind) {
    Ground* ground;
    int index;
    char* data = lbl_73_data_0;

    switch (kind) {
    case 0x1f:
        ground = fn_73_E688(0x4, data + 0x70, data + 0x8c);
        index = 0x4;
        break;
    case 0x20:
        ground = fn_73_E688(0x4, data + 0x70, data + 0xa0);
        index = 0x5;
        break;
    case 0x21:
        ground = fn_73_E688(0x4, data + 0x70, data + 0xb4);
        index = 0x6;
        break;
    case 0x22:
        ground = fn_73_E688(0x4, data + 0x70, data + 0xc8);
        index = 0x7;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->v37(stage->f1a0, 0, 0);
        ground->v39(stage->f9c);
        ground->v113(stage->f274);
        ground->v114(index);
    }
}
}
