#pragma force_active on
struct Pad { unsigned int a, held, b, pressed; char rest[0x28]; signed char error; char pad[3]; int type; };
struct Menu { int a; char* name; int capacity; char p0[0x34]; int state; char p1[0x1c]; void* object; void* message; char p2[8]; unsigned long messageId; char p3[8]; unsigned char flag; char p4[7]; int cursor; unsigned char special; char p5[3]; int timer; };
extern "C" {
int fn_8006CEEC(const char*,int);
void fn_8006BAB0(char*,const char*,int,int);
int strcmp(const char*,const char*);
char* strcpy(char*,const char*);
extern const char* lbl_16_data_4;
extern unsigned int lbl_16_rodata_48[];
extern const double lbl_16_rodata_38;
extern int lbl_16_rodata_4,lbl_16_rodata_8;
extern const char* lbl_16_data_2088[];
extern const char* lbl_16_data_2FF8[];
extern void* g_gfPadSystem;
extern void* g_sndSystem;
extern void* g_GameGlobal;
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*,int,Pad*);
void playSE__9sndSystemF5SndIDiiii(void*,int,int,int,int,int);
int getLanguage__10GameGlobalFv(void*);
int randi__Fl(long);
void printf__5MuMsgFUlPCce(void*,unsigned long,const char*,...);
void setFrameNode__8MuObjectFf(void*,float);
}
inline bool valid(Menu* m) {
if(m->special && fn_8006CEEC(m->name,0x7fff)<=0) return true;
for(int i=0;i<fn_8006CEEC(m->name,0x7fff);++i) {
char c[8]; c[0]=0;
fn_8006BAB0(c,m->name,i,1);
if(strcmp(c,lbl_16_data_4)!=0) return true;
}
return false;
}
inline bool randomPressed(Pad* p,int all) {
if(all) {
Pad status;
for(int i=0;i<8;++i) {
getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem,i,&status);
if(status.error==0 && (status.pressed & lbl_16_rodata_48[status.type])) return true;
}
return false;
}
return (p->pressed & lbl_16_rodata_48[p->type])!=0;
}
extern "C" int fn_16_1670(Menu* m,Pad* p,int all) {
int result=0;
if(p->pressed & 0x200) result=fn_8006CEEC(m->name,0x7fff)<=0?2:4;
if(p->pressed & 0x100) {
switch(m->state) {
case 0: if(fn_8006CEEC(m->name,0x7fff)<=0) result=2; else result=4; break;
case 12: result=5; break;
case 13: if(valid(m)) result=1; break;
default: result=3; break;
}
}
if((p->pressed & 0x1000) && m->state==13 && result!=1) {
if(valid(m)) result=1;
}
if(p->held & 0x200) {
if(p->pressed & 0x200) m->timer=35;
if(--m->timer<0) result=6;
}
if(!m->special && randomPressed(p,all)) {
playSE__9sndSystemF5SndIDiiii(g_sndSystem,0x204c,-1,0,0,-1);
const char* name;
if(getLanguage__10GameGlobalFv(g_GameGlobal)==0) name=lbl_16_data_2088[randi__Fl(lbl_16_rodata_4)];
else name=lbl_16_data_2FF8[randi__Fl(lbl_16_rodata_8)];
strcpy(m->name,name);
if(m->message) printf__5MuMsgFUlPCce(m->message,m->messageId,m->name);
m->flag=1;
int pos=fn_8006CEEC(m->name,0x7fff);
if(m->flag==0) { if(--pos<0) pos=0; }
if(pos>m->capacity-1) pos=m->capacity-1;
if(m->object) setFrameNode__8MuObjectFf(m->object,(float)(pos+1));
m->cursor=pos;
}
return result;
}
