#include <types.h>
#pragma force_active on
typedef struct { unsigned short unk00; char pad02[0x1E]; unsigned char unk20; } Info;
typedef struct { unsigned short unk00; char pad02[0x1E]; unsigned char unk20; char pad21[0x243]; unsigned int unk264; Info *unk268; } Node;
typedef struct { s32 unk00; s32 unk04; Node *node; s32 pad0C[4]; u32 unk1C; s32 unk20; s32 unk24; u16 unk28; } Obj;
extern s32 fn_803B722C(void *, u32, u32, s32 *, s32 *);
extern void fn_803B9BC8(Obj *, s32, s32);
extern s32 fn_803C0080(Info *, void *, u32, u16, u32, s32 *, s32);

static inline u32 BlockCount(Info *v, u32 p)
{
    return (p >> v->unk20) + ((p & (v->unk00 - 1)) ? 1 : 0);
}

s32 fn_803B9F7C(Info *arg0, Obj *self, void *buffer, u32 length, s32 *bytesRead)
{
 s32 spC; s32 sp8; s32 r;
 Node *node; Info *info;
 u32 size; u32 pos; u32 avail; u32 a; u32 b;
 *bytesRead=0; spC=0;
 r=fn_803B722C((u8 *)self->node+4,self->unk24,length,&self->unk20,&spC);
 if(r!=0)return r;
 if((u32)(self->unk20+0x10000)==0xFFFF) {
  node=self->node; size=node->unk264; info=(self==0)?0:node->unk268;
  a = BlockCount(info, self->unk1C);
  b = BlockCount(info, size);
  if(a != b) self->unk20=-1;
  self->unk1C=size;
  info=(self==0)?0:self->node->unk268;
  self->unk24=self->unk1C>>info->unk20;
  self->unk28=self->unk1C&(info->unk00-1);
  return 0x1C;
 }
 avail=(u32)spC<<arg0->unk20;
 if(length>avail)length=avail;
 node=self->node; pos=self->unk1C; size=node->unk264;
 if((u32)(pos+length)>size) {
  u16 blk=arg0->unk00; length=size-pos; length=length-(length&(blk-1));
  if(length<blk)return 0;
 }
 r=fn_803C0080(arg0,buffer,self->unk20,self->unk28,length,&sp8,1);
 if(r!=0&&sp8==0)return r;
 *bytesRead=sp8; fn_803B9BC8(self,sp8,self->unk20);
 return 0;
}
