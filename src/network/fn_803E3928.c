#include <revolution/VF/pf_sector.h>
#pragma force_active on
typedef struct { unsigned short unk00; char pad02[0x1E]; unsigned char unk20; char pad21[0x243]; int unk264; int unk268; } Node;
typedef struct { int unk00; int unk04; Node *node; int pad0C[4]; unsigned int unk1C; int unk20; int unk24; unsigned short unk28; } Obj;
extern int fn_803E1494(void *, int, int, void *, int *);
extern void fn_803E3614(void *, int, int);
int fn_803E3928(Obj *self, void *buffer, unsigned length, int *bytesRead) {
 int spC; int sp8; int node; int r;
 *bytesRead=0;
 node = self == 0 ? 0 : self->node->unk268;
 spC=0;
 r=fn_803E1494((char *)self->node+4,self->unk24,length,(char *)self+0x20,&spC);
 if(r!=0) return r;
 if((unsigned int)(self->unk20+0x10000)==0xFFFF) {
  self->unk1C=self->node->unk264;
  if(self==0) node=0; else node=self->node->unk268;
  self->unk24=self->unk1C >> ((Node *)node)->unk20;
  self->unk28=self->unk1C & (((Node *)node)->unk00-1);
  return 0x1C;
 }
 if(length>(unsigned int)(spC << ((Node *)node)->unk20)) length=spC << ((Node *)node)->unk20;
 if((unsigned int)(self->unk1C+length)>(unsigned int)self->node->unk264) {
  length=self->node->unk264-self->unk1C;
  length=length-(length & (((Node *)node)->unk00-1));
  if(length<((Node *)node)->unk00) return 0;
 }
 r=PFSEC_ReadData((void *)node,buffer,self->unk20,self->unk28,length,&sp8,1);
 if(r!=0 && sp8==0) return r;
 *bytesRead=sp8;
 fn_803E3614(self,sp8,self->unk20);
 if((unsigned int)sp8!=(unsigned int)(length-(length & (((Node *)node)->unk00-1)))) return r;
 return 0;
}