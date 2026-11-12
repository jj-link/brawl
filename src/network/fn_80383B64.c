#pragma force_active on
#pragma opt_propagation off
#include <stdlib.h>
#include <string.h>
typedef struct { char bytes[256]; } Block;
typedef struct { int state,id,mod; } Entry;
extern Block lbl_80490AA8;
extern char lbl_8059FAF8[2],lbl_8059FAFC[4],lbl_8059FB00[7],lbl_8059FB08[4],lbl_8059FB0C[4],lbl_8059FB10[4],lbl_8059FB14[7],lbl_8059FB1C[7],lbl_80535DE0[512];
extern int lbl_805A10C8;
extern void *lbl_805A10C4;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *,int);
extern void fn_80384D1C(int,int,long long,char *,int);
static inline char *getval(const char *input,const char *key) {
Block buf=lbl_80490AA8;
char *found,*src,*dest,*out;
lbl_805A10C8 ^= 1;
strcat(buf.bytes,key);
strcat(buf.bytes,lbl_8059FAF8);
found=strstr(input,buf.bytes);
if (!found) return 0;
src=found+strlen(buf.bytes);
out=lbl_80535DE0+(lbl_805A10C8<<8);
dest=out;
while (*src && *src!='\\') *dest++=*src++;
*dest=0;
return out;
}
static inline char *getsafe(const char *input,const char *key) {
char *value=getval(input,key);
if (value) return value;
return lbl_8059FAFC;
}
static inline int findentry(int b,int c) {
int i; Entry *e;
if (!lbl_805A10C4) return -1;
for(i=0;i<fn_8035A590(lbl_805A10C4);i++){
e=fn_8035A598(lbl_805A10C4,i);
if(e->state==1 && e->id==b && e->mod==c) return i;
}
return -1;
}
void fn_80383B64(const char *input){
int index;
int a,b,c,len;
long long d;
char *data;
char *k;
k=lbl_8059FB00;
a=atoi(getsafe(input,k));
k=lbl_8059FB08;
b=atoi(getsafe(input,k));
k=lbl_8059FB0C;
c=atoi(getsafe(input,k));
k=lbl_8059FB10;
d=atoi(getsafe(input,k));
index=findentry(b,c);
if(index!=-1){
k=lbl_8059FB14;
len=atoi(getsafe(input,k));
data=strstr(input,lbl_8059FB1C);
if(!data){len=0;data=lbl_8059FAFC;}else data+=6;
fn_80384D1C(index,a,d,data,len);
}
}
