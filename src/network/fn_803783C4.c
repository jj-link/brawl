#pragma force_active on
typedef struct Sock { int sock; char pad4[8]; int f0C,f10,f14,f18,f1C; char pad20[8]; int f28; char pad2C[0x14]; int f40; } Sock;
extern int CanSendOnSocket(int); extern short SOHtoNs(int); extern void closesocket(int); extern void fn_8035A4FC(int); extern void fn_8035AF74(int); extern int *fn_8035B1C4(int,int **); extern int fn_8035C658(int); extern void fn_8035D724(void); extern void fn_8035E00C(void *); extern int fn_80373924(void *); extern int fn_80373FDC(void *,int,int,int,int,int,int,int); extern void fn_80374BD4(void *); extern int fn_80376AAC(void *,int,int); extern int fn_80376CC4(void *,int,int,int); extern void fn_80378B50(void *,void *); extern void *memset(void *,int,unsigned int); extern int sendto(int,void *,int,int,void *,int);
int fn_803783C4(Sock *arg0,int arg1,int arg2,int arg3,int arg4) {
    char sp18[0x90];
    struct { int pad[2]; int addr; short port; } key;
    int *sp10; int spC; int sp8;
    int *temp_r3_2; int temp_r3; int var_r4;
    sp8=arg3; spC=arg4; fn_80378B50(&sp8,&spC);
    if(arg0->f40!=3 && CanSendOnSocket(arg0->sock)==0) return 1;
    memset(sp18-16,0,8); *(int *)(sp18-12)=arg1; sp18[-15]=2; *(short *)(sp18-14)=SOHtoNs(arg2);
    if(sendto(arg0->sock,(void *)sp8,spC,0,sp18-16,8)==-1) {
        temp_r3=fn_8035C658(arg0->sock);
        if(temp_r3==-15) { if(fn_80376AAC(arg0,arg1,arg2)!=0) goto block_26; return 0; }
        if(temp_r3==-23) { if(fn_80376CC4(arg0,arg1,arg2,1)!=0) goto block_26; return 0; }
        if(temp_r3==-42 || temp_r3==-6) return 1;
        if(temp_r3!=-35) {
            if(arg0->f18==0) { arg0->f18=1; fn_80374BD4(arg0); if(fn_80373924(arg0)!=0) { if(arg0->f1C!=0) arg0->f14=1; else { closesocket(arg0->sock); fn_8035AF74(arg0->f0C); fn_8035A4FC(arg0->f10); fn_8035E00C(arg0); fn_8035D724(); } } }
            return 0;
        }
        goto block_26;
    }
    if(arg0->f28!=0) {
        key.addr=arg1; key.port=arg2; sp10=&key.addr;
        temp_r3_2=fn_8035B1C4(arg0->f0C,&sp10);
        if(temp_r3_2!=0) var_r4=*temp_r3_2; else var_r4=0;
        if(fn_80373FDC(arg0,var_r4,arg1,arg2,0,sp8,spC,1)==0) return 0;
    }
block_26: return 1;
}