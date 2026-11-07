#include <types.h>
#pragma force_active on
typedef struct { u32 flags; u16 a,b,c,d,e,f,g,h; u32 i; u32 rest[9]; } S;
void fn_801F13EC(S *src, S *dst, s32 x, s32 y) {
 u32 xx = (x * 2) & 0xFFFE;
 u32 yy = (y * 2) & 0xFFFE;
 u16 b;
 u32 mode;
 if (src != dst) *dst = *src;
 mode = src->flags & 3;
 dst->a = src->a - xx;
 b = src->b;
 dst->b = b - yy * b / src->c;
 if (src->i == 0 && mode == 0)
  dst->c = src->c - ((yy >> 1) & 0x7FFF);
 else
  dst->c = src->c - yy;
 dst->f = src->f - xx;
 if (mode == 1)
  dst->g = src->g - ((yy * 2) & 0x1FFFE);
 else
  dst->g = src->g - yy;
 dst->d = src->d + x;
 dst->e = src->e + y;
}