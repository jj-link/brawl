#include <types.h>
#include <string.h>
#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_80480B14[];
extern int fn_803F6150(const void *, const void *, unsigned long);
extern int fn_802466F8(u16, u32);
extern int fn_80245304(u16, int);
extern void fn_80231A14(u32, const char *, u32, u32);

static inline u8 *find_acl(const char *bda)
{
 u8 *p = (u8 *)lbl_80529CF8 + 0x34;
 u32 xx;
 for (xx = 0; xx < 4; xx++, p += 0x11C) {
  if (p[0x119] != 0 && fn_803F6150(p + 8, bda, 6) == 0) return p;
 }
 return 0;
}

void fn_80238FB0(u8 arg0, char *arg1, u8 arg2)
{
 u16 t;
 u8 *ent;
 char *ent2;
 u32 j;
 char *scan2;
 char *src;
 u8 *dst;
 if(arg1) src=arg1; else src=lbl_80529CF8+0x27B4;
 ent = find_acl(src);
 dst=(u8 *)lbl_80529CF8+0x624;
 if(ent) {
  dst[0]=arg0;
  if(arg0==0) {dst[1]=arg2; memcpy(dst+2,src,6); ent[0x11A]=arg2;}
  if(arg1) {
   t=*(u16 *)(ent+0x10E);
   j=0; scan2=lbl_80529CF8+0x34;
   for(;;) {
    if((u8)scan2[0x119]!=0 && fn_803F6150(scan2+8,ent+8,6)==0) {ent2=scan2; break;}
    j++; scan2+=0x11C;
    if(j>=4) {ent2=0; break;}
   }
   if(ent2) {*(u16 *)(ent2+0x10E)=t; if((u8)ent2[0x11A]==0) fn_802466F8(*(u16 *)ent2,t);}
  }
  if(ent[0x11B]==3 && (u8)fn_80245304(*(u16 *)ent,1)!=0) {ent[0x11B]=4; return;}
  if(ent && ent[0x11B]==5) ent[0x11B]=0;
  if(*(void **)(lbl_80529CF8+0x62C)) {
   ((void (*)(u8 *))(*(void **)(lbl_80529CF8+0x62C)))(dst);
   *(void **)(lbl_80529CF8+0x62C)=0;
  }
  if((u8)lbl_80529CF8[0x27C0]>=4) fn_80231A14(0xD0003,lbl_80480B14,dst[1],dst[0]);
 }
}
