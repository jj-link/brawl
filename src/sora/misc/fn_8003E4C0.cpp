#pragma force_active on
#include <types.h>
extern float lbl_805A1728; extern float lbl_805A172C; extern float lbl_805A1730;
#define PASTE(x,y) x##y
#define BLOCK PASTE(a,sm)
#define REG_ PASTE(regist,er)
extern "C" BLOCK void fn_8003E4C0(REG_ float* m, REG_ const float* q) {
stwu r1,-32(r1)
stfd f31,16(r1)
psq_st f31,24(r1),0,0
lfs f0,0x0(r4)
lfs f1,0x4(r4)
lfs f3,0x8(r4)
fmuls f6,f0,f0
lfs f4,0xc(r4)
fmuls f5,f0,f1
lfs f2,lbl_805A1728
fmuls f11,f0,f3
lfs f10,lbl_805A172C
fmuls f12,f1,f3
fmuls f13,f4,f0
fmuls f31,f4,f1
fmuls f4,f4,f3
fmuls f7,f1,f1
fmuls f3,f3,f3
ps_merge00 f1,f10,f2
ps_merge00 f0,f2,f10
psq_st f1,0x0(r3),0,0
psq_st f2,0x8(r3),0,0
psq_st f0,0x10(r3),0,0
psq_st f2,0x18(r3),0,0
psq_st f2,0x20(r3),0,0
psq_st f1,0x28(r3),0,0
fadds f2,f7,f3
fadds f1,f6,f3
lfs f9,lbl_805A1730
fadds f0,f6,f7
fmuls f8,f9,f2
fsubs f7,f5,f4
fadds f5,f5,f4
fmuls f4,f9,f1
fadds f6,f11,f31
fsubs f3,f12,f13
fsubs f2,f11,f31
fadds f1,f12,f13
fmuls f0,f9,f0
fsubs f8,f10,f8
fmuls f7,f9,f7
fmuls f6,f9,f6
fmuls f5,f9,f5
stfs f8,0x0(r3)
fsubs f4,f10,f4
fmuls f3,f9,f3
stfs f7,0x4(r3)
fmuls f2,f9,f2
fmuls f1,f9,f1
stfs f6,0x8(r3)
fsubs f0,f10,f0
stfs f5,0x10(r3)
stfs f4,0x14(r3)
stfs f3,0x18(r3)
stfs f2,0x20(r3)
stfs f1,0x24(r3)
stfs f0,0x28(r3)
psq_l f31,24(r1),0,0
lfd f31,16(r1)
addi r1,r1,32
blr
}