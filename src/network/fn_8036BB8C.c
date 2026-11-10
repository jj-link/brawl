#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma force_active on
typedef struct Pair { int a,b; } Pair;
extern int fn_80372E1C(void *,const char *,int);
extern int fn_80372F14(const char *,const char *,char *,int);
extern void fn_80373290(void *,int,const char *);
extern void fn_8036AAF0(void *,int,int);
extern void fn_803708EC(void *,int);
extern void *fn_80370684(void *,int);
extern int fn_8036B548(void *,void *);
extern int fn_8036B96C(void *,void *);
extern void fn_803732E0(void *,const char *);
extern void *fn_8035DFE8(int);
extern int fn_8036ABB0(void *,void *,void *,void *,int);
extern void fn_8036EEE4(void *,void *);
extern void fn_80372DD8(void *,const char *,int);
extern void fn_8035C0B4(char *,int,void *);
extern int fn_803F6150(void *,const char *,int);
extern char lbl_8048EDF8[];
extern char lbl_8059F710[6],lbl_8059F718[6],lbl_8059F720[6],lbl_8059F728[6],lbl_8059F730[5],lbl_8059F738[8];
extern char lbl_8059F6B8[4],lbl_8059F6BC[4],lbl_8059F6C0[5],lbl_8059F6C8[8];
#define ERR(o,c) do { fn_80373290(arg0,c,base+(o)); fn_8036AAF0(arg0,3,1); return 3; } while(0)
int fn_8036BB8C(void *arg0,void *arg1,const char *cmd,void *arg3)
{
 char *ps=*(char **)arg0;
 char *base=lbl_8048EDF8;
 char *pu,*locPtr,*pa;
 char buf[0x200],buf2[0x58],buf3[0x24],loc[0x15],name[0xC];
 Pair pair,copy;
 int r;
 void *ptr;
 if(fn_80372E1C(arg0,cmd,0)!=0){
  if(*(int *)(ps+0x434)==0x106 && *(int *)(ps+0x1A0)!=0){
   fn_803708EC(arg0,*(int *)(ps+0x1A0));
   *(int *)(ps+0x19C)=0; *(int *)(ps+0x1A0)=0;
  }else if(*(int *)(ps+0x434)==0x201){
   if(fn_80372F14(cmd,lbl_8059F710,buf,0x200)!=0) *(int *)(ps+0x1A0)=atoi(buf);
  }
  fn_80373290(arg0,*(int *)(ps+0x434),ps);
  fn_8036AAF0(arg0,4,1);return 4;
 }
 {
 char *p1=(char *)arg1;
 int type=*(int *)(p1+0x14);
 pu=*(char **)(p1+4);
 switch(type){
 case 1:
  if(strncmp(cmd,lbl_8059F718,5)!=0) ERR(0x300,1);
  if(fn_80372F14(cmd,base+0x23C,pu,0x80)==0) ERR(0x300,1);
  if(*(int *)(pu+0x304)!=0){
   r=fn_8036B96C(arg0,pu);if(r!=0)return r;
   *(int *)(p1+0x14)=3;goto done;
  }
  r=fn_8036B548(arg0,pu);if(r!=0)return r;
  *(int *)(p1+0x14)=2;goto done;
 case 3:
  if(strncmp(cmd,lbl_8059F720,5)!=0) ERR(0x300,1);
  if(fn_80372F14(cmd,base+0x264,buf,0x200)==0) ERR(0x330,1);
  *(int *)(ps+0x19C)=atoi(buf);
  if(fn_80372F14(cmd,base+0x270,buf,0x200)==0) ERR(0x330,1);
  *(int *)(ps+0x1A0)=atoi(buf);
  r=fn_8036B548(arg0,pu);if(r!=0)return r;
  *(int *)(p1+0x14)=2;goto done;
 case 2:
  if(strncmp(cmd,lbl_8059F728,5)!=0) ERR(0x300,1);
  if(fn_80372F14(cmd,base+0x360,buf,0x200)==0) ERR(0x330,1);
  *(int *)(ps+0x198)=atoi(buf);
  if(fn_80372F14(cmd,base+0x264,buf,0x200)==0) ERR(0x330,1);
  *(int *)(ps+0x19C)=atoi(buf);
  if(fn_80372F14(cmd,base+0x270,buf,0x200)==0) ERR(0x330,1);
  *(int *)(ps+0x1A0)=atoi(buf);
  if(fn_80372F14(cmd,base+0x254,loc,0x15)==0)loc[0]=0;
  if(fn_80372F14(cmd,lbl_8059F730,ps+0x48C,0x19)==0)ps[0x48C]=0;
  if(*(int *)(ps+0x1A4)!=0)sprintf(name,lbl_8059F6B8,*(int *)(ps+0x1A4));
  else strcpy(name,lbl_8059F6BC);
  if((signed char)pu[0xC2]!=0)locPtr=pu+0xC2;
  else if((signed char)ps[0x12F]!=0){
   sprintf(buf2,lbl_8059F6C0,name,ps+0x12F);locPtr=buf2;
  }else{
   sprintf(buf2,lbl_8059F6C8,name,ps+0x110,ps+0x144);locPtr=buf2;
  }
  sprintf(buf,base+0x1F8,pu+0xA1,base+0x208,locPtr,pu,pu+0x80,pu+0xA1);
  fn_8035C0B4(buf,(int)strlen(buf),buf3);
  if(fn_80372F14(cmd,lbl_8059F738,buf,0x200)==0) ERR(0x330,1);
  if(fn_803F6150(buf3,buf,0x20)!=0) ERR(0x36C,0x108);
  if(*(int *)(ps+0x100)!=0){
   ptr=fn_80370684(arg0,*(int *)(ps+0x1A0));
   *(int *)ptr=*(int *)(ps+0x1A0);
   *(int *)((char *)ptr+4)=*(int *)(ps+0x19C);
  }
  *(int *)(ps+0x1F4)=3;
  pair=*(Pair *)((char *)arg1+0xC);
  if(pair.a!=0){
   pa=(char *)fn_8035DFE8(0x20);
   if(pa==0){fn_803732E0(arg0,base+0x1A8);return 1;}
   memset(pa,0,0x20);
   *(int *)(pa+4)=*(int *)(ps+0x1A0);*(int *)pa=0;
   fn_80372DD8(pa+8,loc,0x15);
   copy=pair;
   r=fn_8036ABB0(arg0,&copy,pa,arg1,0);if(r!=0)return r;
  }
  fn_8036EEE4(arg0,arg1);goto done;
 default:goto done;
 }
 }
done:return 0;
}
