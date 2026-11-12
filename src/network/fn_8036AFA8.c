#include <types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma force_active on

typedef struct Pair { int a,b; } Pair;

typedef struct {
    u8 pad0;
    u8 family;
    u16 port;
    s32 addr;
} Address;

typedef struct {
    u8 pad[0xC];
    s32 **ref;
} LookupResult;

typedef struct Context {
    unsigned char pad0[0x10C];
    int field10C;
    unsigned char buf110[0x1F];
    unsigned char buf12F[0x15];
    unsigned char buf144[0x33];
    unsigned char buf177[0x1F];
    unsigned char pad196[0x1F4 - 0x196];
    int field1F4;
} Context;

typedef struct Obj {
    unsigned char pad0[0xC2];
    unsigned char buf0C2[0x100];
    unsigned char buf1C2[0x100];
    unsigned char buf2C2[0x41];
    unsigned char pad303;
    s32 field304;
} Obj;

typedef struct Req {
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C;
    void *unk20;
} Req;

extern s16 SOHtoNs(u16);
extern u16 SONtoHs(u16);
extern s32 socket(s32, s32, s32);
extern s32 bind(s32, void *, s32);
extern s32 listen(s32, s32);
extern s32 getsockname(s32, void *, s32 *);
extern s32 fn_8035CD04(s32, s32);
extern s32 fn_8035C620(char *);
extern LookupResult *fn_8035C788(char *);
extern s32 fn_8035C384(s32, void *, s32);
extern s32 fn_8035C658(s32);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern s32 fn_80368C10(void);
extern void fn_803732E0(void *, const char *);
extern void fn_80372DD8(void *, const void *, int);
extern void *fn_8035D6C4(void *);
extern void *fn_8035DFE8(int);
extern s32 fn_8036ED64(Context **, s32, void *, Req **, s32, s32, s32);
extern void fn_8036E9EC(Context **, void *);
extern void fn_8036C3A8(Context **, s32);
extern s32 fn_80369034(Context **, s32);
extern void fn_8035C0B4(const char *, unsigned int, void *);
extern void fn_8036A328(void *, void *, const char *);
extern void fn_8036A384(void *, void *, int);
extern void fn_803709D0(void *, void *, void *, int **);
extern void fn_8037331C(unsigned char *src, void *dst);
extern void fn_8035DA18(int arg0);
extern int fn_8035DA30(int arg0, int arg1);
extern void fn_8035DAA4(signed char *buf, void *dst, unsigned int len, int flag);
extern int fn_80372E1C(void *,const char *,int);
extern int fn_80372F14(const char *,const char *,char *,int);
extern void fn_803708EC(void *,int);
extern void *fn_80370684(void *,int);
extern int fn_8036ABB0(void *,void *,void *,void *,int);
extern void fn_8036EEE4(void *,void *);
extern int fn_803F6150(void *,const char *,int);

extern char lbl_80534808[0x80];
extern char lbl_8059F6B8[4], lbl_8059F6BC[4], lbl_8059F6C0[5];
extern char lbl_8059F6C8[8], lbl_8059F6D0[8], lbl_8059F6D8[7];
extern char lbl_8059F6E0[2], lbl_8059F6E4[7], lbl_8059F6EC[6];
extern char lbl_8059F6F8[8];
extern char lbl_8059F700[8];
extern char lbl_8059F708[7];
extern char lbl_8059F710[6],lbl_8059F718[6],lbl_8059F720[6],lbl_8059F728[6],lbl_8059F730[5],lbl_8059F738[8];

/* 64-byte connection manager host name buffer at the start of the group's .data */
char lbl_8048EDF8[64] = "gpcm.gs.nintendowifi.net";

/* alignment byte between this group's last string and the next string in the
   file's .data; defined after the last function so it follows the strings */
#pragma explicit_zero_data on
__declspec(section ".data") static char pad_8048F183;

int fn_8036AFA8(void *ctx, void *arg1v)
{
    u8 *arg1 = (u8 *)arg1v;
    u8 *self = *(u8 **)ctx;
    Address addr;
    s32 len;
    s32 sock;
    LookupResult *res;

    if (*(s32 *)(self + 0x10C) == 0) {
        sock = socket(2, 1, 0);
        *(s32 *)(self + 0x220) = sock;
        if (sock == -1) {
            fn_80373290(ctx, 5, "There was an error creating a socket.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        if (fn_8035CD04(sock, 0) == 0) {
            fn_80373290(ctx, 5, "There was an error making a socket non-blocking.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        memset(&addr, 0, 8);
        addr.family = 2;
        if (bind(*(s32 *)(self + 0x220), &addr, 8) == -1) {
            fn_80373290(ctx, 5, "There was an error binding a socket.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        if (listen(*(s32 *)(self + 0x220), 5) == -1) {
            fn_80373290(ctx, 5, "There was an error listening on a socket.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        len = 8;
        if (getsockname(*(s32 *)(self + 0x220), &addr, &len) == -1) {
            fn_80373290(ctx, 5, "There was an error getting a socket's addres.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        *(s32 *)(self + 0x224) = addr.port;
    } else {
        *(s32 *)(self + 0x220) = -1;
        *(s32 *)(self + 0x224) = 0;
    }

    sock = socket(2, 1, 0);
    *(s32 *)(self + 0x1F0) = sock;
    if (sock == -1) {
        fn_80373290(ctx, 5, "There was an error creating a socket.");
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }
    if (fn_8035CD04(sock, 0) == 0) {
        fn_80373290(ctx, 5, "There was an error making a socket non-blocking.");
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }
    memset(&addr, 0, 8);
    addr.family = 2;
    if ((unsigned int)(fn_8035C620(lbl_8048EDF8) + 0x10000) == 0xFFFF) {
        res = fn_8035C788(lbl_8048EDF8);
        if (res == 0) {
            fn_80373290(ctx, 5, "Could not resolve connection mananger host name.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
        addr.addr = **res->ref;
    } else {
        addr.addr = fn_8035C620(lbl_8048EDF8);
    }
    addr.port = SOHtoNs(0x74CC);
    if (fn_8035C384(*(s32 *)(self + 0x1F0), &addr, 8) == -1) {
        s32 err = fn_8035C658(*(s32 *)(self + 0x1F0));
        if (err != -6 && err != -0x1A && err != -0x4C) {
            fn_80373290(ctx, 5, "There was an error connecting a socket.");
            fn_8036AAF0(ctx, 3, 1);
            return 3;
        }
    }
    *(s32 *)(arg1 + 0x14) = 1;
    *(s32 *)(self + 0x1F4) = 1;
    return 0;
}

s32 fn_8036B2F4(Context **arg0, u8 *arg1, u8 *arg2, u8 *arg3,
                u8 *arg4, const char arg5[0x100], const char arg6[0x100], u8 *arg7,
                s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12)
{
    Context *ctx;
    Obj *obj;
    Req *req;
    s32 ret;

    ctx = *arg0;

    if (ctx->field1F4 == 4) {
        ret = fn_80368C10();
        if (ret != 0)
            return ret;
    }

    if (ctx->field1F4 != 0) {
        fn_803732E0(arg0, "Invalid connection.");
        return 2;
    }

    switch (arg8) {
    case 1:
        ctx->field10C = 1;
        break;
    case 0:
        ctx->field10C = 0;
        break;
    default:
        fn_803732E0(arg0, "Invalid firewall.");
        return 2;
    }

    fn_80372DD8(ctx->buf110, arg1, 0x1F);
    fn_80372DD8(ctx->buf12F, arg2, 0x15);
    fn_80372DD8(ctx->buf144, arg3, 0x33);
    fn_80372DD8(ctx->buf177, arg4, 0x1F);
    fn_8035D6C4(ctx->buf144);

    obj = fn_8035DFE8(0x308);
    if (obj == 0) {
        fn_803732E0(arg0, "Out of memory.");
        return 1;
    }

    memset(obj, 0, sizeof(Obj));
    obj->field304 = arg9;
    if (arg5[0] && arg6[0]) {
        fn_80372DD8(obj->buf0C2, arg5, 0x100);
        fn_80372DD8(obj->buf1C2, arg6, 0x100);
    }
    if (arg7 != 0)
        fn_80372DD8(obj->buf2C2, arg7, 0x41);

    ret = fn_8036ED64(arg0, 0, obj, &req, arg10, arg11, arg12);
    if (ret != 0)
        return ret;

    ret = fn_8036AFA8(arg0, req);
    if (ret != 0) {
        req->unk1C = ret;
        fn_8036E9EC(arg0, req);
        fn_8036C3A8(arg0, 0);
        return ret;
    }

    if (req->unk8 != 0) {
        ret = fn_80369034(arg0, req->unk18);
        if (ret != 0)
            return ret;
    }

    return 0;
}

int fn_8036B548(void **arg0, char *arg1)
{
    char *p = *arg0;
    int i;
    char *password;
    char *user;
    int *result;
    char prefix[12];
    char digest[36];
    char name[84];
    char buffer[512];

    for (i = 0; i < 32; i++) {
        arg1[0x80 + i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[(unsigned int)rand() % 62];
    }
    *(arg1 + i + 0x80) = 0;
    if (arg1[0x1c2])
        password = arg1 + 0x1c2;
    else
        password = p + 0x177;
    fn_8035C0B4(password, strlen(password), arg1 + 0xa1);
    if (*(int *)(p + 0x1a4))
        sprintf(prefix, lbl_8059F6B8, *(int *)(p + 0x1a4));
    else
        strcpy(prefix, lbl_8059F6BC);
    if (arg1[0xc2])
        user = arg1 + 0xc2;
    else if (p[0x12f]) {
        sprintf(name, lbl_8059F6C0, prefix, p + 0x12f);
        user = name;
    } else {
        sprintf(name, lbl_8059F6C8, prefix, p + 0x110, p + 0x144);
        user = name;
    }
    sprintf(buffer, "%s%s%s%s%s%s", arg1 + 0xa1, "                                                ", user, arg1 + 0x80, arg1, arg1 + 0xa1);
    fn_8035C0B4(buffer, strlen(buffer), digest);
    if (*(int *)(p + 0x100)) {
        fn_803709D0(arg0, p + 0x110, p + 0x144, &result);
        if (result) {
            *(int *)(p + 0x19c) = result[1];
            *(int *)(p + 0x1a0) = result[0];
        }
    }
    fn_8036A328(arg0, p + 0x210, lbl_8059F6D0);
    fn_8036A328(arg0, p + 0x210, "\\challenge\\");
    fn_8036A328(arg0, p + 0x210, arg1 + 0x80);
    if (arg1[0xc2]) {
        fn_8036A328(arg0, p + 0x210, "\\authtoken\\");
        fn_8036A328(arg0, p + 0x210, arg1 + 0xc2);
    } else if (p[0x12f]) {
        fn_8036A328(arg0, p + 0x210, "\\uniquenick\\");
        fn_8036A328(arg0, p + 0x210, p + 0x12f);
    } else {
        fn_8036A328(arg0, p + 0x210, lbl_8059F6D8);
        fn_8036A328(arg0, p + 0x210, p + 0x110);
        fn_8036A328(arg0, p + 0x210, lbl_8059F6E0);
        fn_8036A328(arg0, p + 0x210, p + 0x144);
    }
    if (*(int *)(p + 0x19c)) {
        fn_8036A328(arg0, p + 0x210, "\\userid\\");
        fn_8036A384(arg0, p + 0x210, *(int *)(p + 0x19c));
    }
    if (*(int *)(p + 0x1a0)) {
        fn_8036A328(arg0, p + 0x210, "\\profileid\\");
        fn_8036A384(arg0, p + 0x210, *(int *)(p + 0x1a0));
    }
    fn_8036A328(arg0, p + 0x210, "\\partnerid\\");
    fn_8036A384(arg0, p + 0x210, *(int *)(p + 0x1a4));
    fn_8036A328(arg0, p + 0x210, "\\response\\");
    fn_8036A328(arg0, p + 0x210, digest);
    if (*(int *)(p + 0x10c) == 1)
        fn_8036A328(arg0, p + 0x210, "\\firewall\\1");
    fn_8036A328(arg0, p + 0x210, lbl_8059F6E4);
    fn_8036A384(arg0, p + 0x210, (short)SONtoHs((unsigned short)*(int *)(p + 0x224)));
    fn_8036A328(arg0, p + 0x210, "\\productid\\");
    fn_8036A384(arg0, p + 0x210, *(int *)(p + 0x484));
    fn_8036A328(arg0, p + 0x210, "\\gamename\\");
    fn_8036A328(arg0, p + 0x210, lbl_80534808);
    fn_8036A328(arg0, p + 0x210, "\\namespaceid\\");
    fn_8036A384(arg0, p + 0x210, *(int *)(p + 0x488));
    fn_8036A328(arg0, p + 0x210, "\\sdkrevision\\");
    fn_8036A384(arg0, p + 0x210, 3);
    fn_8036A328(arg0, p + 0x210, lbl_8059F6EC);
    fn_8036A328(arg0, p + 0x210, lbl_8059F6F8);
    return 0;
}

int fn_8036B96C(void **arg0, unsigned char *arg1) {
    char *p;
    char *base;
    unsigned int i;
    unsigned int len;
    signed char k;
    char converted[0x30];
    struct {
        char out[0x5C];
        char buf[0x4C];
    } buffers;

    base = *(char **)arg0;
    fn_8037331C((unsigned char *)(base + 0x177), converted);
    fn_8036A328(arg0, base + 0x210, "\\newuser\\");
    fn_8036A328(arg0, base + 0x210, lbl_8059F700);
    fn_8036A328(arg0, base + 0x210, base + 0x144);
    fn_8036A328(arg0, base + 0x210, lbl_8059F708);
    fn_8036A328(arg0, base + 0x210, base + 0x110);
    fn_8036A328(arg0, base + 0x210, "\\passwordenc\\");
    fn_8036A328(arg0, base + 0x210, converted);
    fn_8036A328(arg0, base + 0x210, "\\productid\\");
    fn_8036A384(arg0, base + 0x210, *(int *)(base + 0x484));
    fn_8036A328(arg0, base + 0x210, "\\gamename\\");
    fn_8036A328(arg0, base + 0x210, lbl_80534808);
    fn_8036A328(arg0, base + 0x210, "\\namespaceid\\");
    fn_8036A384(arg0, base + 0x210, *(int *)(base + 0x488));
    fn_8036A328(arg0, base + 0x210, "\\uniquenick\\");
    fn_8036A328(arg0, base + 0x210, base + 0x12F);
    if ((signed char)arg1[0x2C2] != 0) {
        len = strlen((const char *)(arg1 + 0x2C2));
        fn_8035DA18(0x79707367);
        p = buffers.buf;
        i = 0;
        while (i < len) {
            k = fn_8035DA30(0, 0xFF);
            *p = k ^ arg1[i + 0x2C2];
            i++;
            p++;
        }
        buffers.buf[i] = 0;
        fn_8035DAA4((signed char *)buffers.buf, buffers.out, len, 1);
        fn_8036A328(arg0, base + 0x210, "\\cdkeyenc\\");
        fn_8036A328(arg0, base + 0x210, buffers.out);
    }
    fn_8036A328(arg0, base + 0x210, "\\partnerid\\");
    fn_8036A384(arg0, base + 0x210, *(int *)(base + 0x1A4));
    fn_8036A328(arg0, base + 0x210, lbl_8059F6EC);
    fn_8036A328(arg0, base + 0x210, lbl_8059F6F8);
    return 0;
}

#define ERR(s,c) do { fn_80373290(arg0,c,s); fn_8036AAF0(arg0,3,1); return 3; } while(0)
int fn_8036BB8C(void *arg0,void *arg1,const char *cmd,void *arg3)
{
 char *ps=*(char **)arg0;
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
  if(strncmp(cmd,lbl_8059F718,5)!=0) ERR("Unexpected data was received from the server.",1);
  if(fn_80372F14(cmd,"\\challenge\\",pu,0x80)==0) ERR("Unexpected data was received from the server.",1);
  if(*(int *)(pu+0x304)!=0){
   r=fn_8036B96C(arg0,(unsigned char *)pu);if(r!=0)return r;
   *(int *)(p1+0x14)=3;goto done;
  }
  r=fn_8036B548(arg0,pu);if(r!=0)return r;
  *(int *)(p1+0x14)=2;goto done;
 case 3:
  if(strncmp(cmd,lbl_8059F720,5)!=0) ERR("Unexpected data was received from the server.",1);
  if(fn_80372F14(cmd,"\\userid\\",buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  *(int *)(ps+0x19C)=atoi(buf);
  if(fn_80372F14(cmd,"\\profileid\\",buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  *(int *)(ps+0x1A0)=atoi(buf);
  r=fn_8036B548(arg0,pu);if(r!=0)return r;
  *(int *)(p1+0x14)=2;goto done;
 case 2:
  if(strncmp(cmd,lbl_8059F728,5)!=0) ERR("Unexpected data was received from the server.",1);
  if(fn_80372F14(cmd,"\\sesskey\\",buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  *(int *)(ps+0x198)=atoi(buf);
  if(fn_80372F14(cmd,"\\userid\\",buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  *(int *)(ps+0x19C)=atoi(buf);
  if(fn_80372F14(cmd,"\\profileid\\",buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  *(int *)(ps+0x1A0)=atoi(buf);
  if(fn_80372F14(cmd,"\\uniquenick\\",loc,0x15)==0)loc[0]=0;
  if(fn_80372F14(cmd,lbl_8059F730,ps+0x48C,0x19)==0)ps[0x48C]=0;
  if(*(int *)(ps+0x1A4)!=0)sprintf(name,lbl_8059F6B8,*(int *)(ps+0x1A4));
  else strcpy(name,lbl_8059F6BC);
  if((signed char)pu[0xC2]!=0)locPtr=pu+0xC2;
  else if((signed char)ps[0x12F]!=0){
   sprintf(buf2,lbl_8059F6C0,name,ps+0x12F);locPtr=buf2;
  }else{
   sprintf(buf2,lbl_8059F6C8,name,ps+0x110,ps+0x144);locPtr=buf2;
  }
  sprintf(buf,"%s%s%s%s%s%s",pu+0xA1,"                                                ",locPtr,pu,pu+0x80,pu+0xA1);
  fn_8035C0B4(buf,(int)strlen(buf),buf3);
  if(fn_80372F14(cmd,lbl_8059F738,buf,0x200)==0) ERR("Unexepected data was received from the server.",1);
  if(fn_803F6150(buf3,buf,0x20)!=0) ERR("Could not authenticate server.",0x108);
  if(*(int *)(ps+0x100)!=0){
   ptr=fn_80370684(arg0,*(int *)(ps+0x1A0));
   *(int *)ptr=*(int *)(ps+0x1A0);
   *(int *)((char *)ptr+4)=*(int *)(ps+0x19C);
  }
  *(int *)(ps+0x1F4)=3;
  pair=*(Pair *)((char *)arg1+0xC);
  if(pair.a!=0){
   pa=(char *)fn_8035DFE8(0x20);
   if(pa==0){fn_803732E0(arg0,"Out of memory.");return 1;}
   memset(pa,0,0x20);
   *(int *)(pa+4)=*(int *)(ps+0x1A0);*(int *)pa=0;
   fn_80372DD8(pa+8,loc,0x15);
   copy=pair;
   r=fn_8036ABB0(arg0,&copy,pa,arg1,0);if(r!=0)return r;
  }
  fn_8036EEE4(arg0,arg1);goto done;
 default:
  (void)&pad_8048F183; /* keeps the alignment byte; generates no code */
  goto done;
 }
 }
done:return 0;
}

__declspec(section ".data") static char pad_8048F183 = 0;
#pragma explicit_zero_data off
