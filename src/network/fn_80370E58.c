#pragma force_active on
typedef struct Context { char pad[0x22c]; int count; } Context;
typedef struct Req { char pad[8]; int flag; char pad2[12]; int field18; } Req;
typedef struct Data { char pad[0x28]; char a[0x1f], b[0x15], c[0x33], d[0x1f], e[0x1f]; char pad2[0x67]; int x,y; } Data;
extern char lbl_8048F908[];
extern void fn_803732E0(Context **,const void *);
extern int fn_80370D6C(Context **,Data **,int);
extern void fn_80372DD8(char *,const char *,unsigned long);
extern void fn_8035D6C4(char *);
extern int fn_8036ED64(Context **,int,void *,Req **,int,int,int,int);
extern int fn_80370B9C(Context **,Req *);
extern int fn_80369034(Context **,int);
static inline int process(Context **ctx, Data *data, int a, int b, int c) {
 Req *req;
 int result = fn_8036ED64(ctx,3,data,&req,a,b,c,(*ctx)->count++);
 if (result) return result;
 result = fn_80370B9C(ctx,req);
 if (result) return result;
 if (req->flag) {
  result = fn_80369034(ctx,req->field18);
  if (result) return result;
 }
 return 0;
}
int fn_80370E58(Context **arg0,char *arg1,char *arg2,char *arg3,char *arg4,char *arg5,int arg6,int arg7,int arg8,int arg9,int arg10) {
 Data *data; int result; int out;
 if ((arg1 == 0 || *(signed char *)arg1 == 0) && (arg3 == 0 || *(signed char *)arg3 == 0) && (arg4 == 0 || *(signed char *)arg4 == 0) && (arg5 == 0 || *(signed char *)arg5 == 0) && arg6 == 0 && (arg2 == 0 || *(signed char *)arg2 == 0)) { fn_803732E0(arg0,lbl_8048F908); return 2; }
 result=fn_80370D6C(arg0,&data,1); if(result) return result;
 if(!arg1) data->a[0]=0; else fn_80372DD8(data->a,arg1,0x1f);
 if(!arg2) data->b[0]=0; else fn_80372DD8(data->b,arg2,0x15);
 if(!arg3) data->c[0]=0; else fn_80372DD8(data->c,arg3,0x33);
 fn_8035D6C4(data->c);
 if(!arg4) data->d[0]=0; else fn_80372DD8(data->d,arg4,0x1f);
 if(!arg5) data->e[0]=0; else fn_80372DD8(data->e,arg5,0x1f);
 data->x=arg6; if(arg7<0) arg7=0; data->y=arg7;
 result=process(arg0,data,arg8,arg9,arg10);
 out=0; if(result) out=result; return out;
}