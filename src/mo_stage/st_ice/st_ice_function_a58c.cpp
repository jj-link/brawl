#pragma force_active on
struct W { int a : 4; signed int b : 2; int c : 26; };
extern "C" int fn_62_A58C(int *p) { return ((struct W*)&p[2])->b; }
