#include <revolution/GX/GXTypes.h>
#pragma force_active on
struct Bits54 { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; };
struct Obj {
 u16 h[8]; float f[4]; u8 pad[0x10]; void* vec; u32 p34,p38,p3c,p40,p44,p48; u16 h4c,h4e,h50,h52; Bits54 a,b,c; u8 pad57; u32 p58,p5c;
};
struct Vec { u8 pad[12]; u32 a,b,c; };
struct Src { u16 h[8]; struct { u16 pad:13; u16 b2:1; u16 b1:1; u16 b0:1; } flags; u8 pad[2]; float f[4]; u16 a,b,c,d; };
extern "C" void fn_80112EBC(Obj* self, Vec* vec, Src* src) {
 self->p48 = (u16)self->p48;
 self->a.b0=0; self->a.b1=1; self->a.b2=0; self->a.b4=0; self->a.b5=0;
 self->b.b1=1; self->b.b2=1; self->b.b3=0; self->b.b4=0; self->b.b6=0;
 self->c.b0=0;
 self->p5c=0;
 self->a.b7 = !src->flags.b0;
 self->b.b4 = src->flags.b2;
 self->b.b5 = src->flags.b1;
 self->h52=0;
 self->a.b3 = self->a.b1;
 self->b.b0 = self->a.b7;
 self->p38=vec->a; self->p3c=vec->b; self->vec=vec; self->p34=vec->c;
 self->p40=self->p38+src->h[0]*8;
 self->p44=self->p3c+src->h[0]*16;
 self->h[0]=src->h[0]; self->h[1]=src->h[1]; self->h[2]=src->h[2]; self->h[3]=src->h[3]; self->h[4]=src->h[4]; self->h[5]=src->h[5]; self->h[6]=src->h[6]; self->h[7]=src->h[7];
 { float x, y; y = src->f[1]; x = src->f[0]; self->f[0] = x; self->f[1] = y; }
 { float x, y; y = src->f[3]; x = src->f[2]; self->f[2] = x; self->f[3] = y; }
 *(u16*)((u8*)self+0x4a)=src->a; self->h4c=src->b; self->h50=src->d; self->p58=0;
}