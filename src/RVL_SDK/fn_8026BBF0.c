#include <types.h>
#pragma force_active on
void fn_8026BBF0(u8 *arg0, s32 *arg1, s32 arg2)
{
 s32 buf[64];
 s32 i;
 s32 x7,x0,x6,x1,x5,x2,x4,x3;
 s32 S07,S16,D07,D25,D16,S25,S34,D34,U,A,B,W,E,C,M1,M2,T1,F,FS,T2,T3,T4,R5,R9;
 s32 p7,p0,p6,p1,p5,p2,s07,p3,p4,d07,s16,d16,s25,h,g,s34,d25,d34,a,b,t12,c,f,fs,k,t10,t8,t6,r9,r11;
 s32 *q=buf;
 for(i=0;i<8;i++){
 p7=arg0[7]; p0=arg0[0]; s07=p0+p7; d07=p0-p7;
 p6=arg0[6]; p1=arg0[1]; s16=p1+p6; d16=p1-p6;
 p5=arg0[5]; p2=arg0[2]; s25=p2+p5; d25=p2-p5;
 p4=arg0[4]; p3=arg0[3]; s34=p3+p4; d34=p3-p4;
 a=s07+s34; b=s16+s25; t12=s16-s25; c=s07-s34;
 f=(c+t12)*0x2D41; fs=f>>14;
 q[0]=a+b-0x400;
 q[32]=a-b;q[16]=c+fs;q[48]=c-fs;
 g=d34+d25; k=d25+d16; h=d16+d07;
 t10=(g*0x3B21-h*0x187E)>>14;
 t8=(h*0x3B21+g*0x187E)>>14;
 t6=(k*0x2D41)>>14;
 r9=d07+t6;r11=d07-t6;
 q[8]=r9+t8;q[56]=r9-t8;q[24]=r11-t10;q[40]=r11+t10;
 arg0+=arg2;q++;
 }
 arg0=(u8*)buf;
 for(i=0;i<8;i++){
 x7=*(s32*)(arg0+0x1C);x0=*(s32*)(arg0+0);x6=*(s32*)(arg0+0x18);x1=*(s32*)(arg0+4);
 x5=*(s32*)(arg0+0x14);x2=*(s32*)(arg0+8);x4=*(s32*)(arg0+0x10);x3=*(s32*)(arg0+0xC);
 S07=x0+x7; D07=x0-x7; D16=x1-x6; S16=x1+x6;
 D25=x2-x5; S25=x2+x5; S34=x3+x4; D34=x3-x4;
 A=S07+S34; B=S16+S25; C=S07-S34;
 F=(C+(S16-S25))*0x2D41; FS=F>>14;
 E=D25+D16; U=D34+D25; W=D16+D07;
 arg0+=0x20;
 arg1[0]=A+B;arg1[32]=A-B;arg1[16]=C+FS;arg1[48]=C-FS;
 M1=U*0x22A3; M2=W*0x539F; T1=(U-W)*0x187E;
 T2=(M1+T1)>>14;T3=(M2+T1)>>14;
 T4=(E*0x2D41)>>14;R5=D07-T4;R9=D07+T4;
 arg1[40]=R5+T2;arg1[24]=R5-T2;arg1[8]=R9+T3;arg1[56]=R9-T3;arg1++;
 }
}
