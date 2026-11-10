#include <types.h>
#pragma force_active on
extern s32 fn_8039C984(s32,u32 **);
extern s32 fn_8039CDB4(s32);
extern void fn_80397DE0(s32,const char *,...);
extern s32 fn_8039832C(void *,s32,u32);
extern s32 lbl_805A1170;
extern char lbl_80491D28[],lbl_80491D3C[];
static s32 counter(u32 *p,u32 *out) {
 if(p[0]!=0x57635466) return -3;
 if(p[6]>1000000) p[6]=1;
 *out=p[6];
 p[6]=p[6]+1;
 return 0;
}
static s32 format(s32 kind,s32 base,u32 val) {
 switch(kind) {
 case 0: fn_80397DE0(base,lbl_80491D28,val); break;
 case 1: fn_80397DE0(base,lbl_80491D3C,val); break;
 default: return -3;
 }
 return 0;
}
s32 fn_8039B870(s32 arg0,void *arg1,u32 *arg2) {
 u32 *p; s32 ret; s32 base;
 ret=fn_8039C984(arg0,&p); if(ret!=0) return ret;
 ret=counter(p,arg2); if(ret!=0) return ret;
 ret=fn_8039CDB4(arg0); if(ret!=0) return ret;
 base=lbl_805A1170+0x800;
 ret=format(arg0,base,*arg2); if(ret!=0) return ret;
 return fn_8039832C(arg1,base,0x109);
}
