#pragma force_active on
#include <types.h>
struct Pair { u32 a; u32 b; };
struct AiFighterState {
 char pad0[0x60]; f32 value60; char pad64[0x20]; f32 value84;
 char pad88[0x2C]; s32 valueB4; char padB8[0x102]; u8 value1BA;
};
struct AiScript { char pad0[0x78]; u16 command; };
struct AiInput {
 char pad0[0x42]; s8 fighterId; char pad43[1]; AiScript* script;
 char pad48[0x2D]; u8 counter75; char pad76[0x9D]; u8 value113;
 char pad114[2]; u16 flags116;
};
struct AiConstantPool {
 f32 pad0[4]; f32 value10; f32 pad14[2]; f32 value1C;
 f32 pad20; f32 value24; char pad28[0x1D4]; f32 value1FC;
};
struct AiManager { char pad0[0x36C]; f32 value36C; };
extern "C" {
extern const AiConstantPool lbl_27_rodata_2CF0;
extern AiManager* g_aiMgr;
AiFighterState* fn_27_1F1F58(s8*);
Pair fn_27_20BDE8(AiFighterState*);
s32 fn_27_20B568(AiFighterState*);
void fn_27_20DB40(AiScript*, u32, s8*, u32, u32);
f32 fn_27_20BCBC(AiFighterState*, void*, f32);
u32 fn_27_21DC0C(void*, u32, void*, void*, u16, AiScript*, u32);
}
extern "C" s32 fn_27_1FE5A4(AiInput* self) {
 const AiConstantPool* constants = &lbl_27_rodata_2CF0;
 AiFighterState* fighterState = fn_27_1F1F58(&self->fighterId);
 if (fighterState->value1BA == 5 && fighterState->valueB4 != 0x44 &&
     self->script->command != 0x2050 && (self->flags116 & 2)) {
  self->counter75 += 1;
  if (self->counter75 > 4) {
   Pair copy;
   Pair limits = fn_27_20BDE8(fighterState);
   copy = limits;
   if (fn_27_20B568(fighterState) != 0 ||
       fighterState->value60 + constants->value10 * fighterState->value84 > *(f32*)&copy.b - constants->value24) {
    s8 command[8]; command[0] = -1;
    fn_27_20DB40(self->script, 0x2050, command, 0, 0);
   }
   self->counter75 = 0;
  }
 } else { self->counter75 = 0; }
 if (self->script->command == 0) {
  s8 command[4]; command[0] = -1;
  fn_27_20DB40(self->script, (u16)fn_27_21DC0C((char*)self + 0x90, 0, (char*)self + 0x42,
    (char*)self + 0x110, self->flags116, self->script, self->value113 == 0x1A), command, 0, 0);
  if (self->script->command == 0x2040 &&
      fn_27_20BCBC(fighterState, (char*)fighterState + 0x5C,
      *(f32*)((char*)fighterState + 0xA0)) < constants->value1FC &&
      fighterState->value60 > constants->value1C + g_aiMgr->value36C) {
   s8 otherCommand = -1;
   fn_27_20DB40(self->script, 0x2010, &otherCommand, 0, 0);
  }
 }
 return 1;
}