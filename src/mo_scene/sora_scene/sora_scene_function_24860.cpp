#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on
extern "C" {
void fn_8005033C(void*);
void fn_80050424(void*);
void fn_80055760(u16,u8);
u8* fn_80055998(u16);
void fn_8010F960(u16,void*,void*,int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
s8 getFighterColorFileNo__6muMenuFiii(int,int);
}
struct Flags { u8 pad[8]; u8 mode:6, low:2; u8 rule:3, count:3, rest:2; };
extern "C" void fn_1_24860(int unused, s32 arg) {
 u8 *obj=(u8*)g_GameGlobal->m_modeMelee;
 u8 *src=(u8*)g_GameGlobal->m_selCharData;
 u8 *sel=(u8*)g_GameGlobal->m_selStageData;
 u8 *rec=(u8*)g_GameGlobal->getGlobalRecordMenuDatap();
 fn_8005033C(obj); fn_80050424(obj);
 ((Flags*)obj)->mode=0;
 ((Flags*)obj)->rule=((u8*)g_GameGlobal->m_setRule)[2];
 if(arg==0) arg=*(u16*)(sel+0x22);
 *(s16*)(obj+0x1a)=arg;
 fn_80055760((u16)arg,sel[0x24]);
 u8 *p=fn_80055998(*(u16*)(obj+0x1a));
 *(u64*)(obj+0x30)=*(u64*)p;
 *(s32*)(obj+0x38)=*(s32*)(p+8);
 *(s32*)(obj+0x3c)=*(s32*)(p+12);
 *(u64*)(obj+0x30)&=*(u64*)(rec+8);
 obj[0x16]=rec[0];
 ((Flags*)obj)->count=0;
 u16 zero=0;
 s8 *dst=(s8*)obj;
 int i=0;
 do {
  if(src[0xb9]!=3) {
   int kind=src[0xb8];
   dst[0x98]=kind;
   dst[0x99]=src[0xb9];
   dst[0xa3]=src[0xc3];
   u8 tmp=src[0xbd];
   int m=exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
   s8 v;
   if(m==0x28) v=0; else v=getFighterColorFileNo__6muMenuFiii(m,tmp);
   dst[0x9d]=v;
   dst[0x9e]=src[0xbd];
   dst[0xb0]=src[0xd0];
   dst[0x9f]=src[0xbf];
   dst[0x9a]=i;
   dst[0xa0]=((Flags*)obj)->count;
   dst[0x9c]=-1;
   *(u16*)(dst+0xba)=zero;
   if(((Flags*)obj)->rule==1) dst[0x9c]=((u8*)g_GameGlobal->m_setRule)[4];
   ((Flags*)obj)->count++;
  }
  i++;
  src+=0x5c;
  dst+=0x5c;
 } while(i<4);
 fn_8010F960(*(u16*)(obj+0x1a),obj+0x1c,obj+0x5c,0);
}