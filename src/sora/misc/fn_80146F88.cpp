#pragma force_active on
typedef unsigned char u8;
extern u8 lbl_805A0418[8];
extern "C" int fn_80146F88(int arg0, u8 arg1) {
 u8* p = &lbl_805A0418[(arg0 & 255)*2];
 p[1] = arg1;
 int sum=0;
 for(int i=0;i<4;++i) {
  lbl_805A0418[i*2]=sum;
  sum+=lbl_805A0418[i*2+1];
 }
 return sum;
}