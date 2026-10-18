#pragma force_active on
#pragma opt_propagation off

typedef unsigned int u32;

extern "C" {
struct Constants {
    float v[12];
};
extern const Constants lbl_66_rodata_A8;
extern char lbl_66_data_BDC[];

void fn_66_2BFC(void*);
void* __ct__14snd3DGeneratorFv(void*);
void fn_8009ED40(void*, int, int);
void fn_8009F1FC(void*);
void* memset(void*, int, unsigned long);
}

struct Work {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void set(int, int);

    struct Data {
        u32 x;
        u32 flags;
    }* data;
    u32 mode;
};

struct Bits {
    unsigned mode : 3;
    unsigned rest : 29;
};

#define U(o) (*(u32*)(p + (o)))
#define F(o) (*(float*)(p + (o)))
#define B(o) (*(unsigned char*)(p + (o)))

extern "C" void* fn_66_3964(char* p) {
    const Constants* values = &lbl_66_rodata_A8;

    fn_66_2BFC(p);
    U(0x3c) = (u32)lbl_66_data_BDC;
    __ct__14snd3DGeneratorFv(p + 0x280);
    fn_8009ED40(p + 0x28c, 0, 1);

    U(0x350) = 0;
    U(0x354) = 0;
    U(0x158) = 0;
    B(0x15c) = 0;
    F(0x160) = values->v[0];
    F(0x164) = values->v[0];
    F(0x168) = values->v[0];
    F(0x16c) = values->v[0];
    F(0x170) = values->v[0];
    F(0x174) = values->v[0];
    F(0x178) = values->v[0];
    F(0x17c) = values->v[1];
    F(0x180) = values->v[0];
    F(0x184) = values->v[2];
    B(0x190) = 0;
    F(0x194) = values->v[0];
    F(0x198) = values->v[0];
    F(0x188) = values->v[0];
    B(0x15d) = 0;
    B(0x15e) = 0;
    memset(p + 0x19c, 0, 0xd0);

    Work* w = (Work*)(p + 0xd0);
    U(0x26c) = 0;
    U(0x270) = 0;
    U(0x274) = 0;
    U(0x278) = 0;
    U(0x27c) = 0;

    if (!w)
        return p;

    w->mode = 1;
    w->set(0, 15);
    w->data->flags |= 1;
    w->data->flags |= 16;
    w->data->flags |= 2;
    fn_8009F1FC(p + 0x28c);

    F(0x310) = values->v[0];
    ((Bits*)(p + 0x294))->mode = 1;
    F(0x314) = values->v[0];
    F(0x318) = values->v[0];
    B(0x31c) = 0;
    B(0x31d) = 0;
    U(0x320) = 0;
    U(0x324) = 0;
    return p;
}
