#pragma force_active on
typedef signed int s32; typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef unsigned int u32;
extern void fn_80389178(s32,u8); extern void fn_80389180(s32,s32,u32); extern void fn_8038918C(s32,s32); extern s32 fn_8038919C(s32); extern void fn_80389194(s32,u8); extern void fn_803886C8(s32,s32,s32); extern void fn_8038866C(s32,s32,s32); extern s32 fn_8035A590(s32); extern s32 fn_8035A598(s32,s32); extern u16 SONtoHs(u16); extern void *memcpy(void*,const void*,s32); extern s32 strlen(const char*);
s32 fn_8038B3B0(s32 self,s32 obj,u8 *data,s32 len,s32 arg4) {
 s32 orig_len=len; u8 flag=*data; s32 spC; u16 spA; u16 sp8; s32 i,count,elem,type,r,l,val; char *p1;
 fn_80389178(obj,flag); data+=5; len-=5;
 if(flag&0x10){data+=2;len-=2;}
 if(flag&2){memcpy(&spC,data,4);data+=4;len-=4;}else spC=0;
 if(flag&0x20){memcpy(&sp8,data,2);data+=2;len-=2;}else sp8=*(u16*)(self+0x6AC);
 fn_80389180(obj,spC,sp8);
 if(flag&8){memcpy(&spC,data,4);data+=4;len-=4;fn_8038918C(obj,spC);}
 if(flag&0x40){
  count=fn_8035A590(*(s32*)(self+8));i=0;
  while(i<count){
   elem=fn_8035A598(*(s32*)(self+8),i);type=*(s32*)(elem+4);
   switch(type){
   case 1: fn_803886C8(obj,*(s32*)elem,*data);data++;len--;break;
   case 2: memcpy(&spA,data,2);r=SONtoHs(spA);fn_803886C8(obj,*(s32*)elem,r&0xFFFF);data+=2;len-=2;break;
   case 0:
    if(arg4){val=*data;data++;len--;}else val=0xFF;
    if(val==0xFF){fn_8038866C(obj,*(s32*)elem,(s32)data);l=strlen((char*)data);r=l+1;data+=r;len-=r;}
    else fn_8038866C(obj,*(s32*)elem,*(s32*)(self+val*4+0x84));
    break;
   default: break;
   }
   i++;
  }
  fn_80389194(obj,(u8)(fn_8038919C(obj)|1));
 }
 if(flag&0x80){
  while(*(s8*)data!=0&&len>0){
   p1=(char*)data;l=strlen(p1);r=l+1;data+=r;len-=r;
   fn_8038866C(obj,(s32)p1,(s32)data);
   l=strlen((char*)data);r=l+1;data+=r;len-=r;
  }
  len--;fn_80389194(obj,(u8)(fn_8038919C(obj)|2));
 }
 r=fn_8038919C(obj);if(!(flag&0xC0)&&(r&3))fn_80389194(obj,(u8)(r&0xFC));
 return orig_len-len;
}