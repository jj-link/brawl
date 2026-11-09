#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct Self {
 s32 state; s32 list; u8 pad8[0x488-8];
 void (*cb)(struct Self *, s32, s32, s32);
 u8 pad48c[0x494-0x48c]; s32 cbArg;
 u8 pad498[0x6b4-0x498]; s32 sock; s32 time;
};
struct From { u16 family; u16 port; u32 addr; };
extern s32 CanReceiveOnSocket(s32);
extern s32 closesocket(s32);
extern s32 fn_8035A590(s32);
extern s32 *fn_8035A598(s32,s32);
extern void fn_8035A5C8(s32,s32 *);
extern u32 fn_8035D728(void);
extern u32 fn_80388958(s32);
extern u16 fn_80388968(s32);
extern s32 fn_803890B0(struct Self *,u32,u16);
extern void fn_80389178(s32,s32);
extern s32 fn_803891A4(void);
extern s32 recvfrom(s32,void *,s32,s32,struct From *,s32 *);
extern s32 lbl_805A1128;
static inline s32 find(struct Self *self, u32 addr, u16 port) {
 s32 count=fn_8035A590(self->list);
 s32 obj;
 s32 idx;
 for(idx=0;idx<count;idx++) {
  obj=*fn_8035A598(self->list,idx);
  if(addr==fn_80388958(obj) && port==fn_80388968(obj)) return idx;
 }
 return -1;
}
s32 fn_8038D150(struct Self *self) {
 s32 len; s32 id; struct From from;
 __declspec(align(32)) u8 buf[0x5db];
 s32 count; u32 addr; u16 port; s32 idx; s32 obj;
 len=8;
 while (CanReceiveOnSocket(self->sock)!=0) {
  if (recvfrom(self->sock,buf,0x5db,0,&from,&len)!=-1) {
   if(find(self,from.addr,from.port)==-1) {
    obj=fn_803890B0(self,from.addr,from.port);
    if(fn_803891A4()!=0) return 5;
    fn_80389178(obj,0x11);
    id=obj;
    fn_8035A5C8(self->list,&id);
    self->cb(self,0,id,self->cbArg);
   }
  }
 }
 if ((u32)(fn_8035D728()-self->time)>0x7d0) {
  closesocket(self->sock); self->sock=-1; self->state=1;
  self->cb(self,3,lbl_805A1128,self->cbArg);
 }
 return 0;
}