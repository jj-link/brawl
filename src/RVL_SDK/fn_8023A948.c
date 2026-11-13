#include <types.h>
#include <string.h>
#pragma force_active on
extern u8 lbl_80529CF8[];
extern char lbl_80480D48[];
extern void fn_802319E4(u32,const char *);
extern void fn_80250060(void);
extern void fn_80231FB0(void *,int,int);
extern void fn_80245D40(void);
extern void *fn_8022EFF8(int);
extern void fn_802468B8(void *);
extern void fn_802465B4(void *,void *);
extern void fn_8024629C(void *,void *);
extern void fn_8023F4A8(u8,void *,u8);
void fn_8023A948(void) {
void (*cb)(int);
u8 *base;
void *packet;
if(lbl_80529CF8[0x27C0]>=4) fn_802319E4(0xD0003,lbl_80480D48);
cb=*(void (**)(int))(lbl_80529CF8+0x620);
if(cb) { *(u32 *)(lbl_80529CF8+0x620)=0; cb(0); return; }
if(lbl_80529CF8[0x64E]==0) {
fn_80250060();
*(u16 *)(lbl_80529CF8+0x16A0)=0x12;
*(u16 *)(lbl_80529CF8+0x16A2)=0x800;
*(u16 *)(lbl_80529CF8+0x16A4)=0;
*(u16 *)(lbl_80529CF8+0x169C)=0x12;
*(u16 *)(lbl_80529CF8+0x169E)=0x800;
*(u16 *)(lbl_80529CF8+0x16A6)=0;
lbl_80529CF8[0x64E]=2;
lbl_80529CF8[0x64F]=4;
if(lbl_80529CF8[0x64F]!=4) {
lbl_80529CF8[0x64E]=0;
lbl_80529CF8[0x64F]=4;
fn_80231FB0(lbl_80529CF8+0x574,1,1);
fn_80245D40();
} else {
fn_80231FB0(lbl_80529CF8+0x574,1,1);
packet=fn_8022EFF8(2);
if(packet) fn_802468B8(packet);
}
base=lbl_80529CF8;
memcpy(base+0x648,base+0x648,3);
if(base[0x64E]!=0 && base[0x64E]!=1) {
packet=fn_8022EFF8(2);
if(packet) fn_802465B4(packet,base+0x648);
}
base=lbl_80529CF8;
if(base && base[0x64E]!=0 && base[0x64E]!=1) {
void *packet2=fn_8022EFF8(2);
if(packet2) {
if(lbl_80529CF8!=base) {
memset(base,0,0x20);
strncpy((char *)base,(char *)lbl_80529CF8,0x1F);
}
fn_8024629C(packet2,base);
}
}
fn_8023F4A8(lbl_80529CF8[0x20],lbl_80529CF8+0x22,lbl_80529CF8[0x21]);
}
}
