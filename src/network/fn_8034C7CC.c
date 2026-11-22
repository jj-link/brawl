#include <types.h>
#pragma force_active on
extern s32 DWC_GetState(void);
extern void fn_80335638(s32, void *, ...);
extern s32 fn_803439D4(u8, u32, u32, u16, void *, s32);
extern void fn_8034F028(void *, void *, s32);
extern s32 strncmp(const char *, const char *, u32);
extern u8 lbl_8048AA60[];
extern char lbl_8059F134;
extern int lbl_805A0FA8;
typedef struct Hdr {
char id[4]; u32 w4; u8 b8; u8 b9; u16 h10; u32 w12; u32 w16;
} Hdr;
#define ROTL32(x,n) (((x) << (n)) | ((x) >> (32-(n))))
#define BSWAP32(x) ROTL32((((x)>>8)&0x00FF00FF)|(((x)<<8)&0xFF00FF00),16)
#define BSWAP16(x) ((u16)((((s32)(x)>>8)&~0xFFFF00)|(((x)<<8)&0xFFFF00)))
void fn_8034C7CC(u8 *arg0, s32 arg1) {
u8 *base=lbl_8048AA60;
Hdr hdr;
u8 body[0x7c];
s32 pos=0;
if(DWC_GetState()!=5) {
if(DWC_GetState()!=6 || ((u32)*(u8 *)(lbl_805A0FA8+0x15)!=2 && *(const u8 *)(lbl_805A0FA8+0x15)!=3)) {
fn_80335638(4,base+0x21F8); return;
}
}
while(pos+0x14<=arg1) {
fn_8034F028(&hdr,arg0,0x14);
hdr.w4=BSWAP32(hdr.w4);
hdr.h10=BSWAP16(hdr.h10);
hdr.w16=BSWAP32(hdr.w16);
if(strncmp(hdr.id,&lbl_8059F134,4)!=0) { fn_80335638(8,base+0x2220); return; }
if(hdr.w4!=0xB) { fn_80335638(8,base+0x223C); return; }
fn_8034F028(body,arg0+0x14,hdr.b9);
fn_80335638(0x40,base+0x2260,hdr.b8,hdr.w12,hdr.h10,hdr.w16);
if(fn_803439D4(hdr.b8,hdr.w16,hdr.w12,hdr.h10,body,hdr.b9>>2)==0) return;
pos=pos+hdr.b9+0x14;
}
}
