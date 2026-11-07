#include <types.h>
#include <stddef.h>
#pragma force_active on

extern "C" void fn_800E4D28(void* p, u8 x);
extern "C" void fn_800E14A4(void*, int, int);
extern "C" void fn_800E1ED8(void*, int, int);

struct Out {
    int v;
    Out() {}
    Out(int x) : v(x) {}
};

struct Ent {
    char pad0[0x18];
    int x18;
    char pad1c[0x2a8 - 0x1c];
    int x2a8;
    int x2ac;
    char pad2b0[4];
    int x2b4;
    char pad2b8[0x350 - 0x2b8];
    u8 x350;
    char pad351[0x568 - 0x351];
    int x568;
    int x56c;

    int getKind(Out* o) {
        new (o) Out(x56c);
        return x568;
    }
};

extern "C" void fn_800DD0CC(u8* m, int a, int b) {
    u8 t = (m + a)[0x68];
    (m + a)[0x68] = (m + b)[0x68];
    (m + b)[0x68] = t;
    Ent** pa = (Ent**)(m + a * 4 + 0x4c);
    Ent** pb = (Ent**)(m + b * 4 + 0x4c);

    Ent* e = *pa;
    int v = e->x2b4;
    e->x2b4 = (*pb)->x2b4;
    fn_800E4D28(e, e->x350);
    e = *pb;
    e->x2b4 = v;
    fn_800E4D28(e, e->x350);

    v = (*pa)->x18;
    fn_800E14A4(*pa, (*pb)->x18, 0);
    fn_800E14A4(*pb, v, 0);

    v = (*pa)->x2a8;
    (*pa)->x2a8 = (*pb)->x2a8;
    (*pb)->x2a8 = v;
    v = (*pa)->x2ac;
    (*pa)->x2ac = (*pb)->x2ac;
    (*pb)->x2ac = v;

    Out sa, sb;
    int ka = (*pa)->getKind(&sa);
    int kb = (*pb)->getKind(&sb);
    fn_800E1ED8(*pa, kb, sb.v);
    fn_800E1ED8(*pb, ka, sa.v);
}
