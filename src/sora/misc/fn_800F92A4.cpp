#include <types.h>
#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on
extern "C" {
extern float lbl_805A267C;
void fn_800B8A0C(void*,int);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32,HeapType,u32);
}
extern "C" void fn_800F92A4(char* self) {
 u8 colors[3][4]={{0,0x74,0x62,0},{0x99,0x18,0,0},{0x29,0x24,0x87,0}};
 MuMsg* msg; void* p;
 MuMsg** slot=(MuMsg**)(self+0x334);
 u8* color=colors[0]; u32 k;
 for(k=0;k<3;k++,color+=4){
  msg=create__5MuMsgFUlQ25Heaps8HeapTypeUl(5,(HeapType)0x2A,0x2B);
  if(*slot!=msg){fn_800B8A0C(*slot,1);*slot=msg;}
  (*slot)->allocMsgBuf(0x100,8);
  switch(k){
  case 0:p=*(void**)(self+0x390);p=p?p:((gfFileIOHandle*)(self+0x358))->getBuffer();(*slot)->setMsgData(p);break;
  case 1:p=*(void**)(self+0x394);p=p?p:((gfFileIOHandle*)(self+0x370))->getBuffer();(*slot)->setMsgData(p);break;
  case 2:p=*(void**)(self+0x398);p=p?p:((gfFileIOHandle*)(self+0x388))->getBuffer();(*slot)->setMsgData(p);break;
  }
  {char* q=self;u32 j=0;for(;j<8;j++,q+=0x18){
   (*slot)->attachScnMdlSimple(j,*(nw4r::g3d::ScnMdlSimple**)(*(char**)(q+0x274)+0x10),0,lbl_805A267C);
   (*slot)->setFontColor(j,color[0],color[1],color[2],0xFF);
   (*slot)->setAlignMode(j,MuMsg::Align_Left);
  }}
  ++slot;
 }
 if(*(int*)(self+0xF8)!=0){
  msg=create__5MuMsgFUlQ25Heaps8HeapTypeUl(1,(HeapType)0x2A,0x2B);
  if(*(MuMsg**)(self+0x340)!=msg){fn_800B8A0C(*(MuMsg**)(self+0x340),1);*(MuMsg**)(self+0x340)=msg;}
  (*(MuMsg**)(self+0x340))->allocMsgBuf(0x100,8);
  (*(MuMsg**)(self+0x340))->setMsgData(*(void**)(self+0x344));
  int b[3][2]={{0,0},{0,1},{3,0}};
  int a[3]={0,2,1};
  int k2=0;
  for(;k2<a[*(int*)(self+0xF8)];k2++){
   (*(MuMsg**)(self+0x340))->attachScnMdlSimple(k2,*(nw4r::g3d::ScnMdlSimple**)(*(char**)(self+0x268)+0x10),k2,lbl_805A267C);
   (*(MuMsg**)(self+0x340))->setFontColor(k2,0,0,0,0xFF);
   (*(MuMsg**)(self+0x340))->setAlignMode(k2,MuMsg::Align_Center);
   (*(MuMsg**)(self+0x340))->printIndex(k2,b[*(int*)(self+0xF8)][k2],0);
  }
 }
}
