#include <types.h>
#pragma force_active on
typedef union Vec4 { struct { f32 x,y,z,w; }; double d[2]; } Vec4 __attribute__((aligned(16)));
typedef struct Object { char pad[0x30]; Vec4 vec; } Object;
typedef struct Blob { f32 f0,f4,f8,fC,f10,f14,f18,f1C,f20,f24; Object *v28,*v2C; u32 v30,v34; f32 f38,f3C; u32 v40,v44,v48,v4C,v50; } Blob;
typedef struct Node { u16 kind,pad2,id,pad6; struct Node *next; f32 s1,s2; } Node;
typedef struct Context { u32 a,b,c; } Context;
extern void fn_8029515C(Blob *,u32,u32,Context *);
extern void fn_8028F8F4(f32 *,f32 *,Blob *,Context *);
extern void fn_80293CBC(Node *,Blob *,Context *);
extern void fn_80288BC8(Node *,u16,Blob *,Context *);
static inline void copy_blob(Blob *d,const Blob *s) {
 d->f0=s->f0; d->f4=s->f4; d->f8=s->f8; d->fC=s->fC; d->f10=s->f10; d->f14=s->f14; d->f18=s->f18; d->f1C=s->f1C; d->f20=s->f20; d->f24=s->f24;
 d->v28=s->v28; d->v2C=s->v2C; d->v30=s->v30; d->v34=s->v34; d->f38=s->f38; d->f3C=s->f3C;
 d->v40=s->v40; d->v44=s->v44; d->v48=s->v48; d->v4C=s->v4C; d->v50=s->v50;
}
extern int __cntlzw(unsigned int);
static inline signed char is_kind(Node *p) { return (u8)((u32)__cntlzw((u32)p->kind - 0x16) >> 5); }
void fn_8028D18C(Node * __restrict self,const Blob *src,void *a,void *b,Context *ctx) {
 const Blob *source;
 Object *p;
 Object *q;
 Node *c;
 u16 id;
 Context *cx;
 Blob local __attribute__((aligned(16)));
 Vec4 o1,o2;
 f32 t20[4],t10[4];
 f32 s1,s2;
 source=src; cx=ctx;
 copy_blob(&local,source);
 s1=self->s1; s2=self->s2; c=self->next; id=self->id;
 cx->c-=0x18;
 fn_8029515C(&local,0,0,cx);
 p=*(Object **)((char *)source+0x28); q=*(Object **)((char *)source+0x2c);
 o1=p->vec; o2=q->vec;
 t20[0]=s1*o1.x; t20[1]=s1*o1.y; t20[2]=s1*o1.z; t20[3]=s1*o1.w;
 t10[0]=s2*o2.x; t10[1]=s2*o2.y; t10[2]=s2*o2.z; t10[3]=s2*o2.w;
 p->vec.x=p->vec.x*s1; p->vec.y=p->vec.y*s1; p->vec.z=p->vec.z*s1; p->vec.w=p->vec.w*s1;
 q->vec.x=q->vec.x*s2; q->vec.y=q->vec.y*s2; q->vec.z=q->vec.z*s2; q->vec.w=q->vec.w*s2;
 fn_8028F8F4(t20,t10,&local,cx);
 { signed char flag = is_kind(c); if (((u32)(-(int)flag | (int)flag) >> 31) != 0) fn_80293CBC(c,&local,cx); else fn_80288BC8(c,id,&local,cx); }
 p->vec.x=o1.x; p->vec.y=o1.y; p->vec.z=o1.z; p->vec.w=o1.w;
 q->vec.x=o2.x; q->vec.y=o2.y; q->vec.z=o2.z; q->vec.w=o2.w;
 fn_8028F8F4((f32 *)&o1,(f32 *)&o2,&local,cx);
}