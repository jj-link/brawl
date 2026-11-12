#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on
typedef void (*Callback)(int,int);
typedef struct Msg {int type,a,b,c,d,e; short f,g; int h,i,j,k; Callback callback;} Msg;
typedef struct State {
char pad0[0x160]; s8 head,tail; char pad162[2]; void *buffer; int size;
char pad16c[0x6cc]; int pending; char pad83c[0x80]; int result;
char pad8c0[0xc]; u8 mode; char pad8cd[0xf]; int enabled;
} State;
extern State *lbl_804F6810[];
extern u8 lbl_805A0C79;
extern u8 lbl_8040D640[],lbl_8040D670[];
extern void fn_8021C97C(int,int);
static s8 queue_count(State *q) {
int en; s8 count;
en=OSDisableInterrupts();
count=q->tail-q->head;
if(count<0) count+=q->size;
OSRestoreInterrupts(en);
return count;
}
static void enqueue(State *q,Msg m,int count) {
int en;
en=OSDisableInterrupts();
count=queue_count(q);
if((u32)(q->size-1)==(u32)count) {OSRestoreInterrupts(en); return;}
memset((char*)q->buffer+q->tail*0x30,0,0x30);
memcpy((char*)q->buffer+q->tail*0x30,&m,0x30);
q->tail=q->tail==q->size-1?0:q->tail+1;
OSRestoreInterrupts(en);
}
static void send_simple(State *q,int type,u8 value,Callback callback,int count) {
Msg m;
m.type=type; m.g=1; *(u8*)&m.a=value; m.callback=callback;
if(type==0x15) m.k=0;
enqueue(q,m,count);
}
static void enqueue_ptr(State *q,Msg *m) {
int en,count;
en=OSDisableInterrupts(); count=queue_count(q);
if((u32)(q->size-1)==(u32)count) {OSRestoreInterrupts(en); return;}
memset((char*)q->buffer+q->tail*0x30,0,0x30);
memcpy((char*)q->buffer+q->tail*0x30,m,0x30);
q->tail=q->tail==q->size-1?0:q->tail+1;
OSRestoreInterrupts(en);
}
static void send_write(State *q,u32 address,void *data,int size,Callback callback) {
Msg out,m; u8 length;
length=(u8)(size&0x1f);
m.type=0x16; m.g=0x15; m.callback=callback;
memcpy(&m.a,&address,4);
memcpy(&m.b,&length,1);
memcpy((char*)&m.b+1,data,size);
out=m;
enqueue_ptr(q,&out);
}
static void send_write_b(State *q,u32 address,void *data,int size,Callback callback) {
Msg m,out; u8 length;
length=(u8)(size&0x1f);
m.type=0x16; m.g=0x15; m.callback=callback;
memcpy(&m.a,&address,4);
memcpy(&m.b,&length,1);
memcpy((char*)&m.b+1,data,size);
out=m;
enqueue_ptr(q,&out);
}
static void send_table9(State *q,u32 address,int index,int size,Callback callback) {
Msg m,out; u8 length;
void *data=lbl_8040D640+(index-1)*9;
length=(u8)(size&0x1f);
m.type=0x16; m.g=0x15; m.callback=callback;
memcpy(&m.a,&address,4);
memcpy(&m.b,&length,1);
memcpy((char*)&m.b+1,data,size);
out=m;
enqueue_ptr(q,&out);
}
static void send_table2(State *q,u32 address,int index,int size,Callback callback) {
Msg m,out; u8 length;
void *data=lbl_8040D670+(index-1)*2;
length=(u8)(size&0x1f);
m.type=0x16; m.g=0x15; m.callback=callback;
memcpy(&m.a,&address,4);
memcpy(&m.b,&length,1);
memcpy((char*)&m.b+1,data,size);
out=m;
enqueue_ptr(q,&out);
}
static void send_byte(State *q,u32 address,u8 value,Callback callback) {
Msg out,m; u8 length;
length=(u8)(1&0x1f);
m.type=0x16; m.g=0x15; m.callback=callback;
memcpy(&m.a,&address,4);
memcpy(&m.b,&length,1);
memcpy((char*)&m.b+1,&value,1);
out=m;
enqueue_ptr(q,&out);
}
#define SIMPLE(Q,T,V,C) do { \
Msg out,m; int ien; \
m.type=(T); m.g=1; *(u8*)&m.a=(V); m.callback=(C); \
if((T)==0x15) m.k=0; \
out=m; ien=OSDisableInterrupts(); \
{int ien2=OSDisableInterrupts(); \
pending=(s8)((Q)->tail-(Q)->head); \
if(pending<0) pending=(s8)(pending+(Q)->size); \
OSRestoreInterrupts(ien2);} \
if((u32)((Q)->size-1)==(u32)pending) OSRestoreInterrupts(ien); \
else {memset((char*)(Q)->buffer+(Q)->tail*0x30,0,0x30); \
memcpy((char*)(Q)->buffer+(Q)->tail*0x30,&out,0x30); \
(Q)->tail=(Q)->tail==(Q)->size-1?0:(Q)->tail+1; \
OSRestoreInterrupts(ien);} \
}while(0)
int fn_8021C9AC(int index,unsigned int mode,Callback callback) {
State *q; int pending,enabled; u8 savedmode; int result,en,en2;
q=lbl_804F6810[index];
en=OSDisableInterrupts();
pending=q->pending; savedmode=q->mode; result=q->result; enabled=q->enabled;
OSRestoreInterrupts(en);
if(result!=-1) {
if(enabled==0) result=-2;
else if(mode==0) {
if(pending==0) result=0;
else {
en=OSDisableInterrupts();
en2=OSDisableInterrupts();
pending=(s8)(q->tail-q->head);
if(pending<0) pending=(s8)(pending+q->size);
OSRestoreInterrupts(en2);
if((u32)(pending+3)<=(u32)(q->size-1)) {
q->mode=mode;
SIMPLE(q,0x13,0,0);
SIMPLE(q,0x1a,0,fn_8021C97C);
SIMPLE(q,0x15,0,callback);
OSRestoreInterrupts(en); return 0;
}
result=-2; OSRestoreInterrupts(en);
}
} else if(mode!=savedmode) {
en=OSDisableInterrupts();
en2=OSDisableInterrupts();
pending=(s8)(q->tail-q->head);
if(pending<0) pending=(s8)(pending+q->size);
OSRestoreInterrupts(en2);
if((u32)(pending+8)<=(u32)(q->size-1)) {

q->mode=mode;
send_simple(q,0x13,4,0,pending);
send_simple(q,0x1a,4,0,pending);
send_byte(q,0x04b00030,1,0);
send_table9(q,0x04b00000,lbl_805A0C79,9,0);
send_table2(q,0x04b0001a,lbl_805A0C79,2,0);
send_byte(q,0x04b00033,mode,0);
send_byte(q,0x04b00030,8,fn_8021C97C);
send_simple(q,0x15,0,callback,pending);
OSRestoreInterrupts(en); return 0;
}
result=-2; OSRestoreInterrupts(en);
}
}
if(callback) callback(index,result);
return result;
}
