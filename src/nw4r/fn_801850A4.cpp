#pragma force_active on

struct Col16 { unsigned short r, g, b, a; };
struct Vec4 { float x, y, z, w; };

struct Obj50 {
    char pad0[0x18];
    unsigned char base[4];
    unsigned char alt[4];
    int mode;
    char pad24[8];
    float f2C;
    float f30;
    char pad34[0x64 - 0x34];
};

struct Shape {
    char pad[0x10];
    Col16 a;
    Col16 b;
};

class Class_804657A8 {
public:
    virtual void fn_80184E48();
    virtual void fn_801856B4();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_801850A4();
    virtual void fn_80183024();
    virtual void fn_801830B0();
    virtual void fn_80184FCC();
    virtual void fn_80185000();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80185074();
    virtual void fn_8018508C();
    virtual void fn_80182B40();
    virtual void fn_80182BEC();
    virtual void fn_80183164();
    virtual void fn_80183180();
    virtual void fn_80183210();
    virtual void fn_80183228();
    virtual void fn_801832FC();
    virtual void fn_80183374();
    virtual void fn_80183618();
    virtual void fn_8018342C();
    virtual void fn_801852B8(int);
    virtual void fn_80185330();
    char padding04[0x24];
    Shape* f28;
    char pad2C[0xB5 - 0x2C];
    unsigned char fB5;
    char padB6[0xD4 - 0xB6];
    void* fD4;
    unsigned char fD8[4];
    unsigned char fDC[4];
    void* fE0;
    char padE4[0xFA - 0xE4];
    unsigned short fFA;
};

extern "C" {
void fn_801601F8(Obj50* p);
void fn_801854A8(Vec4* out, Class_804657A8* self, Obj50* p);
void fn_8018C464(unsigned int* out, const unsigned char* in, int mode);
void fn_8015FCE0(Obj50* p);
void fn_80185274(Obj50* p, const unsigned int* a, const unsigned int* b);
void fn_80184AF0(unsigned int* out, const Col16& in);
void fn_8015EB14(Obj50* p, const unsigned int* a, const unsigned int* b);
void fn_8015ECF8(Obj50* p);
void fn_801605B0(Obj50* p, void* a, unsigned short b, float c);
void* fn_80160254(void* p, int n);
}

extern "C" void fn_801850A4(Class_804657A8* self) {
    if (self->fD4 == 0 || self->fE0 == 0 || self->f28 == 0) {
        return;
    }
    Obj50 p50;
    Vec4 v40;
    unsigned int o2C, o28, o24, o20;
    unsigned char s1C[4], s18[4];
    unsigned int cA, cB, cC, cD;
    self->fn_8018342C();
    fn_801601F8(&p50);
    fn_801854A8(&v40, self, &p50);
    s1C[0] = self->fD8[0];
    s1C[1] = self->fD8[1];
    s1C[2] = self->fD8[2];
    s1C[3] = self->fD8[3];
    fn_8018C464(&o2C, s1C, self->fB5);
    s18[0] = self->fDC[0];
    s18[1] = self->fDC[1];
    s18[2] = self->fDC[2];
    s18[3] = self->fDC[3];
    fn_8018C464(&o28, s18, self->fB5);
    int mode = 0;
    if (o2C != o28) {
        mode = 2;
    }
    p50.mode = mode;
    fn_8015FCE0(&p50);
    cA = o2C;
    cB = o28;
    fn_80185274(&p50, &cA, &cB);
    Col16 c38 = self->f28->a;
    fn_80184AF0(&o24, c38);
    Col16 c30 = self->f28->b;
    fn_80184AF0(&o20, c30);
    cC = o24;
    cD = o20;
    fn_8015EB14(&p50, &cC, &cD);
    fn_8015ECF8(&p50);
    p50.f2C = v40.x;
    p50.f30 = v40.y;
    fn_801605B0(&p50, self->fD4, self->fFA, v40.y);
    fn_80160254(&p50, -1);
}
