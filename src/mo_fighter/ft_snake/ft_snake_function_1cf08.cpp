#pragma force_active on
struct V3 { int x, y, z; };
struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    V3 pos;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    Flags flags;
};
struct Inner;
#define D1(n) virtual void n##a(); 
#define D4(n) D1(n##0) D1(n##1) D1(n##2) D1(n##3)
#define D16(n) D4(n##0) D4(n##1) D4(n##2) D4(n##3)
struct M64 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void f1c(int, int);
    D4(b0) D4(b1) D4(b2)
    virtual void f50(int);
};
struct M70 { D16(c) D16(d) virtual void e0(); virtual void e1(); virtual void f90(int, Inner*); };
struct M54 { D16(c) D16(d) D16(e) D16(f) D16(g) D16(h) virtual void i0(); virtual void i1(); virtual void i2(); virtual void f194(int, int, int); };
struct M0c { D16(c) D16(d) virtual void f88(int); };
struct Acc { char pad[0xc]; M0c* m0c; char p2[0x54-0x10]; M54* m54; char p3[0x64-0x58]; M64* m64; char p4[0x70-0x68]; M70* m70;
    M64& get64() { return *m64; } };
struct Par { char pad[0x1c]; float a; float b; };
struct Ref { char pad[4]; int v; };
struct Inner { char p[0xd8]; Acc* acc; };
struct Object2 { char pad[0x60]; Inner* inner; char p[0xbc-0x64]; Ref* r; char q[0x221c-0xc0]; Par* par; };
extern "C" {
extern const float lbl_122_rodata_F0;
extern const float lbl_122_rodata_F8;
V3* fn_122_D580(V3*, float, float, float);
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);

void fn_122_1CF08(Object2* object, int team, int parameter, int resource) {
    V3 position;
    fn_122_D580(&position, lbl_122_rodata_F0, lbl_122_rodata_F0, lbl_122_rodata_F0);
    Param p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.pos, &position, sizeof(position));
    p.facing = lbl_122_rodata_F0;
    p.parameter = parameter;
    p.reserved2 = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved3 = 0;
    p.motion = 0x35f;
    p.reserved4 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(object, &p);
    object->inner->acc->get64().f1c(object->par->a + object->par->b / lbl_122_rodata_F8, 0x10000006);
    Inner* in = object->inner;
    in->acc->m70->f90(0, in);
    object->inner->acc->m64->f50(0x12000000);
    object->inner->acc->m54->f194(3, 0xc, 1);
    object->inner->acc->m0c->f88(object->r->v);
}
}
