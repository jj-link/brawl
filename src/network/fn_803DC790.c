#include <types.h>
#pragma force_active on
typedef struct {u16 field0;u8 pad2[0x208];u8 count,flag,sum,pad20d;u8 name[13];u8 flags,kind,extra;u16 a,b,c,d,e;u32 value;u8 pad22c[8];u32 size,address;u16 port;} State;
typedef struct {u8 pad0[0x44];u32 address;u16 port;u8 pad4a[2];u8 name[11];u8 kind,flags,extra;u16 a,b,c,sizehi,d,e,sizelo;u32 value;} Packet;
extern int fn_803DC584(State *,void *,int,unsigned int,unsigned int,unsigned int,int *);
extern int fn_803DD04C(State *,void *);
extern void fn_803E799C(void *,void *,int);
extern int fn_803E7D7C(short *,char *);
extern int fn_803E75D0(u8 *,const u8 *,int);
static inline u32 swap16(u32 v) { return ((v >> 8) & 0xff) | ((v << 8) & 0xff00); }
static inline int copy_fields(State *s, Packet *p) {
    u8 *dstA = (u8 *)s + 0x21e;
    u8 *dstB = (u8 *)s + 0x220;
    u8 *dstC = (u8 *)s + 0x222;
    u8 *dstD = (u8 *)s + 0x224;
    u8 *dstE = (u8 *)s + 0x226;
    u32 v, sizehi, sizelo;
    int hi;
    s->kind = p->kind;
    hi = s->kind & 0x10;
    s->flags = p->flags;
    s->extra = p->extra;
    *(u16 *)dstA = swap16(p->a); *(u16 *)dstB = swap16(p->b); *(u16 *)dstC = swap16(p->c);
    *(u16 *)dstD = swap16(p->d); *(u16 *)dstE = swap16(p->e);
    v = p->value;
    s->value = ((v<<24)|((v<<8)&0xff0000))|((v>>24)|((v>>8)&0xff00));
    sizehi = p->sizehi; sizelo = p->sizelo;
    s->size = (((sizehi>>8)|((sizehi<<8)&0xff00))<<16)|((sizelo<<8)&0xff00)|(sizelo>>8);
    return hi;
}
int fn_803DC790(State *s,Packet *p,int a,unsigned int b,unsigned int c,int *d){
u8 kind=p->kind;char buf[16];u8 tmp[16];int n;u16 i;u8 sum;u32 v,size;u8 *dstA,*dstB,*dstC,*dstD,*dstE;u8 kind2;u32 sizehi,sizelo;int hi;
if(fn_803DC584(s,p->name,a,kind,b,c,d)==1){if((kind&15)==15){if(fn_803DD04C(s,p->name)){s->count=0;s->field0=0;}}else{s->count=0;s->field0=0;}return -1;}
if(s->count==0&&(p->flags&0x18)){fn_803E799C(s->name,buf,p->flags);n=fn_803E7D7C((short*)s,buf);s->count=n/13+(n%13!=0);fn_803E75D0(tmp,s->name,0);sum=0;for(i=0;i<11;i++)sum=(u8)(tmp[i]+(sum>>1)+((sum&1)?0x80:0));s->sum=sum;s->flag=1;}
hi=copy_fields(s,p);
s->address=p->address;s->port=p->port;if(hi&&s->size==0)s->size=1;return 0;
}