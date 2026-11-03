#include <types.h>
#pragma force_active on
struct Dest { u8 kind, b1, pad2[3], color, costume, level, pad8[3], b; u8 data[12]; u8 stage; };
struct Src { u8 pad[0xb8]; u8 kind; u8 padb9[4]; u8 costume; u8 padbe; u8 level; u8 padc0[16]; u8 stage; };
struct Other { u8 pad[0x24]; int value; };
struct Adv { u8 pad[0x4924]; u8 flags; };
struct Global { u8 pad[12]; Dest* dest; Src* src; u8 pad14[8]; Other* other; u8 pad20[16]; Adv* adv; };
extern "C" {
extern Global* g_GameGlobal;
void fn_8004FF3C(Dest*, int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int,int);
void fn_8004D674(Global*, int, void*);
void fn_1_277B0() {
 int color;
 u8 costume;
 Src* s;
 Dest* d;
 d = g_GameGlobal->dest;
 s = g_GameGlobal->src;
 fn_8004FF3C(d,0);
 color = 0;
 d->b1 = 0;
 d->kind = s->kind;
 d->b = 0;
 costume = s->costume;
 d->costume = costume;
 int kind = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(d->kind);
 color = kind == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(kind,costume);
 d->color = color;
 d->level = s->level;
 d->stage = s->stage;
 if (d->stage != 0x78)
  fn_8004D674(g_GameGlobal, d->stage, d->data);
 g_GameGlobal->other->value = d->level - 1;
 g_GameGlobal->adv->flags &= ~0x40;
}
}