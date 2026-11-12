#include <types.h>
#pragma force_active on

struct Mode {
    char pad[8];
    u8 f8 : 6; u8 f8b : 2;
    u8 f9a : 3; u8 f9cnt : 3; u8 f9b : 1; u8 f9c : 1;
    u8 fa0 : 1; u8 fa1 : 5; u8 fa2 : 1; u8 fa3 : 1;
    u8 fb0 : 5; u8 fb1 : 1; u8 fb2 : 2;
    u8 fc0 : 1; u8 fc1 : 6; u8 fc2 : 1;
    u8 pad0d;
    u8 fe0 : 3; u8 fe1 : 5;
    char pad0f[4];
    u8 f13; u8 f14; u8 pad15; u8 f16; u8 pad17[2];
    u16 f1a; u8 f1c; char pad1d[3];
    int f20; char pad24[12];
    int f30; int f34; int f38; int f3c;
};
struct Sel {
    char pad[0x2e];
    u8 e0 : 3; u8 e1 : 5;
};

extern "C" {
struct GG { int a; int b; Mode* mode; int c; Sel* sel; };
void fn_8005033C(void*);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_1_3D378();
void fn_8010F960(u16, void*, void*, int);
extern GG* g_GameGlobal;

void fn_1_347F0(void* arg0) {
    Mode* self = g_GameGlobal->mode;
    Sel* input = g_GameGlobal->sel;
    u8* q = (u8*)input;
    fn_8005033C(self);
    self->f8 = 8;
    self->f9a = 1;
    self->f13 = 0;
    self->fe0 = 0;
    self->fc2 = 1;
    self->fa0 = 1;
    self->f20 = 0;
    self->f9b = 0; self->f9c = 1;
    self->fa3 = 0; self->fa2 = 1;
    self->fc0 = 0;
    self->fb1 = 0;
    self->f16 = 0;
    self->f34 = 0; self->f30 = 0; self->f38 = 0; self->f3c = 0;
    self->f1a = 0x38;
    self->f1c = input->e0;
    self->fe0 = input->e0;
    self->f14 = 3;
    u8* p = (u8*)self;
    int count = 0;
    int n = 0;
    do {
        if (q[0xB9] == 0) {
            p[0x99] = 0;
            u8 k = q[0xB8];
            p[0x98] = k;
            p[0x9C] = 1;
            p[0xA3] = 0;
            int color = q[0xBD];
            int kind = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(k);
            p[0x9D] = kind == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(kind, color);
            ++count;
            p[0x9E] = q[0xBD];
            p[0xB0] = q[0xD0];
            p[0x9F] = q[0xBF];
            p[0x9A] = n;
        } else {
            p[0x99] = 3;
        }
        ++n;
        q += 0x5C;
        p += 0x5C;
    } while (n < 2);
    self->f9cnt = count;
    ((u8*)self)[0x151] = 3;
    ((u8*)self)[0x1AD] = 3;
    if (((u8*)arg0)[0x19]) {
        ((u8*)arg0)[0x19] = 0;
        fn_1_3D378();
    }
    fn_8010F960(self->f1a, (u8*)self + 0x1c, (u8*)self + 0x5c, 0);
}
}
