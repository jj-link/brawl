#pragma force_active on
typedef unsigned char u8;
struct Entry { u8 a; u8 b; u8 pad[2]; };
struct State { Entry entries[8]; u8 count, length; bool result; };
extern "C" void fn_80302C78(void *, State *s, short x, short y) {
 int v; Entry *e; int p, q;
 if ((int)s->length >= 3) {
  if (s->count >= 4) { s->result=1; return; }
  v = x; v >>= 4;
  if (v & 8) p=0; else { v = -((v >> 2) & 1); p = v + 2; }
  v = y; v >>= 4;
  if (v & 8) q=0; else { v = -((v >> 2) & 1); q = v + 2; }
  e=s->entries; int a=0,b=0;
  for (int i=0;i<s->length;i++,e++) {
   if(e->a<=2) {
    v=e->b; v>>=4; int h=(v&8)?0:1,m=(v&4)?0:1,l=(v&2)?0:1;
    if(q!=0){int t=1<<((m+l*2)*2);if(!((t<<1)&b))b+=t;}
    if(q!=1){int t=1<<((h+l*2+4)*2);if(!((t<<1)&b))b+=t;}
    if(q!=2){int t=1<<((h+m*2+8)*2);if(!((t<<1)&b))b+=t;}
   } else if(e->a<=6) {
    v=e->b; v>>=4; int h=(v&8)?0:1,m=(v&4)?0:1,l=(v&2)?0:1;
    if(p!=0){int t=1<<((m+l*2)*2);if(!((t<<1)&a))a+=t;}
    if(p!=1){int t=1<<((h+l*2+4)*2);if(!((t<<1)&a))a+=t;}
    if(p!=2){int t=1<<((h+m*2+8)*2);if(!((t<<1)&a))a+=t;}
   } else {
    v=e->a; int h=((v>>4)&8)?0:1,m=((v>>4)&4)?0:1,l=((v>>4)&2)?0:1;
    if((v&15)==0){int t=1<<((m+l*2)*2);if(!((t<<1)&a))a+=t;}
    else if((v&15)==1){int t=1<<((h+l*2+4)*2);if(!((t<<1)&a))a+=t;}
    else {int t=1<<((h+m*2+8)*2);if(!((t<<1)&a))a+=t;}
    v=e->b; int k=v&15; v>>=4; h=(v&8)?0:1;m=(v&4)?0:1;l=(v&2)?0:1;
    if(k==0){int t=1<<((m+l*2)*2);if(!((t<<1)&b))b+=t;}
    else if(k==1){int t=1<<((h+l*2+4)*2);if(!((t<<1)&b))b+=t;}
    else {int t=1<<((h+m*2+8)*2);if(!((t<<1)&b))b+=t;}
   }
  }
  int result=0;if((a&0x555555)>0||(b&0x555555)>0)result=1;
  s->result=result==0;
 }
}
