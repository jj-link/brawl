#pragma force_active on
typedef unsigned char u8;
struct GG { char pad[0x1c]; struct D* d; };
struct D { char p0[2]; u8 u2; u8 u3; u8 u4; u8 u5; u8 u6; u8 u7; };
struct S { char pad[0x66c]; u8 a; u8 b; u8 c; u8 d; u8 e; u8 f; u8 g; u8 h; };
extern GG* g_GameGlobal;
extern "C" void fn_80050294();
extern "C" void fn_18_479C(S* s) {
    D* d = g_GameGlobal->d;
    switch (s->a) {
    case 0: d->u2 = 0; break;
    case 2: d->u2 = 2; break;
    case 1: d->u2 = 1; break;
    }
    bool ch = false;
    switch (s->c) {
    case 0: if (d->u5 != 0) { d->u5 = 0; ch = true; } break;
    case 1: if (d->u5 != 2) { d->u5 = 2; ch = true; } break;
    case 2: if (d->u5 != 1) { d->u5 = 1; ch = true; } break;
    }
    if (ch) fn_80050294();
    d->u3 = s->b;
    d->u6 = s->d;
    d->u7 = s->e;
    d->u4 = s->h;
}