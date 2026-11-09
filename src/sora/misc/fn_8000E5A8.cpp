#pragma force_active off
#include <revolution/GX.h>
extern "C" void* fn_801AC5F4(char*, int);
extern "C" void fn_801B5DC8(void**);
extern "C" void fn_8000D530(void*, char*, unsigned int);
extern "C" unsigned int* fn_801B69B8(void*, unsigned int);
extern "C" void fn_801B601C(unsigned int*, const GXColor*);
extern const float lbl_805A1350;
extern const float lbl_805A1354;
#pragma force_active on
extern "C" void fn_8000E5A8(char* arg0) {
 float f31;
 float f30;
 unsigned char b[8];
 char sp20[0x10];
 struct Local { unsigned char a[8]; void* p; int padding; } local;
 unsigned char* color;
 char* list;
 unsigned int i;
 unsigned short n;
 unsigned int j;
 unsigned int k;
 char* base;
 f30=lbl_805A1350;
 f31=lbl_805A1354;
 base=arg0;
 for(i=0;;i++){
  void* p=fn_801AC5F4(base,i);
  local.p=p;
  if(!p) break;
  if(p){ ((float*)p)[1]=f30; ((float*)p)[2]=f31; }
  local.a[0]=0;local.a[1]=0;local.a[2]=0;local.a[3]=0;
  local.a[4]=0;local.a[5]=0;local.a[6]=0;local.a[7]=0;
  if(local.p){ unsigned char* t=(unsigned char*)local.p; t[20]=0;t[21]=0;t[22]=0;t[23]=0; }
  fn_801B5DC8(&local.p);
 }
 n=*(unsigned short*)(base+0x287a);
 list=base+0x2878;
 color=b+4;
 for(j=0;j<n;j++){
  fn_8000D530(sp20,list,j);
  for(k=0;k<4;k++){
   unsigned int* q=fn_801B69B8(sp20,k);
   if(q){
    b[0]=0;b[1]=0;b[2]=0;b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;
    fn_801B601C(q,(GXColor*)color);
    *q &= 0xFFFFFFFB;
   }
  }
 }
}