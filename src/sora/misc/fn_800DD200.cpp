#include <types.h>
#include <stddef.h>
#pragma force_active on
extern "C" void fn_800E4D28(void*, u8);
extern "C" void fn_800E14A4(void*, int, int);
extern "C" void fn_800E1ED8(void*, int, int);
struct Out { int v; Out() {} Out(int x) : v(x) {} };
struct Ent {
 char pad0[0x18]; int x18; char pad1c[0x2a8-0x1c]; int x2a8; int x2ac;
 char pad2b0[4]; int x2b4; char pad2b8[0x34c-0x2b8]; int x34c; u8 x350;
 char pad351[0x568-0x351]; int x568; int x56c;
 int getKind(Out* o) { new (o) Out(x56c); return x568; }
};
struct Manager { char pad[0x4c]; Ent* entries[7]; u8 map[7]; };
extern "C" void fn_800DD200(Manager* m) {
 s32 i=0; s32 v;
 while(i<7) { v=m->map[i]; if(i!=v) break; i++; }
 if(i<7) {
 Ent** pa=&m->entries[i];
 Ent** pb=&m->entries[v];
 int x=(*pa)->x18;
 fn_800E14A4(*pa,(*pb)->x18,0);
 fn_800E14A4(*pb,x,0);
 x=(*pa)->x2a8; (*pa)->x2a8=(*pb)->x2a8; (*pb)->x2a8=x;
 x=(*pa)->x2ac; (*pa)->x2ac=(*pb)->x2ac; (*pb)->x2ac=x;
 Out sa,sb;
 int ka=(*pa)->getKind(&sa);
 int kb=(*pb)->getKind(&sb);
 fn_800E1ED8(*pa,kb,sb.v);
 fn_800E1ED8(*pb,ka,sa.v);
 u8 j;
 for(j=0;j<7;j++) {
  if(j!=m->map[j]) {
   m->map[j]=j;
   Ent* e=m->entries[j];
   e->x2b4=e->x34c;
   fn_800E4D28(e,e->x350);
  }
 }
 }
}