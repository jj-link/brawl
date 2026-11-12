#pragma force_active on
#include <string.h>
#include <stdlib.h>
#include <types.h>

typedef struct State {
    char pad0[4];
    int fd;
    void *buffer;
    int size;
    char pad10[0x138];
    int time;
} State;
typedef struct Op {
    char pad0[4];
    State *state;
    char pad8[0xc];
    int status;
} Op;
typedef struct Host {
    char pad[0xc];
    int **addresses;
} Host;
typedef struct Addr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    int addr;
} Addr;
typedef struct Sub { unsigned char pad0[0x140]; int field140; int field144; } Sub;
typedef struct Node { int type; Sub *sub; unsigned char pad8[0xC]; int field14; unsigned char pad18[4]; int field1C; struct Node *next; } Node;
typedef struct Context { unsigned char pad0[0x22C]; int count; unsigned char pad230[0x210]; Node *head440; } Context;
typedef struct Req { char pad[8]; int flag; char pad2[12]; int field18; } Req;
typedef struct Data { char pad[0x28]; char a[0x1f], b[0x15], c[0x33], d[0x1f], e[0x1f]; char pad2[0x67]; int x,y; } Data;
typedef struct Cb { s32 a,b; } Cb;
typedef struct Res { s32 a0,a4,a8; void *ac; } Res;

extern void *fn_8035DFE8(int);
extern void fn_803732E0(void *, const void *);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern int socket(int, int, int);
extern int fn_8035CD04(int, int);
extern Host *fn_8035C788(char *);
extern unsigned short SOHtoNs(unsigned short);
extern int fn_8035C384(int, void *, int);
extern int fn_8035C658(int);
extern int fn_8035D728(void);
extern void fn_80372DD8(void *, const void *, unsigned long);
extern void fn_8035D6C4(char *);
extern int fn_8036ED64(Context **,int,void *,Req **,int,int,int,int);
extern int fn_80369034(Context **,int);
extern void fn_8035E00C(void *);
extern void fn_8036EEE4(Context **, Node *);

char lbl_8048F800[64] = "gpsp.gs.nintendowifi.net";

int fn_80370B9C(void *arg0, Op *arg1) {
    State *state = arg1->state;
    Host *host;
    Addr addr;
    int error;
    state->size = 0x1000;
    state->buffer = fn_8035DFE8(0x1001);
    if (!state->buffer) {
        fn_803732E0(arg0, "Out of memory.");
        return 1;
    }
    state->fd = socket(2, 1, 6);
    if (state->fd == -1) {
        fn_80373290(arg0, 5, "There was an error creating a socket.");
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    if (!fn_8035CD04(state->fd, 0)) {
        fn_80373290(arg0, 5, "There was an error making a socket non-blocking.");
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    host = fn_8035C788(lbl_8048F800);
    if (!host) {
        fn_80373290(arg0, 5, "Could not resolve search mananger host name.");
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    memset(&addr, 0, 8);
    addr.family = 2;
    addr.addr = **host->addresses;
    addr.port = SOHtoNs(0x74cd);
    if (fn_8035C384(state->fd, &addr, 8) == -1) {
        error = fn_8035C658(state->fd);
        if (error != -6 && error != -26 && error != -76) {
            fn_80373290(arg0, 5, "There was an error connecting a socket.");
            fn_8036AAF0(arg0, 3, 1);
            return 3;
        }
    }
    arg1->status = 1;
    state->time = fn_8035D728();
    return 0;
}

int fn_80370D6C(void *arg0, void **arg1, int arg2) {
    int *obj;
    int *buf;

    obj = fn_8035DFE8(0x14C);
    if (obj == 0) {
        fn_803732E0(arg0, "Out of memory.");
        return 1;
    }
    memset(obj, 0, 0x14C);
    obj[0] = arg2;
    obj[1] = -1;
    obj[2] = 0;
    obj[4] = 0;
    obj[5] = 0;
    obj[3] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[7] = 0x1000;
    buf = fn_8035DFE8(0x1001);
    obj[6] = (int)buf;
    if (buf == 0) {
        fn_803732E0(arg0, "Out of memory.");
        return 1;
    }
    obj[80] = 0;
    obj[81] = 0;
    *arg1 = obj;
    return 0;
}

static inline int process(Context **ctx, Data *data, int a, int b, int c) {
 Req *req;
 int result = fn_8036ED64(ctx,3,data,&req,a,b,c,(*ctx)->count++);
 if (result) return result;
 result = fn_80370B9C(ctx,(Op *)req);
 if (result) return result;
 if (req->flag) {
  result = fn_80369034(ctx,req->field18);
  if (result) return result;
 }
 return 0;
}

/* "No search criteria." followed by the text of two functions that were
   dead-stripped from the original file ("Invalid e-mail.", "Invalid
   password."); no surviving function references the latter two, so their
   bytes are kept here together with the alignment padding between them. */
char lbl_8048F908[60] = "No search criteria.\0\0\0\0\0Invalid e-mail.\0Invalid password.";

int fn_80370E58(Context **arg0,char *arg1,char *arg2,char *arg3,char *arg4,char *arg5,int arg6,int arg7,int arg8,int arg9,int arg10) {
 Data *data; int result; int out;
 if ((arg1 == 0 || *(signed char *)arg1 == 0) && (arg3 == 0 || *(signed char *)arg3 == 0) && (arg4 == 0 || *(signed char *)arg4 == 0) && (arg5 == 0 || *(signed char *)arg5 == 0) && arg6 == 0 && (arg2 == 0 || *(signed char *)arg2 == 0)) { fn_803732E0(arg0,lbl_8048F908); return 2; }
 result=fn_80370D6C(arg0,(void **)&data,1); if(result) return result;
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

#pragma push
#pragma global_optimizer off
#pragma opt_lifetimes off
#define GETP(p,o) (*(void **)((u8 *)(p)+(o)))
#define GETS(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define GETB(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define APP(s) fn_8036A328(arg0,(u8 *)sub+0x18,(s))
#define NUM(o) fn_8036A384(arg0,(u8 *)sub+0x18,GETS(obj,(o)))
#define PARSE() do { ret=fn_803730AC(arg0,GETP(sub,8),&sp20,spKey,spVal); if(ret) return ret; } while(0)
#define EQ(s) (strcmp(spKey,(s))==0)
#define COPY(o,n) fn_80372DD8(r17+(o),spVal,(n))
#define RCOPY(o,n) fn_80372DD8((u8 *)flg+(o),spVal,(n))
#define BAD() do { fn_80373290(arg0,1,"Error reading from the search server."); fn_8036AAF0(arg0,3,1); return 3; } while(0)
#define OOM() do { fn_803732E0(arg0,"Out of memory."); return 1; } while(0)
#define SETCB(cb,src) do { (cb).a=(src).a; (cb).b=(src).b; } while(0)
extern char lbl_80534808[0x80];
extern char lbl_8059F878[8],lbl_8059F87C[8],lbl_8059F888[8];
extern char lbl_8059F890[8],lbl_8059F898[8],lbl_8059F8A0[8];
extern char lbl_8059F8A8[8],lbl_8059F8B0[8],lbl_8059F8B8[8];
extern char lbl_8059F8C0[8],lbl_8059F8C8[8],lbl_8059F8D0[8];
extern char lbl_8059F8D4[8],lbl_8059F8D8[8],lbl_8059F8E0[8];
extern char lbl_8059F8E8[8],lbl_8059F8EC[8],lbl_8059F8F0[8];
extern char lbl_8059F8F8[8],lbl_8059F900[8],lbl_8059F904[8];
extern char lbl_8059F90C[8],lbl_8059F910[8],lbl_8059F918[8];
extern char lbl_8059F91C[8],lbl_8059F924[8],lbl_8059F92C[8];
extern char lbl_8059F930[8],lbl_8059F938[8],lbl_8059F940[8],lbl_8059F944[8];
extern void fn_8035D774(s32);
extern void *fn_8035DFF8(void *,s32);
extern void fn_8036A328(void **,void *,void *);
extern void fn_8036A384(void **,void *,s32);
extern s32 fn_8036A6DC(void **,s32,void *,s32 *,s32 *,void *);
extern s32 fn_8036A81C(void **,s32,void *,s32 *,s32,void *);
extern s32 fn_8036ABB0(void **,Cb *,void *,void *,s32);
extern s32 fn_80372E1C(void **,void *,s32);
extern s32 fn_80372F14(void *,void *,void *,s32);
extern s32 fn_80372FC0(void **,s32,s32 *);
extern s32 fn_803730AC(void **,void *,s32 *,void *,void *);
extern void fn_8037331C(void *,void *);
s32 fn_803710E8(void **arg0,void *arg1)
{
    void *p;
    char spKey[0x200],spVal[0x200],spB0[0x30];
    Res res;
    Cb cbx;
    Cb cb2,cb3,cb4,cb5,cb6,cb7,cb8;
    Cb pr8,pr7,pr6,pr5,pr4,pr3,pr2;
    s32 sp24,sp20,sp1C,sp18;
    s32 flag;
    void *sub;
    u8 *r17;
    s32 state,ret,flg,sav,cnt,off,v;
    void *p8;
    void *obj;

    obj=*arg0;
    sub=GETP(arg1,4);
    v=GETS(arg1,8);
    flag=((u32)-(s32)v|(u32)v)>>31;
    if(v==0) {
        if((u32)(fn_8035D728()-GETS(sub,0x148))>0xEA60) {
            GETS(sub,0x144)=1;
            fn_80373290(arg0,0xD02,"The search timed out");
            fn_8036AAF0(arg0,3,0);
            return 3;
        }
    }
    do {
        ret=fn_8036A81C(arg0,GETS(sub,4),(u8 *)sub+0x18,&sp18,1,lbl_8059F878);
        if(ret) return ret;
        state=GETS(arg1,0x14);
        if(state==1) {
            ret=fn_80372FC0(arg0,GETS(sub,4),&sp24);
            if(ret) return ret;
            if(sp24==4) {
                fn_80373290(arg0,0xD01,"Could not connect to the search manager.");
                fn_8036AAF0(arg0,4,0);
                return 4;
            }
            if(sp24!=3) goto next;
            state=GETS(sub,0);
            if(state==1) {
                APP("\\search\\");
                APP("\\sesskey\\"); NUM(0x198);
                APP("\\profileid\\"); NUM(0x1a0);
                APP("\\namespaceid\\"); NUM(0x488);
                APP("\\partnerid\\"); NUM(0x1a4);
                if(GETB(sub,0x28)) { APP(lbl_8059F87C); APP((u8 *)sub+0x28); }
                if(GETB(sub,0x47)) { APP("\\uniquenick\\"); APP((u8 *)sub+0x47); }
                if(GETB(sub,0x5C)) { APP(lbl_8059F888); APP((u8 *)sub+0x5C); }
                if(GETB(sub,0x8F)) { APP("\\firstname\\"); APP((u8 *)sub+0x8F); }
                if(GETB(sub,0xAE)) { APP("\\lastname\\"); APP((u8 *)sub+0xAE); }
                if(GETS(sub,0x134)) {
                    APP("\\icquin\\");
                    fn_8036A384(arg0,(u8 *)sub+0x18,GETS(sub,0x134));
                }
                if(GETS(sub,0x138)>0) {
                    APP(lbl_8059F890);
                    fn_8036A384(arg0,(u8 *)sub+0x18,GETS(sub,0x138));
                }
            } else if(state==2) {
                APP(lbl_8059F898);
                APP(lbl_8059F888); APP((u8 *)sub+0x5C);
                APP("\\partnerid\\"); NUM(0x1a4);
            } else if(state==3) {
                APP(lbl_8059F8A0);
                APP(lbl_8059F888); APP((u8 *)sub+0x5C);
                fn_8037331C((u8 *)sub+0xCD,spB0);
                APP("\\passenc\\"); APP(spB0);
                APP("\\namespaceid\\"); NUM(0x488);
                APP("\\partnerid\\"); NUM(0x1a4);
            } else if(state==4) {
                APP("\\pmatch\\");
                APP("\\sesskey\\"); NUM(0x198);
                APP("\\profileid\\"); NUM(0x1a0);
                APP("\\productid\\");
                fn_8036A384(arg0,(u8 *)sub+0x18,GETS(sub,0x13C));
            } else if(state==5) {
                APP(lbl_8059F8A8);
                APP(lbl_8059F87C); APP((u8 *)sub+0x28);
                APP(lbl_8059F888); APP((u8 *)sub+0x5C);
                APP("\\partnerid\\"); NUM(0x1a4);
                fn_8037331C((u8 *)sub+0xCD,spB0);
                APP("\\passenc\\"); APP(spB0);
            } else if(state==6) {
                APP("\\newuser\\");
                APP(lbl_8059F87C); APP((u8 *)sub+0x28);
                APP(lbl_8059F888); APP((u8 *)sub+0x5C);
                fn_8037331C((u8 *)sub+0xCD,spB0);
                APP("\\passenc\\"); APP(spB0);
                APP("\\productID\\"); NUM(0x484);
                APP("\\namespaceid\\"); NUM(0x488);
                APP("\\uniquenick\\"); APP((u8 *)sub+0x47);
                if(GETB(sub,0xEC)) { APP(lbl_8059F8B0); APP((u8 *)sub+0xEC); }
                APP("\\partnerid\\"); NUM(0x1a4);
            } else if(state==7) {
                APP("\\others\\");
                APP("\\sesskey\\"); NUM(0x198);
                APP("\\profileid\\"); NUM(0x1a0);
                APP("\\namespaceid\\"); NUM(0x488);
            } else if(state==8) {
                APP("\\uniquesearch\\");
                APP("\\preferrednick\\"); APP((u8 *)sub+0x47);
                APP("\\namespaceid\\"); NUM(0x488);
            }
            APP("\\gamename\\"); APP(lbl_80534808); APP(lbl_8059F8B8);
            GETS(arg1,0x14)=4;
            goto next;
        } else if(state==4) {
            ret=fn_8036A6DC(arg0,GETS(sub,4),(u8 *)sub+8,&sp1C,&sp18,lbl_8059F878);
            if(ret) {
                if(ret==3) {
                    fn_80373290(arg0,0xD01,"There was an error reading from the server.");
                    fn_8036AAF0(arg0,3,0);
                    return 3;
                } else {
                    return ret;
                }
            }
            if(GETS(arg1,8)) {
                if((u32)(fn_8035D728()-GETS(sub,0x148))>0xEA60) {
                    GETS(sub,0x144)=1;
                    fn_80373290(arg0,0xD02,"The search timed out");
                    fn_8036AAF0(arg0,3,0);
                    return 3;
                }
            }
            if(!strstr((char *)GETP(sub,8),lbl_8059F8B8)) goto next;
            sp20=0;
            GETS(arg1,0x14)=5;
            if(fn_80372E1C(arg0,GETP(sub,8),1)) {
                GETS(sub,0x144)=1;
                return 4;
            }
            state=GETS(sub,0);
            if(state==1) {
                res.a0=0; res.a4=0; res.ac=0; res.a8=0x601;
                flag=0;
                do {
                    PARSE();
                    if(EQ(lbl_8059F8C0)) {
                        PARSE();
                        if(EQ(lbl_8059F8C8)) {
                            if(strcmp(spVal,lbl_8059F8D0)) res.a8=0x600;
                        }
                        flag=1;
                    } else if(EQ(lbl_8059F8D4)) {
                        res.a4++;
                        res.ac=fn_8035DFF8(res.ac,res.a4*0xAC);
                        if(!res.ac) OOM();
                        r17=(u8 *)res.ac+(res.a4-1)*0xAC;
                        memset(r17,0,0xAC);
                        *(s32 *)r17=atoi(spVal);
                        flg=0;
                        do {
                            sav=sp20;
                            PARSE();
                            if(EQ(lbl_8059F8D8)) { COPY(4,0x1F); }
                            else if(EQ("uniquenick")) { COPY(0x23,0x15); }
                            else if(EQ("firstname")) { COPY(0x38,0x1F); }
                            else if(EQ("lastname")) { COPY(0x57,0x1F); }
                            else if(EQ(lbl_8059F8E0)) { COPY(0x76,0x33); }
                            else if(EQ(lbl_8059F8D4)||EQ(lbl_8059F8C0)) {
                                flg=1; sp20=sav;
                            }
                        } while(!flg);
                    } else BAD();
                } while(!flag);
                cbx.a=GETS(arg1,0xC);
                cbx.b=GETS(arg1,0x10);
                sav=res.a8;
                if(cbx.a) ((s32 (*)(void **,Res *,s32))cbx.a)(arg0,&res,cbx.b);
                if(sav==0x600&&res.a8==0x600) {
                    ret=fn_80370E58((Context **)arg0,(char *)sub+0x28,(char *)sub+0x47,
                        (char *)sub+0x5C,(char *)sub+0x8F,(char *)sub+0xAE,
                        GETS(sub,0x134),res.a4+GETS(sub,0x138),
                        GETS(arg1,8),GETS(arg1,0xC),GETS(arg1,0x10));
                    if(ret) return ret;
                }
                fn_8035E00C(res.ac);
                res.ac=0;
                goto block_a38;
            } else if(state==2) {
                void *p2;
                pr2.a=GETS(arg1,0xC); pr2.b=GETS(arg1,0x10);
                if(!pr2.a) goto block_a38;
                PARSE();
                if(!EQ(lbl_8059F8E8)) BAD();
                p2=fn_8035DFE8(0x3C);
                if(!p2) OOM();
                *(s32 *)p2=0;
                fn_80372DD8((u8 *)p2+4,(u8 *)sub+0x5C,0x33);
                if(spVal[0]=='0') GETS(p2,0x38)=0;
                else GETS(p2,0x38)=1;
                SETCB(cb2,pr2);
                ret=fn_8036ABB0(arg0,&cb2,p2,arg1,0);
                if(ret) return ret;
                goto block_a38;
            } else if(state==3) {
                void *tmp;
                pr3.a=GETS(arg1,0xC); pr3.b=GETS(arg1,0x10);
                if(!pr3.a) goto block_a38;
                p=fn_8035DFE8(0x44);
                if(!p) OOM();
                *(s32 *)p=0;
                strcpy((char *)p+4,(char *)sub+0x5C);
                GETS(p,0x38)=0;
                GETS(p,0x3C)=0;
                GETS(p,0x40)=0;
                PARSE();
                if(!EQ(lbl_8059F8EC)) BAD();
                flag=0;
                do {
                    PARSE();
                    if(EQ(lbl_8059F8D8)) {
                        tmp=fn_8035DFF8(GETP(p,0x3C),(GETS(p,0x38)+1)<<2);
                        if(!tmp) OOM();
                        GETP(p,0x3C)=tmp;
                        tmp=fn_8035DFE8(0x1F);
                        if(!tmp) OOM();
                        ((void **)GETP(p,0x3C))[GETS(p,0x38)]=tmp;
                        fn_80372DD8(((void **)GETP(p,0x3C))[GETS(p,0x38)],spVal,0x1F);
                        GETS(p,0x38)++;
                    } else if(EQ("uniquenick")) {
                        if(GETS(p,0x38)>0) {
                            tmp=fn_8035DFF8(GETP(p,0x40),GETS(p,0x38)<<2);
                            if(!tmp) OOM();
                            GETP(p,0x40)=tmp;
                            tmp=fn_8035DFE8(0x15);
                            if(!tmp) OOM();
                            (((void **)GETP(p,0x40))-1)[GETS(p,0x38)]=tmp;
                            fn_80372DD8((((void **)GETP(p,0x40))-1)[GETS(p,0x38)],spVal,0x15);
                        }
                    } else if(EQ(lbl_8059F8F0)) { flag=1; }
                    else BAD();
                } while(!flag);
                SETCB(cb3,pr3);
                ret=fn_8036ABB0(arg0,&cb3,p,arg1,3);
                if(ret) return ret;
                goto block_a38;
            } else if(state==4) {
                pr4.a=GETS(arg1,0xC); pr4.b=GETS(arg1,0x10);
                if(!pr4.a) goto block_a38;
                p=fn_8035DFE8(0x10);
                if(!p) OOM();
                GETS(p,4)=GETS(sub,0x13C);
                GETS(p,0)=0; GETS(p,8)=0; GETS(p,0xC)=0;
                flag=0;
                do {
                    PARSE();
                    if(EQ(lbl_8059F8F8)) { flag=1; }
                    else if(EQ(lbl_8059F900)) {
                        GETS(p,8)++;
                        r17=fn_8035DFF8(GETP(p,0xC),GETS(p,8)*0x128);
                        GETS(p,0xC)=(s32)r17;
                        if(!r17) OOM();
                        r17+=(GETS(p,8)-1)*0x128;
                        memset(r17,0,0x128);
                        *(s32 *)(r17+0x24)=1;
                        *(s32 *)r17=atoi(spVal);
                        flg=0;
                        do {
                            sav=sp20;
                            PARSE();
                            if(EQ(lbl_8059F904)) { COPY(0x28,0x100); }
                            else if(EQ(lbl_8059F8D8)) { COPY(4,0x1F); }
                            if(EQ("statuscode\0")) {
                                *(s32 *)(r17+0x24)=atoi(spVal);
                            } else if(EQ(lbl_8059F900)||EQ(lbl_8059F8F8)) {
                                flg=1; sp20=sav;
                            }
                        } while(!flg);
                    } else BAD();
                } while(!flag);
                SETCB(cb4,pr4);
                ret=fn_8036ABB0(arg0,&cb4,p,arg1,4);
                if(ret) return ret;
                goto block_a38;
            } else if(state==5) {
                pr5.a=GETS(arg1,0xC); pr5.b=GETS(arg1,0x10);
                if(!pr5.a) goto block_a38;
                PARSE();
                if(!EQ(lbl_8059F90C)) BAD();
                flg=atoi(spVal);
                if(flg) { GETS(obj,0x434)=flg; sav=0; }
                else {
                    if(!fn_80372F14(GETP(sub,8),lbl_8059F910,spVal,0x200)) BAD();
                    sav=atoi(spVal);
                }
                p8=fn_8035DFE8(8);
                if(!p8) OOM();
                GETS(p8,0)=flg; GETS(p8,4)=sav;
                SETCB(cb5,pr5);
                ret=fn_8036ABB0(arg0,&cb5,p8,arg1,0);
                if(ret) return ret;
                goto block_a38;
            } else if(state==6) {
                void *p6;
                pr6.a=GETS(arg1,0xC); pr6.b=GETS(arg1,0x10);
                if(!pr6.a) goto block_a38;
                PARSE();
                if(!EQ(lbl_8059F918)) BAD();
                flg=atoi(spVal);
                if(flg) GETS(obj,0x434)=flg;
                if(!fn_80372F14(GETP(sub,8),lbl_8059F910,spVal,0x200)) {
                    if(!flg) BAD();
                    sav=0;
                } else { sav=atoi(spVal); }
                p6=fn_8035DFE8(8);
                if(!p6) OOM();
                GETS(p6,0)=flg; GETS(p6,4)=sav;
                SETCB(cb6,pr6);
                ret=fn_8036ABB0(arg0,&cb6,p6,arg1,0);
                if(ret) return ret;
                goto block_a38;
            } else if(state==7) {
                u8 *tmp7;
                pr7.a=GETS(arg1,0xC); pr7.b=GETS(arg1,0x10);
                if(!pr7.a) goto block_a38;
                off=(s32)fn_8035DFE8(0xC);
                if(!off) OOM();
                GETS(off,0)=0; GETS(off,4)=0; GETS(off,8)=0;
                PARSE();
                if(!EQ(lbl_8059F91C)) BAD();
                flag=0;
                do {
                    PARSE();
                    if(EQ(lbl_8059F924)) { flag=1; }
                    else if(EQ(lbl_8059F92C)) {
                        tmp7=fn_8035DFF8(GETP(off,8),(GETS(off,4)+1)*0xAC);
                        if(!tmp7) OOM();
                        GETS(off,8)=(s32)tmp7;
                        flg=(s32)(tmp7+GETS(off,4)*0xAC);
                        memset((void *)flg,0,0xAC);
                        GETS(off,4)++;
                        *(s32 *)flg=atoi(spVal);
                        r17=0;
                        do {
                            sav=sp20;
                            PARSE();
                            if(EQ(lbl_8059F8D8)) { RCOPY(4,0x1F); }
                            else if(EQ("uniquenick")) { RCOPY(0x23,0x15); }
                            else if(EQ(lbl_8059F930)) { RCOPY(0x38,0x1F); }
                            else if(EQ(lbl_8059F938)) { RCOPY(0x57,0x1F); }
                            else if(EQ(lbl_8059F8E0)) { RCOPY(0x76,0x33); }
                            else if(EQ(lbl_8059F92C)||EQ(lbl_8059F924)) {
                                r17=(u8 *)1; sp20=sav;
                            }
                        } while(!r17);
                    } else BAD();
                } while(!flag);
                SETCB(cb7,pr7);
                ret=fn_8036ABB0(arg0,&cb7,(void *)off,arg1,8);
                if(ret) return ret;
                goto block_a38;
            } else if(state==8) {
                pr8.a=GETS(arg1,0xC); pr8.b=GETS(arg1,0x10);
                if(!pr8.a) goto block_a38;
                r17=0;
                flg=(s32)fn_8035DFE8(0xC);
                if(!flg) OOM();
                GETS(flg,0)=0; GETS(flg,4)=0; GETS(flg,8)=0;
                PARSE();
                if(!EQ(lbl_8059F940)) BAD();
                GETS(flg,4)=atoi(spVal);
                GETP(flg,8)=fn_8035DFE8(GETS(flg,4)<<2);
                if(!GETP(flg,8)) OOM();
                flag=0;
                off=0;
                do {
                    PARSE();
                    if(EQ(lbl_8059F8D8)) {
                        *(void **)((u8 *)GETP(flg,8)+off)=fn_8035DFE8(0x15);
                        cnt=*(s32 *)((u8 *)GETP(flg,8)+off);
                        if(!cnt) OOM();
                        fn_80372DD8((void *)cnt,spVal,0x15);
                        off+=4;
                        r17++;
                    } else if(EQ(lbl_8059F944)) {
                        GETS(flg,4)=(s32)r17; flag=1;
                    } else BAD();
                } while(!flag);
                SETCB(cb8,pr8);
                ret=fn_8036ABB0(arg0,&cb8,(void *)flg,arg1,9);
                if(ret) return ret;
                goto block_a38;
            }
            goto block_a38;
        } else {
            goto next;
        }
block_a38:
        GETS(sub,0x144)=1;
        flag=0;
next:
        if(flag) fn_8035D774(10);
    } while(flag);
    return 0;
}
#pragma pop

int fn_80372A74(Context **arg0) {
 Context *ctx; Node **arr; Node *cur; Sub *sub; int n, i, r;
 ctx=*arg0; n=0;
 if (ctx->count > 0) {
  arr=fn_8035DFE8(ctx->count*4);
  if (arr==0) { fn_803732E0(arg0,"Out of memory."); return 1; }
  for(cur=ctx->head440;cur!=0;cur=cur->next) {
   if(cur->type==3 && cur->field14!=5 && cur->sub->field140==0) {
    arr[n++]=cur; cur->sub->field140=1;
   }
  }
  for(i=0;i<n;i++) {
   r=fn_803710E8((void **)arg0,arr[i]);
   if(r!=0) arr[i]->field1C=r;
  }
  for(i=0;i<n;i++) {
   sub=arr[i]->sub;
   sub->field140=0;
   if(sub->field144!=0) fn_8036EEE4(arg0,arr[i]);
  }
  fn_8035E00C(arr);
 }
 return 0;
}
