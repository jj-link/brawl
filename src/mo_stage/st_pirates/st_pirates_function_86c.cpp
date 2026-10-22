#pragma force_active on
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();

struct Ground {
    char pad[0x3c];
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void f36();
    virtual void v39(int, int, int);
    virtual void f38();
    virtual void v41(int);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s) V4(t) V4(u) V4(v) V4(w) V4(x) V4(y)
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void v114(void*);
    virtual void v115(void*);
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void v119(void*);
    virtual void v120(float);
    virtual void v121(void*);
};

struct Stage {
    char pad0[0x9c];
    int f9c;
    char padA0[0x100];
    int f1a0;
    char pad1a4[0x2d4 - 0x1a4];
    char pad2d4[0x569 - 0x2d4];
};

extern "C" {
extern char lbl_52_data_0[];
extern float lbl_52_rodata_8;
extern float lbl_52_rodata_C;

Ground* fn_52_F6D4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_52_86C(Stage* self, int kind) {
    Ground* ground;
    float val;
    void* ptr;
    const char* data = lbl_52_data_0;

    switch (kind) {
    case 3:
        ground = fn_52_F6D4(7, data + 0x40, data + 0x50);
        val = lbl_52_rodata_8;
        ptr = (void*)((char*)self + 0x2d4);
        break;
    case 2:
        ground = fn_52_F6D4(8, data + 0x60, data + 0x70);
        val = lbl_52_rodata_C;
        ptr = (void*)((char*)self + 0x2d4);
        break;
    case 4:
        ground = fn_52_F6D4(9, data + 0x80, data + 0x90);
        val = lbl_52_rodata_8;
        ptr = (void*)((char*)self + 0x2d4);
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->v39(self->f1a0, 0, 0);
        ground->v41(self->f9c);
        ground->v119(ptr);
        ground->v120(val);
        ground->v121((void*)((char*)self + 0x568));
        ground->v114((void*)((char*)self + 0x1dc));
        ground->v115((void*)((char*)self + 0x564));
    }
}
}
