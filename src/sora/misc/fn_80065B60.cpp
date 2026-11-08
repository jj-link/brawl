#pragma force_active on
extern "C" void fn_80065C98(void*);
struct ecTrace {
 char p[8]; short a; char q[4]; unsigned char flags; char r[0x21];
 unsigned long x30,x34,x38,x3c; int x40; unsigned int x44; short x48,x4a;
 char s[0x24]; signed char x70; char t[15];
 ecTrace(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long);
};
ecTrace::ecTrace(unsigned long a,unsigned long b,unsigned long c,unsigned long d,unsigned long e,unsigned long f) {
 unsigned long m = -1;
 x30=m; x34=m; x38=m; x3c=m; x40=0;
 this->a=(short)(a+1); x70=(signed char)e;
 fn_80065C98(this);
 unsigned char v=flags|1; flags=v;
 if(f!=0) { v|=2; flags=v; }
 x44=b; x48=(short)c; x4a=(short)d;
}