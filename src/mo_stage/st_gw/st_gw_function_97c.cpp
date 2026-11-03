#pragma force_active on
#define V10(p) \
    virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
    virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

struct Pad {
    char p[0x3c];
};

struct Ground : Pad {
    V10(a) V10(b) V10(c)
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void startup(void*, int, int);
    virtual void unused38();
    virtual void setData(void*);
    V10(e) V10(f) V10(g) V10(h) V10(i) V10(j) V10(k)
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void setPtrA(void*);
    virtual void setIndex(int);
    virtual void unused116();
    virtual void setPtrB(void*);
};

struct Stage {
    char pad0[0x9c];
    void* d9C;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x38];
    char data1DC[4];
    char data1E0[4];
};

extern "C" {
extern char lbl_63_data_0[];

Ground* fn_63_552C(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_63_97C(Stage* self, int kind) {
    char* data = lbl_63_data_0;
    Ground* ground;
    int index;

    switch (kind) {
    case 20:
        ground = fn_63_552C(11, data + 0x130, data + 0x13c);
        index = 1;
        break;
    case 33:
        ground = fn_63_552C(21, data + 0x14c, data + 0x158);
        index = 0;
        break;
    case 24:
        ground = fn_63_552C(41, data + 0x168, data + 0x174);
        index = 2;
        break;
    case 28:
        ground = fn_63_552C(51, data + 0x184, data + 0x190);
        index = 3;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(self->archive, 0, 0);
        ground->setData(self->d9C);
        ground->setPtrA(self->data1E0);
        ground->setIndex(index);
        ground->setPtrB(self->data1DC);
    }
}
}
