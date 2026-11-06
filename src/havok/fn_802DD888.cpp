#pragma force_active on
#pragma use_lmw_stmw on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node { u16 a,b,type,count,flags; };
struct Sub { char pad[0x58]; void* p; };
struct Info { char pad[0x9c]; int flag; };
struct Stats { char pad[0xc]; int a,b,c; Info* info; void update(int x,int y,int z) { a-=x; b-=y; c-=z; } };
struct Counts { char pad[0x14]; u16 a,b,c; };
struct Owner { char pad[8]; Stats* stats; char pad2[8]; Sub* x; Sub* y; char pad3[0xc]; Counts* counts; };
struct Obj { char pad[0xc]; u8* indices; int count; char pad2[0x14]; Owner* owner; Node* node; };
extern "C" void fn_802DA368(void*,int);
extern "C" void* fn_802DA430(void*,int);
extern "C" void fn_802EA884(void*);
extern "C" void fn_802F58CC(void*,void*,void*,int);
extern "C" void fn_802DD888(Obj* obj,int index) {
 int x=0,y=0,z=0;
 u8 n=obj->indices[index];
 obj->indices[index]=0xff;
 Node* old=obj->node;
 if ((int)old->type==2) { y=4; x=0x20; z=1; }
 fn_802DA368(old,n);
 Node* node=obj->node;
 u8* entry=(u8*)(((u32)node+0x37)&~15)+(node->count<<5)+n*0x14;
 entry[0xf]&=~2;
 obj->node=(Node*)fn_802DA430(obj->node,1);
 for(int i=obj->count-1;i>=0;--i) {
  u8 v=obj->indices[i];
  if(v!=0xff && (int)v>(int)n) obj->indices[i]=v-1;
 }
 Owner* owner=obj->owner;
 if(owner->stats->info->flag) {
  fn_802EA884(owner->x->p);
  fn_802EA884(obj->owner->y->p);
 }
 owner=obj->owner;
 int c=z+1,b=y+4,a=x+0x30;
 owner->stats->update(a,b,c);
 Counts* counts=owner->counts;
 if(counts) {
  int cc=counts->c-c;
  int cb=counts->b-b;
  int ca=counts->a-a;
  counts->c=cc;
  counts->a=ca;
  counts->b=cb;
 }
 node=obj->node;
 if(old!=node) fn_802F58CC(obj->owner,old,node,node->b);
 obj->node->flags|=5;
}