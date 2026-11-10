#include <types.h>
#pragma force_active on
typedef struct Node { u16 f0, f2; u32 f4; u8 *f8; u32 fC, f10, f14, f18; } Node;
typedef struct Context {
 u16 f0; u8 pad2[10]; u32 fC; s32 f10; u8 pad14[8]; s32 f1C;
 u8 pad20[2]; u8 f22; u8 pad23[0x15]; s32 f38; u32 f3C;
 u8 pad40[0x1FAC-0x40]; u16 flags;
} Context;
typedef struct Outer { u8 pad0[12]; u32 fC, f10; u8 pad14[0x20]; Context *ctx; } Outer;
typedef struct Entry { u32 f0, f4, f8, fC, f10; } Entry;
extern Entry lbl_8041B0E0[];
extern s32 fn_803DF8B4(Context *, u32, u32, u32, u32 *, u32 *);
extern s32 fn_803DFAFC(Context *, u32);
extern s32 fn_803DA454(Context *, s32, Node **, s32 *);
extern void fn_803DA55C(Context *, Node *);
extern s32 fn_803DF760(Context *, Node *, u32);
extern s32 fn_803E0500(Outer *, u32, u32, u32, u32, Node *);
extern s32 fn_803E9178(Context *, u8 *, u32, u32, u16);
extern s32 fn_803E224C(Context *);
static inline s32 flush(Context *ctx, Node *node) {
 u16 i;
 s32 err;
 u32 cur;
 err = 0;
 i = 0;
 cur = node->f18;
 while (i < ctx->f22) {
  s32 ret = fn_803E9178(ctx,node->f8,cur,0,ctx->f0);
  if (ret != 0 && err == 0) err = ret;
  cur += ctx->fC;
  i++;
 }
 return err;
}
s32 fn_803E0728(Outer *arg0, s32 arg1, u32 arg2, u32 *arg3, u32 *arg4, s32 arg5) {
 Context *ctx; u32 start; u32 end; s32 cnt; Node *node; u32 limit; s32 ret; s32 err; u32 i; u32 cur; Entry *entry;
 ctx=arg0->ctx;
 entry=&lbl_8041B0E0[ctx->f1C];
 *arg3=-1; *arg4=-1; end=-1;
 limit=entry->f8;
 ret=fn_803DF8B4(ctx,ctx->f3C,-1,arg1,&start,&end);
 if(ret!=0) return ret;
 if((u32)(start+0x10000)==0xffff) return 0;
 if(arg5!=0) { ret=fn_803DFAFC(ctx,start); if(ret!=0) return ret; }
 ret=fn_803DA454(ctx,-1,&node,&cnt);
 if(ret!=0) return ret;
 ret=fn_803DF760(ctx,node,start);
 if(ret!=0) { fn_803DA55C(ctx,node); return ret; }
 node->f2=0;
 i=start;
 while(i<end) {
  ret=fn_803E0500(arg0,i,arg2,i+1,1,node);
  if(ret!=0) { fn_803DA55C(ctx,node); return ret; }
  if(ctx->flags&4) {
   if((u32)(ctx->f38+0x10000)!=0xffff && ctx->f38!=0 && (ctx->f1C!=2 || end!=(u32)ctx->f10)) ctx->f38--;
  }
  if((u32)(*arg3+0x10000)==0xffff) *arg3=i;
  *arg4=i; arg2++; i++;
 }
 if((u32)(end+0x10000)!=0xffff) {
  ret=fn_803E0500(arg0,end,arg2,limit,1,node);
  if(ret!=0) { fn_803DA55C(ctx,node); return ret; }
  if((u32)(*arg3+0x10000)==0xffff) *arg3=i;
  *arg4=i;
  if((u32)(ctx->f38+0x10000)!=0xffff && ctx->f38!=0 && (ctx->f1C!=2 || end!=(u32)ctx->f10)) ctx->f38--;
 }
 ctx->f3C=end+1; arg0->fC=end; arg0->f10=arg2; *arg4=end;
 err=flush(ctx,node);
 if(err!=0) { fn_803DA55C(ctx,node); return err; }
 fn_803DA55C(ctx,node);
 if(ctx->f1C==2 && (ctx->flags&2) && fn_803E224C(ctx)!=0) { ctx->f38=-1; ctx->flags &= ~4; }
 return 0;
}