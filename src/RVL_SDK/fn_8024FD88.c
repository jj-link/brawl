#pragma force_active on
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct { u32 a,b; } Pair;
typedef struct { char pad[0x3a]; u16 field3a; char pad2[4]; Pair pairs[3]; } Dst;
typedef struct { u16 field0; u8 flag2; u8 pad3; u16 value4; u8 flag6; u8 pad7; Pair data[3]; u8 flag20; u8 pad21; u16 value22; u8 pad24; } Src;
int fn_8024FD88(Dst *dst, Src *src) {
 int r6=1,r7=1,r8=1;
 if(src->flag2){u16 v=src->value4;if(v>=0x30){dst->field3a=v;if(v>0x69b){src->value4=0x69b;dst->field3a=0x69b;}}else{r6=0;src->value4=0x30;}}
 if(src->flag20&&src->value22==0){r8=0;src->value22=0xFFFF;}
 if(src->flag6){if(((u8*)src->data)[1]<=2){dst->pairs[0]=src->data[0];dst->pairs[1]=src->data[1];dst->pairs[2]=src->data[2];}else{r7=0;((u8*)src->data)[1]=1;}}
 {
  int var_r3, var_r0;
  var_r3=0;
  var_r0=0;
  if(r6&&r8&&r7)var_r0=1;
  if(var_r0)var_r3=1;
  if(var_r3)return var_r3;
  src->field0=1;
  if(r6)src->flag2=0;
  if(r8)src->flag20=0;
  if(r7)src->flag6=0;
  src->pad24=0;
  return var_r3;
 }
}