#pragma force_active on
extern "C" {
unsigned char *fn_802C05BC();
void fn_802C05B4();
void fn_802C05B0();
void fn_802C05B8();
int fn_802CB630(int, unsigned char *, int);
void fn_802CB640();
int fn_802CB644(int, int, int);
void fn_802CAA50(void *);
}
struct Cell { unsigned char a, b, c; };
struct Obj {
    char pad0[0x18c];
    int flag1;
    unsigned char a[32][32];
    unsigned char b[32][32];
    void *f1;
    void *f2;
    void *f3;
    void *f4;
    unsigned char f5, f6;
    char pad1[0xe90 - 0x9a2];
    int flag2;
    unsigned char c[32][32];
    unsigned char d[32][32];
    void *g1;
    void *g2;
    int g3, g4, g5, g6, g7, g8, g9, g10;
    void *g11;
    int g12;
    int g13;
    char pad2[0x1c08 - 0x16c8];
    unsigned char h;
    char pad3[0x1c24 - 0x1c09];
    Cell (*p1)[32];
    Cell (*p2)[32];
    Cell (*p3)[32];
    Cell (*p4)[32];
};
extern "C" void fn_802CB64C(Obj *o) {
    o->flag1 = 1;
    o->flag2 = 1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (o->p1) {
                o->p1[i][j].c = 100;
                o->p2[i][j].c = 100;
                o->p3[i][j].c = 100;
                o->p4[i][j].c = 100;
            }
            o->a[i][j] = 0;
            o->c[i][j] = 0;
            o->b[i][j] = 0;
            o->d[i][j] = 0;
        }
    }
    o->f1 = (void *)fn_802C05BC;
    o->f2 = (void *)fn_802C05B4;
    o->f3 = (void *)fn_802C05B0;
    o->f4 = (void *)fn_802C05B8;
    o->f5 = 0;
    o->f6 = 1;
    o->g1 = (void *)fn_802CB630;
    o->g2 = (void *)fn_802CB640;
    o->g3 = 0;
    o->g4 = 0;
    o->g5 = 0;
    o->g6 = 0;
    o->g7 = 0;
    o->g10 = 0;
    o->g8 = 0;
    o->g9 = 0;
    o->g11 = (void *)fn_802CB644;
    o->g13 = 0;
    fn_802CAA50(o);
    o->h = 0;
    if (o->p3) {
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < 32; j++) {
                o->p3[i][j].c = 100;
                o->p4[i][j].c = 100;
            }
    }
}