#pragma force_active on

#define V1(n) virtual void n();
#define V10(p) V1(p##0) V1(p##1) V1(p##2) V1(p##3) V1(p##4) V1(p##5) V1(p##6) V1(p##7) V1(p##8) V1(p##9)

struct Pad {
    char p[0x3c];
};

struct Ground : Pad {
    V10(a) V10(b) V10(c)                       /* 0..29 */
    V1(d0) V1(d1) V1(d2) V1(d3) V1(d4) V1(d5) V1(d6) /* 30..36 */
    virtual void f37(void*, int, int);         /* 0x9c: startup */
    V1(v38)                                    /* 0xa0 */
    virtual void f39(void*);                   /* 0xa4 */
    V10(e) V10(g) V10(h) V10(i) V10(j) V10(k) V10(l) /* 40..109 */
    V1(m0) V1(m1) V1(m2) V1(m3) V1(m4) V1(m5)  /* 110..115 */
    virtual void f116(void*);                  /* 0x1d8 */
    virtual void f117(void*);                  /* 0x1dc */
};

struct Param {
    char pad[0x1c];
    float f1c;
};

struct Stage {
    char pad0[0x9c];
    Param* f9c;
    char pad_a0[0x100];
    void* f1a0;
};

extern "C" {
extern char lbl_79_data_D0[];
extern char lbl_79_data_E8[];

Ground* fn_79_A6B0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void createCollision__5StageFP9gfArchiveiP6Ground(Stage*, void*, int, Ground*);
float randf__Fv();

void fn_79_8A8(Stage* self, unsigned int arg1, unsigned int arg2) {
    if (arg1 < 6 && arg2 < 5) {
        Param* p = self->f9c;
        if (p != 0) {
            int t7 = arg1 * 0x8c;
            char* t6 = (char*)self + t7;
            char* elem = t6 + 0x1f4 + arg2 * 0x1c;
            Ground* g = fn_79_A6B0(4, lbl_79_data_D0, lbl_79_data_E8);
            if (g != 0) {
                addGround__5StageFP6Ground(self, g);
                g->f37(self->f1a0, 0, 0);
                g->f39(self->f9c);
                g->f116(elem);
                g->f117((char*)self + 0x1d8);
                if (randf__Fv() < p->f1c) {
                    elem[0x1a] = 1;
                } else {
                    elem[0x1a] = 0;
                }
                elem[0x19] = 7;
                createCollision__5StageFP9gfArchiveiP6Ground(self, self->f1a0, 3, g);
            }
        }
    }
}
}
