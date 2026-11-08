#pragma force_active on
#include <types.h>
#include <gf/gf_shutdown_manager.h>
extern "C" u32 NETCalcCRC32(void*, s32);
extern "C" u8 fn_8004EAD4(void*);
extern "C" void* g_GameGlobal;
struct Lbl804953A0 { u32 unk0, unk4; u8 unk8, unk9, unkA, unkB; };
extern "C" Lbl804953A0 lbl_804953A0;
struct Obj {
 char pad0[0xA0]; s32 a0; char pad_a4[0x4C]; s32 f0; s32 f4;
 u8 f8 : 1; u8 rest : 7; u8 pad_f9; u8 fa; char pad_fb[4]; s32 f100; s32 f104;
 char pad_108[4]; s32 f10c; s32 f110;
};
extern "C" s32 fn_80032F38(Obj* self, s32 idx, u8 arg2) {
 if (idx >= 3) return 0;
 if (self->f10c == 0 || self->f110 == 0) return 0;
 if (self->f0 != 0) return 0;
 s32 flags = fn_8004EAD4(g_GameGlobal);
 if ((flags & (1 << idx)) == 0) {
  self->f0 = 0; self->a0 = 3; return 1;
 }
 s32 ptr;
 s32 size;
 size = self->f110;
 ptr = self->f10c;
 u32 crc = NETCalcCRC32((void*)ptr, size - 4);
 *(s32*)(size + ptr - 4) = (s32)crc;
 self->f0 = 3;
 self->f4 = 0;
 self->f8 = 0;
 self->f100 = 0;
 self->fa = arg2;
 self->f104 = idx;
 self->a0 = 0;
 lbl_804953A0.unk8 = 0;
 g_gfShutdownManager.unkC = 0;
 return 1;
}